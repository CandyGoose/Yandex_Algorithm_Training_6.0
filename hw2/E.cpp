#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<long long, int> pii;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a){
        cin >> x;
    }
    
    ordered_set s;
    for(int i=0; i<n; i++){
        s.insert({a[i], i});
    }
    
    vector<long long> res;
    
    while(!s.empty()){
        int m = s.size();
        long long median;
        pii elem;
        
        if(m % 2 == 1){
            int pos = m / 2;
            elem = *s.find_by_order(pos);
        }
        else{
            int pos1 = m / 2 - 1;
            int pos2 = m / 2;
            pii e1 = *s.find_by_order(pos1);
            pii e2 = *s.find_by_order(pos2);
            
            if(e1.first != e2.first){
                elem = e1;
            }
            else{
                elem = e1;
            }
        }
        
        res.push_back(elem.first);
        s.erase(elem);
    }
    
    for(auto x: res){
        cout << x << ' ';
    }
}
