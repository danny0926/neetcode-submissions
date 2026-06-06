class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cur_min = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if (prices[i] < cur_min){
                cur_min = prices[i];
            }
            else if (prices[i] - cur_min > ans){
                ans = prices[i] - cur_min;
            }
        }
        return ans;
    }
};
