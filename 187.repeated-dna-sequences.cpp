class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> ans;
        if(s.length() < 10) return vector<string>();
        unordered_set<string> m;
        for(int i = 0; i < s.length() - 9; i++) {
            if(!m.count(s.substr(i,10))) {
                m.insert(s.substr(i,10));
            }
            else {
                ans.insert(s.substr(i,10));
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
