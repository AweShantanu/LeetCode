#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

class Solution {
public:
    int Operate(int a, int b, const std::string& s) {
        if (s == "+") return a + b;
        else if (s == "-") return a - b;
        else if (s == "*") return a * b;
        else if (s == "/") return a / b;
        throw std::invalid_argument("Invalid operator");
    }
    
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;
        int first = 0;
        int second = 0;
        int n = tokens.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                second = st.top(); st.pop(); // The second operand should be popped first
                first = st.top(); st.pop();  // The first operand should be popped second
                res = Operate(first, second, tokens[i]);
                st.push(res);
            } else {
                st.push(std::stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};
