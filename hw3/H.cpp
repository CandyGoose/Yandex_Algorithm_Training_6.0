#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<ll, ll>> stack;
    
    while(n--){
        char op;
        cin >> op;
        if(op == '+'){
            ll x;
            cin >> x;
            if(stack.empty()){
                stack.emplace_back(x, x);
            }
            else{
                ll cum_sum = stack.back().second + x;
                stack.emplace_back(x, cum_sum);
            }
        }
        else if(op == '-'){
            if(!stack.empty()){
                ll val = stack.back().first;
                stack.pop_back();
                cout << val << "\n";
            }
        }
        else if(op == '?'){
            ll k;
            cin >> k;
            if(k <= 0 || k > stack.size()){
                cout << "0\n";
            }
            else{
                ll sum;
                if(k == stack.size()){
                    sum = stack.back().second;
                }
                else{
                    sum = stack.back().second - stack[stack.size() - k -1].second;
                }
                cout << sum << "\n";
            }
        }
    }
}
