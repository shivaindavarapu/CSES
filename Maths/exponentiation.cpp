#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
#define int long long

const int mod = 1e9 + 7;
int modularBinaryExponentiation(int base, int exponent){
    if (exponent == 0)
        return 1;
    int result = modularBinaryExponentiation(base,exponent/2);
    if (exponent%2==1)
        return (((result * result) % mod) * base) % mod;
    else
        return (result * result) % mod;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<modularBinaryExponentiation(a,b)<<ln;
    }
    return 0;
}