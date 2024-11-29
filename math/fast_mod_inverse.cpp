#include <iostream>
using namespace std;

long long modInverse(long long a, long long mod) {
    return fastExp(a, mod - 2, mod);  // Using Fermat's Little Theorem
}

int main() {
    cout << "Modular Inverse (3 mod 11): " << modInverse(3, 11) << endl;  // Output: 4
}
