class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        INI_MAX = float("infinity")
        localSum = 0
        minLen = INI_MAX
        left = 0
        
        for i in range(len(nums)):
            localSum += nums[i]
            while localSum >= target:
                minLen = min(minLen, i + 1 - left)
                localSum -= nums[left]
                left += 1
                
        return minLen if minLen != INI_MAX else 0
        
