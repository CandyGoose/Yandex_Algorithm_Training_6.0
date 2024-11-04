#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> a(n +1, 0);
    for(int i=1; i<=n; ++i){
        cin >> a[i];
    }
    
    vector<ll> prefix_a(n +1, 0);
    vector<ll> prefix_ai(n +1, 0);
    
    for(int i=1; i<=n; ++i){
        prefix_a[i] = prefix_a[i-1] + a[i];
        prefix_ai[i] = prefix_ai[i-1] + (i * a[i]);
    }
    
    ll W = prefix_a[n];
    ll target = (W +1) /2;
    
    int x =1;
    while(x <=n && prefix_a[x] < target){
        x++;
    }
    ll sum1 = x * prefix_a[x] - prefix_ai[x];
    ll sum2 = prefix_ai[n] - prefix_ai[x] - x * (prefix_a[n] - prefix_a[x]);
    ll sum_total = sum1 + sum2;
    
    cout << sum_total;
}
