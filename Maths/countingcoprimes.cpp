#include <bits/stdc++.h>
using namespace std;
#define MAX_VALUE 1000010

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    vector<vector<int>> divisorsOf(MAX_VALUE);

    for (int i = 2; i < MAX_VALUE; ++i) {
        if (divisorsOf[i].empty()) {
            for (int j = i; j < MAX_VALUE; j += i) {
                divisorsOf[j].push_back(i);
            }
        }
    }

    vector<int> valuesDivisibleBy(MAX_VALUE, 0);
    vector<int> primeDivisorsOf(MAX_VALUE, 0);

    for (int i = 0; i < n; ++i) {
        int value = values[i];
        int size = divisorsOf[value].size();
        for (int mask = 1; mask < (1 << size); ++mask) {
            int combination = 1;
            int primeDivisors = 0;
            for (int pos = 0; pos < size; ++pos) {
                if (mask & (1 << pos)) {
                    combination *= divisorsOf[value][pos];
                    primeDivisors++;
                }
            }
            valuesDivisibleBy[combination]++;
            primeDivisorsOf[combination] = primeDivisors;
        }
    }

    ll totalNumberOfPairs = (ll)n * (n - 1) / 2;
    ll validPairs = 0;

    for (int i = 0; i < MAX_VALUE; ++i) {
        if (valuesDivisibleBy[i] > 1) {
            ll count = (ll)valuesDivisibleBy[i] * (valuesDivisibleBy[i] - 1) / 2;
            if (primeDivisorsOf[i] % 2 == 1) {
                validPairs += count;
            } else {
                validPairs -= count;
            }
        }
    }

    cout << totalNumberOfPairs - validPairs << "\n";
    return 0;
}
