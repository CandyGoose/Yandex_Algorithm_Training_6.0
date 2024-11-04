#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for(auto &x : a){
        cin >> x;
    }
    
    sort(a.begin(), a.end());
    
    priority_queue<ll, vector<ll>, std::greater<ll>> minHeap;
    
    for(int i = 0; i < n; ++i){
        if(!minHeap.empty() && a[i] - minHeap.top() > k){
            minHeap.pop();
        }
        minHeap.push(a[i]);
    }
    
    cout << minHeap.size();
}
