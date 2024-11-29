#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute the LPS array for the pattern
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int j = 0; // length of previous longest prefix suffix

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lps[j - 1]; // Go to the previous longest prefix suffix
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        lps[i] = j;
    }

    return lps;
}

// KMP Search function
void KMPSearch(const string& text, const string& pattern) {
    vector<int> lps = computeLPSArray(pattern);
    int n = text.length();
    int m = pattern.length();
    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    KMPSearch(text, pattern);
    return 0;
}
