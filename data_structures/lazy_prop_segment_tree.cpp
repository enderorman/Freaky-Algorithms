#include <iostream>
#include <vector>
using namespace std;

class LazySegmentTree {
    vector<int> tree, lazy;
    int n;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];  // Apply the update
            if (start != end) {  // If not a leaf node, propagate lazily
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;  // Clear the lazy value
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);
        if (start > r || end < l) return;  // Out of range
        if (start >= l && end <= r) {  // Completely in range
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > r || end < l) return 0;  // Out of range
        if (start >= l && end <= r) return tree[node];  // Completely in range
        int mid = (start + end) / 2;
        return queryRange(2 * node, start, mid, l, r) + queryRange(2 * node + 1, mid + 1, end, l, r);
    }

public:
    LazySegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void update(int l, int r, int val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    int query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

int main() {
    LazySegmentTree segTree(10);
    segTree.update(0, 5, 2);  // Add 2 to the range [0, 5]
    segTree.update(3, 7, 3);  // Add 3 to the range [3, 7]
    cout << "Sum of range [0, 5]: " << segTree.query(0, 5) << endl;  // Output: 18
    cout << "Sum of range [6, 9]: " << segTree.query(6, 9) << endl;  // Output: 3
}
