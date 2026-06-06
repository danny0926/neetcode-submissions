#include<algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        for(int i =0; i <n; ++i) {
            int x = numbers[i];
            int y = target - x;
            if (x > y) break;

            auto it = lower_bound(numbers.begin(), numbers.end(), y);
            int idx = it - numbers.begin();
            if (idx < n && numbers[idx] == y) return {i+1, idx+1};
        }
        return {-1, -1};
    }
};
