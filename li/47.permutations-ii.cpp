class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        int s = nums.size();
        unordered_map<int, int> m;
        for(auto i : nums) {
            m[i]++;
        }
        vector<int> curr;
        helper(m, s, curr, ans);
        return ans;
    }
    void helper(unordered_map<int, int>& m, int s, vector<int>& curr, vector<vector<int>>& ans) {
        if(curr.size() == s) {
            ans.push_back(curr);
            return;
        }
        for(auto& entry : m) {
            if(entry.second > 0) {
                curr.push_back(entry.first);
                entry.second--;
                helper(m, s, curr, ans);
                curr.pop_back();
                entry.second++;
            }
        }
    }
};
