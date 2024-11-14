#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 100000;

bool is_open(char c, const unordered_map<char, char>& matching_closing) {
    return matching_closing.find(c) != matching_closing.end();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string w;
    cin >> w;
    string s;
    cin >> s;
    
    unordered_map<char, int> order_map;
    for(int i=0;i<4;i++) {
        order_map[w[i]] = i;
    }
    
    unordered_map<char, char> matching_closing = {
        {'(', ')'},
        {'[', ']'}
    };
    
    unordered_map<char, char> matching_opening;
    for(auto &[open, close] : matching_closing){
        matching_opening[close] = open;
    }
    
    vector<char> sorted_brackets(4);
    for(int i=0;i<4;i++) sorted_brackets[i] = w[i];
    sort(sorted_brackets.begin(), sorted_brackets.end(), [&](const char a, const char b) -> bool{
        return order_map[a] < order_map[b];
    });
    
    stack<char> stk;
    for(char c : s){
        if(matching_closing.find(c) != matching_closing.end()){
            stk.push(c);
        }
        else{
            if(stk.empty() || stk.top() != matching_opening[c]){
            }
            else{
                stk.pop();
            }
        }
    }
    
    int m = s.length();
    int rem = n - m;
    string result = s;
    
    while(rem >0){
        bool placed = false;
        for(char bracket : sorted_brackets){
            if(matching_closing.find(bracket) != matching_closing.end()){
                if(rem >= (int)(stk.size()) + 2){
                    result += bracket;
                    stk.push(bracket);
                    rem -=1;
                    placed = true;
                    break;
                }
            }
            else{
                if(!stk.empty()){
                    char top = stk.top();
                    if(matching_closing[top] == bracket){
                        if(rem >= (int)(stk.size())){
                            result += bracket;
                            stk.pop();
                            rem -=1;
                            placed = true;
                            break;
                        }
                    }
                }
            }
        }
        if(!placed){
            break;
        }
    }
    
    cout << result;
}
