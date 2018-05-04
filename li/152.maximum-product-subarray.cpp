class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = nums[0], max_ = nums[0], min_ = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int tmpMax = max_;
            int tmpMin = min_;
            max_ = max(max(tmpMax * nums[i], tmpMin * nums[i]), nums[i]);
            min_ = min(min(tmpMax * nums[i], tmpMin * nums[i]), nums[i]);
            ans = max(max_, ans);
        }
        return ans;
    }
};
