class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l <= r) {
            ans = max(ans, (r-l)*min(heights[r], heights[l]));

            if(heights[r] <= heights[l]) r--;
            else l++;
        }
        return ans;
    }
};
