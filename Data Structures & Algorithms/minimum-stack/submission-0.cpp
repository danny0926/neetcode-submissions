#include<stack>
using namespace std;
class MinStack {
private:
    stack<int> stk;
    stack<int> sub_stk;
public:
    MinStack() {
    }
    
    void push(int val) {
        stk.push(val);

        if (sub_stk.empty() || (!sub_stk.empty() && val <= sub_stk.top())){
            sub_stk.push(val);
        }
    }
    
    void pop() {
        
        if(!sub_stk.empty() && stk.top() == sub_stk.top()){
            sub_stk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return sub_stk.top();
    }
};
