#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, r;
    cin >> n >> r;
    
    vector<ll> distances(n);
    for(auto &d : distances){
        cin >> d;
    }
    
    ll count = 0;
    ll j = 0;
    
    for(ll i = 0; i < n; ++i){
        if(j <= i){
            j = i + 1;
        }
        while(j < n && distances[j] - distances[i] <= r){
            j++;
        }
        count += (n - j);
    }
    
    cout << count;
}
