class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> s;
        for(auto i : tokens) {
            if(i == "+" || i == "-" || i == "*" || i == "/") {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                if(i == "+")
                    s.push(num1 + num2);
                else if(i == "-")
                    s.push(num1 - num2);
                else if(i == "*")
                    s.push(num1 * num2);
                else
                    s.push(num1 / num2);
            }
            else {
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};
