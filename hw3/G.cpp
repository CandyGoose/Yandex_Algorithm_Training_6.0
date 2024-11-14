#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll b;
    cin >> n >> b;

    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    ll sum_served_time=0;
    ll sum_arrival=0;
    ll total_served=0;
    ll Q=0;

    vector<pair<int, ll>> queue;
    int front_idx=0;

    for(int t=1;t<=n;t++){
        ll a_t = a[t-1];
        Q +=a_t;
        if(a_t >0){
            queue.emplace_back(make_pair(t, a_t));
        }

        ll k = min(b, Q);
        sum_served_time += t *k;
        total_served +=k;
        ll served =k;

        while(served >0 && front_idx < queue.size()){
            ll cnt = queue[front_idx].second;
            if(cnt <= served){
                sum_arrival += (ll)queue[front_idx].first * cnt;
                served -=cnt;
                Q -=cnt;
                front_idx++;
            }
            else{
                sum_arrival += (ll)queue[front_idx].first * served;
                queue[front_idx].second -=served;
                Q -=served;
                served =0;
            }
        }
    }

    ll sum_unserved_time=0;
    for(int i=front_idx;i<queue.size();i++){
        ll arrival_time = queue[i].first;
        ll cnt = queue[i].second;
        sum_unserved_time += (ll)(n +2 - arrival_time) * cnt;
    }

    ll total_time = (sum_served_time - sum_arrival + total_served) + sum_unserved_time;

    cout << total_time;
}
