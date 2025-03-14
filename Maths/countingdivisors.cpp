#include <bits/stdc++.h>
using namespace std;
#define ln '\n'

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i == n / i) count += 1;
                else count += 2;
            }
        }
        cout << count << ln;
    }
    return 0;
}