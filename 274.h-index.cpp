class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        sort(citations.begin(), citations.end(), greater<int>());
        if(citations[0] == 0) return 0;
        int ans = 1;
        for(int i = 0; i < citations.size(); i++) {
            if(citations[i] >= ans) {
                ans++;
            }
        }
        return ans - 1;
    }
};

