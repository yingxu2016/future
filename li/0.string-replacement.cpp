// String Replacement
// Three strings as input. Output the first string with all the second string replaced by the third string

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replace(string orig, string pattern, string repl) {
        if(pattern.empty() || pattern == repl) {
            return orig;
        }
        int pos = orig.find(pattern);
        if(pos == string::npos) {
            return orig;
        }
        return orig.substr(0, pos) + repl + replace(orig.substr(pos + pattern.size()), pattern, repl);
    }
};

class Solution2 {
public:
    string replace(string orig, string pattern, string repl) {
        if(pattern.empty() || pattern == repl) {
            return orig;
        }
        int pos = myFind(orig, pattern);
        if(pos < 0) {
            return orig;
        }
        return orig.substr(0, pos) + repl + replace(orig.substr(pos + pattern.size()), pattern, repl);
    }
private:
    int myFind(string s, string p) {
        if(s.size() < p.size()) {
            return -1;
        }
        for(int i = 0; i < s.size() - p.size(); ++i) {
            int k = i;
            int j;
            for(j = 0; j < p.size(); ++j, ++k) {
                if(s[k] != p[j]) {
                    break;
                }
            }
            if(j == p.size()) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    string orig = "foohahaorzhahahelloword";
    string pattern = "haha";
    string repl = "whysoserious";
    Solution2 s;
    cout << s.replace(orig, pattern, repl) << endl;
}