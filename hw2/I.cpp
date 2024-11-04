#include <bits/stdc++.h>
using namespace std;

struct Algorithm {
    int index;
    long long a;
    long long b;
};

struct CompareA {
    bool operator()(const Algorithm& lhs, const Algorithm& rhs) const {
        if (lhs.a != rhs.a)
            return lhs.a < rhs.a;
        if (lhs.b != rhs.b)
            return lhs.b < rhs.b;
        return lhs.index > rhs.index;
    }
};

struct CompareB {
    bool operator()(const Algorithm& lhs, const Algorithm& rhs) const {
        if (lhs.b != rhs.b)
            return lhs.b < rhs.b;
        if (lhs.a != rhs.a)
            return lhs.a < rhs.a;
        return lhs.index > rhs.index;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    
    vector<long long> b(n);
    for(int i=0; i<n; ++i){
        cin >> b[i];
    }
    
    vector<int> p(n);
    for(int i=0; i<n; ++i){
        cin >> p[i];
    }
    
    vector<Algorithm> algorithms(n);
    for(int i=0; i<n; ++i){
        algorithms[i] = Algorithm{ i+1, a[i], b[i] };
    }
    
    priority_queue<Algorithm, vector<Algorithm>, CompareA> heap_a;
    priority_queue<Algorithm, vector<Algorithm>, CompareB> heap_b;
    
    for(auto &algo : algorithms){
        heap_a.push(algo);
        heap_b.push(algo);
    }
    
    vector<bool> removed(n+1, false);
    
    vector<int> order;
    order.reserve(n);
    
    for(int day=0; day<n; ++day){
        if(p[day] == 1){
            while(!heap_b.empty() && removed[heap_b.top().index]){
                heap_b.pop();
            }
            if(!heap_b.empty()){
                Algorithm selected = heap_b.top();
                heap_b.pop();
                removed[selected.index] = true;
                order.push_back(selected.index);
            }
        }
        else{
            while(!heap_a.empty() && removed[heap_a.top().index]){
                heap_a.pop();
            }
            if(!heap_a.empty()){
                Algorithm selected = heap_a.top();
                heap_a.pop();
                removed[selected.index] = true;
                order.push_back(selected.index);
            }
        }
    }
    
    for(int i=0; i<order.size(); ++i){
        cout << order[i] << (i < order.size()-1 ? ' ' : '\n');
    }
}
