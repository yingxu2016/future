class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.empty()) {
            return 0;
        }
        unordered_set<string> wl(wordList.begin(), wordList.end());
        if (!wl.count(endWord)) return 0;
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int l = beginWord.length();
        int ans = 0;
        while(!q1.empty() && !q2.empty()) {
            ans++;
            if(q1.size() > q2.size()) {
                swap(q1, q2);
            }
            unordered_set<string> tmp;
            for(string s : q1) {
                for(int i = 0; i < l; i++) {
                    char c = s[i];
                    for(int j = 'a'; j <= 'z'; j++) {
                        s[i] = j;
                        if(q2.count(s)) return ans + 1;
                        if(!wl.count(s)) continue;
                        tmp.insert(s);
                        wl.erase(s);
                    }
                    s[i] = c;
                }
            }
            swap(tmp, q1);
        }
        return 0;
    }
};
