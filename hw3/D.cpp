#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int evaluatePostfix(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {
            stack.push(std::stoi(token));
        } else {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            if (token == "+") {
                stack.push(a + b);
            } else if (token == "-") {
                stack.push(a - b);
            } else if (token == "*") {
                stack.push(a * b);
            }
        }
    }

    return stack.top();
}

int main() {
    std::string expression;
    std::getline(std::cin, expression);

    int result = evaluatePostfix(expression);
    std::cout << result << std::endl;

    return 0;
}
