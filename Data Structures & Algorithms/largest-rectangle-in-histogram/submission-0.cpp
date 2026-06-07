#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        
        vector<int> h;
        h.push_back(0);
        for(auto& x: heights) h.push_back(x);
        h.push_back(0);
        int n = h.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            while(!stk.empty() && h[stk.top()] > h[i]){
                int prev_i = stk.top();
                stk.pop();
                int prev_prev_i = stk.top();
                int height = h[prev_i];
                ans = max(ans, height*(i - prev_prev_i - 1));
            }
            stk.push(i);
        }
        return ans;
    }
};
