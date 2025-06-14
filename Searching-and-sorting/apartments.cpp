#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define int long long
const int mod = 1e9 + 7;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(b.begin(),b.end());
    sort(a.begin(),a.end());
    int p1 = 0;
    int p2 = 0;
    int count = 0;
    while(p1 < n && p2 < m){
        if(abs(a[p1] - b[p2]) <= k){
            p1++;
            p2++;
            count++;
        }
        else{
            if(a[p1] > b[p2]) p2++;
            else p1++;
        }
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