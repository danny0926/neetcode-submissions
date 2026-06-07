#include<unordered_map>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> umap;
        int l = 0;
        int maxFreq = 0;
        int ans = 0;
        int n = s.size();

        for(int r = 0; r < n; ++r) {
            umap[s[r]]++;
            maxFreq = max(maxFreq, umap[s[r]]);

            int curLen = r - l + 1;
            if(curLen - maxFreq <= k) {
                // can be changed in k step
                ans = max(ans, curLen);
            }
            else{
                // else, move l
                umap[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};
