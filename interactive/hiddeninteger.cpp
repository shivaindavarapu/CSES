#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ask(int y) {
    cout << "? " << y << endl;
    cout.flush();
    string response;
    cin >> response;
    return response == "YES";
}

void solve() {
    int low = 1, high = 1e9;
    while (low < high) {
        int mid = (low + high) / 2;
        if (ask(mid)) {
            low = mid + 1; 
        } else {
            high = mid;
        }
    }
    cout << "! " << low << endl;
    cout.flush();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}