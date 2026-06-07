#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; ++i) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                int prev_i = stk.top();
                stk.pop();
                ans[prev_i] = i-prev_i;
            }
            stk.push(i);
        }
        return ans;
    }
};
