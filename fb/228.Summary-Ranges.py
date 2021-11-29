class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        if not nums:
            return ans
        l = 0
        
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1] + 1:
                if l == i - 1:
                    ans.append(str(nums[l]))
                else:
                    ans.append(str(nums[l]) + '->' + str(nums[i-1]))
                l = i
        if l == len(nums) - 1:
            ans.append(str(nums[l]))
        else:
            ans.append(str(nums[l]) + '->' + str(nums[len(nums)-1]))
        return ans
            
