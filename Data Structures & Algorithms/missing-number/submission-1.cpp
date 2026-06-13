class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(auto& x: nums){
            ans ^= x;
        }
        for(int i = 0; i <= n; ++i){
            ans ^= i;
        }
        return ans;
    }
};
