class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int prepre = nums[0];
        int pre = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            int tmp = pre;
            pre = max((prepre + nums[i]), pre);
            prepre = tmp;
        }
        return pre;
    }
};
