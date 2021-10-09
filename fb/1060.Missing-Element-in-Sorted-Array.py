class Solution:
    def missingElement(self, nums: List[int], k: int) -> int:
        missing = lambda idx : nums[idx] - nums[0] - idx
        
        if k > missing(len(nums)-1):
            return nums[len(nums)-1] + k - missing(len(nums)-1)
        
        left, right = 0, len(nums)-1
        while left + 1 < right:
            pivot = left + (right-left)//2
            if k <= missing(pivot):
                right = pivot
            else:
                left = pivot
        return nums[left] + k - missing(left)
