#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX_VAL = 2000000000;

class Parser {
public:
    string expr;
    int index;
    int n;
    bool error_flag;

    Parser(string s) : expr(s), index(0), n(s.length()), error_flag(false) {}

    ll parse_expression() {
        ll value = parse_term();
        while (!error_flag && index < n) {
            skip_spaces();
            if (index >= n) break;
            if (expr[index] == '+') {
                index++;
                ll term = parse_term();
                value += term;
                if (abs(value) > MAX_VAL) {
                    error_flag = true;
                    return 0;
                }
            }
            else if (expr[index] == '-') {
                index++;
                ll term = parse_term();
                value -= term;
                if (abs(value) > MAX_VAL) {
                    error_flag = true;
                    return 0;
                }
            }
            else {
                break;
            }
        }
        return value;
    }

private:
    ll parse_term() {
        ll value = parse_factor();
        while (!error_flag && index < n) {
            skip_spaces();
            if (index >= n) break;
            if (expr[index] == '*') {
                index++;
                ll factor = parse_factor();
                value *= factor;
                if (abs(value) > MAX_VAL) {
                    error_flag = true;
                    return 0;
                }
            }
            else {
                break;
            }
        }
        return value;
    }

    ll parse_factor() {
        skip_spaces();
        if (index >= n) {
            error_flag = true;
            return 0;
        }

        if (expr[index] == '(') {
            index++;
            ll value = parse_expression();
            skip_spaces();
            if (index >= n || expr[index] != ')') {
                error_flag = true;
                return 0;
            }
            index++;
            return value;
        }
        else {
            int start = index;
            if (expr[index] == '+' || expr[index] == '-') {
                index++;
            }
            if (index >= n || !isdigit(expr[index])) {
                error_flag = true;
                return 0;
            }
            int num_start = index;
            while (index < n && isdigit(expr[index])) {
                index++;
            }
            for(int i = num_start; i < index; ++i){
                if(expr[i] == ' '){
                    error_flag = true;
                    return 0;
                }
            }
            string num_str = expr.substr(start, index - start);
            ll num;
            try {
                num = stoll(num_str);
            }
            catch (...) {
                error_flag = true;
                return 0;
            }
            if (abs(num) > MAX_VAL) {
                error_flag = true;
                return 0;
            }
            return num;
        }
    }

    void skip_spaces(){
        while(index < n && expr[index] == ' ') index++;
    }
};

int main(){
    string input_expr;
    getline(cin, input_expr);

    string allowed = "0123456789+-*() ";
    for(char c : input_expr){
        if(allowed.find(c) == string::npos){
            cout << "WRONG";
            return 0;
        }
    }

    stack<char> stk;
    for(char c : input_expr){
        if(c == '('){
            stk.push(c);
        }
        else if(c == ')'){
            if(stk.empty()){
                cout << "WRONG";
                return 0;
            }
            stk.pop();
        }
    }
    if(!stk.empty()){
        cout << "WRONG";
        return 0;
    }

    Parser parser(input_expr);
    ll result = parser.parse_expression();

    while(parser.index < input_expr.length() && input_expr[parser.index] == ' ') parser.index++;

    if(parser.error_flag || parser.index != input_expr.length()){
        cout << "WRONG";
    }
    else{
        cout << result;
    }
}
