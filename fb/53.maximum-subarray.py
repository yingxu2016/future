class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        maxSum = dp = nums[0]
        for n in nums[1:]:
            dp = max(dp + n, n)
            maxSum = max(maxSum, dp)
            
        return maxSum
