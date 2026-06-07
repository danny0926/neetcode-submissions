#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;

        int n = s.size();
        int ans = 0;

        int l = 0;
        for(int r = 0; r < n; ++r) {
            umap[s[r]]++;
            while(r >= l && umap[s[r]] > 1){
                umap[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
