#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lisOptimized(const vector<int>& arr) {
    vector<int> seq;  // This will store the smallest possible element for each length subsequence
    
    for (int num : arr) {
        // Use binary search to find the position of num in seq
        auto it = lower_bound(seq.begin(), seq.end(), num);
        
        // If num is larger than any element in seq, add it to the end
        if (it == seq.end()) {
            seq.push_back(num);
        } else {
            // Otherwise, replace the first element larger than or equal to num
            *it = num;
        }
    }
    
    return seq.size();  // The length of the longest increasing subsequence
}

int main() {
    int n;
    cin >> n;  // Input the number of elements in the sequence
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input the sequence
    }

    cout << "Length of Longest Increasing Subsequence: " << lisOptimized(arr) << endl;

    return 0;
}
