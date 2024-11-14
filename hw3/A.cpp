#include <iostream>
#include <stack>
#include <string>

std::string isBalanced(const std::string& sequence) {
    std::stack<char> stack;
    for (char ch : sequence) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.empty()) return "no";
            char top = stack.top();
            stack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return "no";
            }
        }
    }
    return stack.empty() ? "yes" : "no";
}

int main() {
    std::string sequence;
    std::cin >> sequence;
    std::cout << isBalanced(sequence) << std::endl;
    return 0;
}
