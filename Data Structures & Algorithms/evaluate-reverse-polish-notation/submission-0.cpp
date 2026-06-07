#include<stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> stk;

        for(auto& c: tokens){
            if (c == "+" || c == "-" || c == "*" || c == "/"){
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                switch (c[0]){
                    case '+': 
                        stk.push(x+y);
                        break;
                    case '-': 
                        stk.push(x-y);
                        break;
                    case '*': 
                        stk.push(x*y);
                        break;
                    case '/': 
                        stk.push(x/y);
                        break;
                }
            }
            else stk.push(stoi(c));
        }
        return stk.top();
    }
};
