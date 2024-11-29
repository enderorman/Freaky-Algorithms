#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function to compute the hash of a string
long long computeHash(const string& s, int len, int base, int mod) {
    long long hashValue = 0;
    for (int i = 0; i < len; i++) {
        hashValue = (hashValue * base + s[i]) % mod;
    }
    return hashValue;
}

// Rabin-Karp Algorithm
void rabinKarpSearch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int base = 256; // The number of possible characters (ASCII)
    int mod = 1e9 + 7; // A large prime number

    long long patternHash = computeHash(pattern, m, base, mod);
    long long textHash = computeHash(text, m, base, mod);
    long long basePower = 1;

    // Precompute base^m % mod
    for (int i = 0; i < m - 1; i++) {
        basePower = (basePower * base) % mod;
    }

    // Searching for the pattern in the text
    for (int i = 0; i <= n - m; i++) {
        if (patternHash == textHash) {
            if (text.substr(i, m) == pattern) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < n - m) {
            // Update the hash value for the next substring
            textHash = (textHash - text[i] * basePower) % mod;
            textHash = (textHash + mod) % mod;  // Ensure it's non-negative
            textHash = (textHash * base + text[i + m]) % mod;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    rabinKarpSearch(text, pattern);
    return 0;
}
