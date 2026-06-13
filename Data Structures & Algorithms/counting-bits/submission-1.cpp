class Solution {
public:
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        if(n == 1) return {0,1};

        vector<int> ans = {0, 1};

        int i = 2;
        int t = 0;
        while(i <= n){
            if((i & (i-1)) == 0) t = 0;
            ans.push_back(ans[t]+1);
            t++; 
            i++;
        }
        return ans;
    }
};
