#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> primes(k);
    for (int i = 0; i < k; i++) cin >> primes[i];

    vector<ll> count(k + 1, 0);

    for (int mask = 1; mask < (1 << k); mask++) {
        ll temp = n;
        int noOfDivisors = __builtin_popcount(mask);
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                if (temp < primes[i]) {
                    temp = 0;
                    break;
                }
                temp /= primes[i];
            }
        }
        count[noOfDivisors] += temp;
    }

    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        if (i % 2 == 0) ans -= count[i];
        else ans += count[i];
    }

    cout << ans << "\n";
    return 0;
}