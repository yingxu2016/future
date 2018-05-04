class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int target = 0;
        int n = nums.size();
        for (auto e : nums)
            target += e;
        if (target % k != 0)
            return false;
        target = target / k;
        vector<bool> visited(n, false);
        return canPartition(nums, visited, k, 0, 0, target);
    }

    bool canPartition(vector<int>& nums, vector<bool>& visited, int k, int start, int s, int target) {
        if (k == 0)
            return true;
        if (s == target)
            return canPartition(nums, visited, k-1, 0, 0, target);
        for (int i = start; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                if (canPartition(nums,visited, k, i+1, s+nums[i], target))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};
