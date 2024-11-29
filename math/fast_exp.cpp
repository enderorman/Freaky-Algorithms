#include <iostream>
using namespace std;

long long fastExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    cout << "Fast Exponentiation (2^10 mod 1000): " << fastExp(2, 10, 1000) << endl;  // Output: 24
}
