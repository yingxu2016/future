class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        max_so_far = nums[0]
        min_so_far = nums[0]
        result = max_so_far
        
        for i in range(1, len(nums)):
            cur = nums[i]
            tmp_max = max(cur, max_so_far*cur, min_so_far*cur) // keep max_so_far unchange during max()/min() comparison
            min_so_far = min(cur, max_so_far*cur, min_so_far*cur)
            
            max_so_far = tmp_max
            result = max(max_so_far, result)
            
        return result
