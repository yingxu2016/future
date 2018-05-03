class WordDistance {
private:
    unordered_map<string, int> m;
    unordered_map<string, vector<int>> mm;
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); i++) {
            mm[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        if(word1 > word2) {
            swap(word1, word2);
        }
        if(m.count(word1+word2)) {
            return m[word1+word2];
        }
        int ans = INT_MAX;
        vector<int> v1 = mm[word1];
        vector<int> v2 = mm[word2];
        for(int i = 0, j = 0; i < v1.size() && j < v2.size();) {
            ans = min(ans, abs(v1[i] - v2[j]));
            if(v1[i] < v2[j]) i++;
            else j++;
        }
        m[word1+word2] = ans;
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
