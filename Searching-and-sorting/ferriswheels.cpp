#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define int long long
#define rep(i,a,b) for (int i=a; i<b; ++i)
const int mod = 1e9 + 7;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    sort(a.begin(),a.end());
    int count = 0;
    int p1 = 0;
    int p2 = n-1;
    while(p1<=p2){
        if(a[p1] + a[p2] <= x){
            p1++;
        }
        p2--;
        count++;
    }
    cout<<count<<ln;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
}