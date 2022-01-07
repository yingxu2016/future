class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        cur = 0
        for i in range(1, len(nums)):
            if nums[cur] != nums[i]:
                cur += 1
                nums[cur] = nums[i]
        return cur+1
        
