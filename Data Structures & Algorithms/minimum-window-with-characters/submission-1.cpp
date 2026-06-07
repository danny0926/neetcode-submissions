#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (n > m) return "";

        unordered_map<char, int> umap;
        for(auto& c: t) umap[c]++;

        int l = 0;
        int ans = INT_MAX;
        int start_idx = 0;
        int required = n;

        for(int r = 0; r < m; ++r) {
            if (umap[s[r]] > 0){
                required--;
            }
            umap[s[r]]--;

            while (required == 0 && l <= r){
                if(r - l + 1 < ans) {
                    ans = min(ans, r-l+1);
                    start_idx = l;
                }
                umap[s[l]]++;
                if(umap[s[l]] > 0){
                    required++;
                }
                l++;
            }
        }
        cout << start_idx << ' ' << ans ;
        if (ans < INT_MAX)
            return s.substr(start_idx, ans);
        return "";
    }
};
