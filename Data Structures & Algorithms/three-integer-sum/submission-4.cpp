#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i){
            if(i > 0 &&nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; ++j) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int tar = -nums[i] - nums[j];
                auto it = lower_bound(nums.begin()+j+1, nums.end(), tar);
                int idx = it - nums.begin();
                if(idx < n && nums[idx] == tar){
                    vector<int> t = {nums[i], nums[j], tar};
                    sort(t.begin(), t.end());

                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};
