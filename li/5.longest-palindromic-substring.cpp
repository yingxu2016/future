class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) {
            return s;
        }
        int ssize = s.size();
        int begin = 0;
        int end = 0;
        for(int i = 0; i < ssize; i++) {
            int j = 0;
            for(; i - j >= 0 && i + j < ssize && s[i-j] == s[i+j]; j++) {}
            j--;
            if(2 * j > end - begin) {
                begin = i - j;
                end = i + j;
            }
            for(j = 0; i - 1 - j >= 0 && i + j < ssize && s[i-1-j] == s[i+j]; j++) {}
            j--;
            if(2 * j + 1 > end - begin) {
                begin = i - 1 - j;
                end = i + j;
            }
        }
        return s.substr(begin, end - begin + 1);
    }
};