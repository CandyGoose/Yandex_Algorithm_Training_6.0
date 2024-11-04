#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const ll inv6 = 166666668;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &x : a){
        cin >> x;
    }
    
    ll S = 0;
    ll S2 = 0;
    ll S3 = 0; 
    
    for(int i=0; i<n; ++i){
        S = (S + a[i]) % MOD;
        S2 = (S2 + (a[i] * a[i]) % MOD) % MOD;
        S3 = (S3 + ((a[i] * a[i]) % MOD * a[i]) % MOD) % MOD;
    }
    
    ll term1 = (((S * S) % MOD) * S) % MOD;
    
    ll term2 = ((3LL * S) % MOD * S2) % MOD;
    
    ll term3 = (2LL * S3) % MOD;
    
    ll res = (term1 - term2 + term3) % MOD;
    if(res < 0){
        res += MOD;
    }
    
    res = (res * inv6) % MOD;
    
    cout << res;
}
