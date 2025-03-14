#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9 + 7;

ll modularBinaryExponentiation(int base, int exponent){
    if (exponent == 0)
        return 1;
    ll result = modularBinaryExponentiation(base,exponent/2);
    if (exponent%2==1)
        return (((result * result) % mod) * base) % mod;
    else
        return (result * result) % mod;
}

int main(){
    ll n;
    cin >> n;
    ll answer = 0;
    for (ll i = 1,j; i <= n; i = j)
    {
        ll q = n/i;
        j = n/q + 1;
        ll sumTilljm1 = ((((j%mod)*((j-1)%mod))%mod)*modularBinaryExponentiation(2,mod-2))%mod;
        ll sumTillim1 = ((((i%mod)*((i-1)%mod))%mod)*modularBinaryExponentiation(2,mod-2))%mod;
        ll temp = (sumTilljm1-sumTillim1+mod)%mod;
        answer = (answer+(q%mod)*temp)%mod;
    }
    cout << answer;
}