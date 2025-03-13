#include <bits/stdc++.h>
using namespace std;
#define ln '\n'
typedef long long ll;
const int mod = 1e9 + 7;
int main(){
    int n;
    cin>>n;
    vector<int> freq(1e6+1,0);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        freq[x]++;
    }
    for(int gcd=1e6;gcd>=0;gcd--){
        int count = 0;
        for(int i=gcd;i<=1e6;i+=gcd){
            count += freq[i];
        }
        if(count > 1){
            cout << gcd;
            return 0;
        }
    }
}