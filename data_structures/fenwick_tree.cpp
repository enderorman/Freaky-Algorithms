/*

2. Fenwick Tree (Binary Indexed Tree)
Description:
A Fenwick Tree is used for point updates and prefix/range queries in 
O
(
log
⁡
n
)
O(logn).

Use Case:

Efficient for tasks involving prefix sums or frequency counts, such as inversions in an array or dynamic prefix calculations.
*/

#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        for (; index <= n; index += index & -index)
            tree[index] += value;
    }

    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index)
            sum += tree[index];
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    FenwickTree fenwick(10);
    fenwick.update(1, 5);
    fenwick.update(3, 3);
    fenwick.update(7, 2);
    cout << "Sum of range [1, 3]: " << fenwick.rangeQuery(1, 3) << endl;  // Output: 8
    cout << "Sum of range [1, 7]: " << fenwick.rangeQuery(1, 7) << endl;  // Output: 10
}
