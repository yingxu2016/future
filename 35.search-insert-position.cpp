class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while(l + 1 < r) {
            int mid = (l + r) >> 1;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        if(target <= nums[l])
            return l;
        else if (target <= nums[r])
            return r;
        return r + 1;
    }
};
