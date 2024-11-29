/*
7. Suffix Tree
Description:
A Suffix Tree is a compressed trie built from the suffixes of a string. It allows fast string matching and pattern matching.

Use Case:

Substring search, longest common substring, string matching algorithms like Ukkonen’s algorithm.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SuffixTree {
    string text;
    vector<int> suffixArray;

    void buildSuffixArray() {
        int n = text.size();
        suffixArray.resize(n);
        for (int i = 0; i < n; ++i)
            suffixArray[i] = i;

        sort(suffixArray.begin(), suffixArray.end(), [this, n](int i, int j) {
            return text.substr(i, n - i) < text.substr(j, n - j);
        });
    }

public:
    SuffixTree(const string& s) : text(s) {
        buildSuffixArray();
    }

    void printSuffixArray() {
        for (int i : suffixArray) cout << i << " ";
        cout << endl;
    }

    // Find the pattern in the text
    bool findPattern(const string& pattern) {
        int l = 0, r = text.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            string suffix = text.substr(suffixArray[mid]);
            if (suffix.compare(0, pattern.size(), pattern) < 0)
                l = mid + 1;
            else if (suffix.compare(0, pattern.size(), pattern) > 0)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
};

int main() {
    string text = "banana";
    SuffixTree suffixTree(text);
    suffixTree.printSuffixArray();  // Output: 5 3 1 0 4 2
    cout << "Pattern 'ana' found: " << suffixTree.findPattern("ana") << endl;  // Output: 1
}
