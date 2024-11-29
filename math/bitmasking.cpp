/*
4. Bitmasking
Description:
Bitmasking is a technique that uses bitwise operations to manipulate or represent sets. It's commonly used to solve subset problems and problems where you need to track combinations efficiently.

Use Case:

Solving problems involving subsets, power sets, or subsets of sets.
*/


#include <iostream>
using namespace std;

void printSubsets(int n) {
    for (int mask = 0; mask < (1 << n); ++mask) {
        cout << "{ ";
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                cout << i << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    printSubsets(3);  // Output: All subsets of a set {0, 1, 2}
}
