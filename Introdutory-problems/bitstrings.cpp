#include <iostream>
using namespace std;

#define ln '\n'
typedef long long ll;
const int mod = 1e9 + 7;

int modularBinaryExponentiation(int a, int b) {
    if(b == 0) return 1;
    int res = modularBinaryExponentiation(a, b / 2) % mod;
    if(b % 2 == 0) return (1LL * res * res) % mod;
    else return (1LL * a * ((1LL * res * res) % mod)) % mod;
}

int main() {
    int n;
    cin >> n;
    cout << modularBinaryExponentiation(2, n) << ln;
    return 0;
}