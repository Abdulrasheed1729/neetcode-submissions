class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0;
        int R = s.size() - 1;
        
        for (auto& c: s) {
            if(isupper(c)) c = tolower(c);
        }

        while(L < R) {
            if(!isalnum(s[L])) { L++; }
            else if (!isalnum(s[R])) { R--; }
            else if(s[L] != s[R]) { return false; }
            else { L++; R--; }
        }

        return true;
    }
};
