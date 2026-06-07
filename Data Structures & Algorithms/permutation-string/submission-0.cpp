#include<unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> umap;

        int m = s1.size();
        int n = s2.size();
        if (m > n) return false;

        for(auto& c: s1){
            umap[c]++;
        }
        int l = 0;
        for(int r = 0; r < n; ++r){
            umap[s2[r]]--;
            while(umap[s2[r]] < 0){
                umap[s2[l]]++;
                l++;
            }
            if(r - l + 1 == m) return true;
        }
        return false;
    }
};
