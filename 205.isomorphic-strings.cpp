class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.empty() || t.empty()) return true;
        unordered_map<char, char> m;
        for(int i = 0; i < s.size(); i++) {
            if(!m.count(s[i])) {
                m[s[i]] = t[i];
            }
            else if(m[s[i]] != t[i]) {
                return false;
            }
        }
        m.clear();
        for(int i = 0; i < s.size(); i++) {
            if(!m.count(t[i])) {
                m[t[i]] = s[i];
            }
            else if(m[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isIsomorphic(string s, string t) {
        int map_s[128] = { 0 };
        int map_t[128] = { 0 };
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;
    }
};

