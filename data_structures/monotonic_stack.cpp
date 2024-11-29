/*

4. Monotonic Stack
Description:
A Monotonic Stack is used to maintain a stack where the elements are either monotonically increasing or monotonically decreasing.

Use Case:

Finding the next greater element, next smaller element, and previous greater element in an array, or solving problems like stock span, trapping rainwater.

*/


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i];  // Found the next greater element
            st.pop();
        }
        st.push(i);  // Push the current index
    }
    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(nums);
    cout << "Next Greater Elements: ";
    for (int num : result) cout << num << " ";  // Output: 5 10 10 -1 -1
    cout << endl;
}
