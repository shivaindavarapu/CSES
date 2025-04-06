#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define int long long
const int mod = 1e9 + 7;

int modularBinaryExponentiation(int a, int b, int m) {
    if (b == 0) return 1;
    int res = modularBinaryExponentiation(a, b / 2, m);
    if (b % 2 != 0) return (((res * res) % m) * a) % m;
    else return (res * res) % m;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int exp = modularBinaryExponentiation(b, c, mod - 1);
        cout << modularBinaryExponentiation(a, exp, mod) << ln;
    }
    return 0;
}