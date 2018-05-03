class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n1 = -1, n2 = -1;
        int ans = INT_MAX;
        for(int i = 0; i < words.size(); i++) {
            int t = n1;
            if(word1 == word2) {
                if(words[i] == word1) {
                    n1 = i;
                    if(t != -1) {
                        ans = min(ans, abs(i - t));
                    }
                }
            }
            else {
                if(words[i] == word1) {
                    n1 = i;
                }
                if(words[i] == word2) {
                    n2 = i;
                }
                if(n1 != -1 && n2 != -1) {
                    ans = min(ans, abs(n1 - n2));
                }
            }
        }
        return ans;
    }
};
