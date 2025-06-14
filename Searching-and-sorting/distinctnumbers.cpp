#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define int long long
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    set<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size();
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