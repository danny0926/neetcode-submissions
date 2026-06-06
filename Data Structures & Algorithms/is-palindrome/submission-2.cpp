#include<cctype>
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;

        while (l <= r) {
            while(l < n && !isalpha(s[l]) && !isdigit(s[l])) l++;
            while(r >= 0 && !isalpha(s[r]) && !isdigit(s[r])) r--;
            if (l > r) break;
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};
