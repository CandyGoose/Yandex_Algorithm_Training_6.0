#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll c;
    cin >> n >> c;
    string s;
    cin >> s;
    
    vector<ll> prefix_a(n, 0);
    vector<ll> prefix_b(n, 0);
    vector<ll> sum_b_a(n, 0);
    
    for(int i=0; i<n; ++i){
        prefix_a[i] = (i > 0 ? prefix_a[i-1] : 0) + (s[i] == 'a' ? 1 : 0);
        prefix_b[i] = (i > 0 ? prefix_b[i-1] : 0) + (s[i] == 'b' ? 1 : 0);
        sum_b_a[i] = (i > 0 ? sum_b_a[i-1] : 0) + (s[i] == 'a' ? prefix_b[i] : 0);
    }
    
    int left =0;
    ll max_len =0;
    
    for(int right=0; right<n; ++right){
        ll grobost = prefix_b[right] * (prefix_a[right] - (left >0 ? prefix_a[left-1] : 0)) 
                      - (sum_b_a[right] - (left >0 ? sum_b_a[left-1] : 0));
        
        while(left <= right && grobost > c){
            left +=1;
            if(left > right){
                break;
            }
            grobost = prefix_b[right] * (prefix_a[right] - (left >0 ? prefix_a[left-1] : 0)) 
                      - (sum_b_a[right] - (left >0 ? sum_b_a[left-1] : 0));
        }
        
        if(grobost <=c){
            max_len = max(max_len, (ll)(right - left +1));
        }
    }
    
    cout << max_len;
}
