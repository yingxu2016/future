class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(left, right):
            nonlocal nums
            pivot = nums[left]
            l = left + 1
            r = right
            while l <= r:
                if pivot > nums[l] and pivot <= nums[r]: // create a descending order array
                    nums[l], nums[r] = nums[r], nums[l]
                    l += 1
                    r -= 1
                if pivot <= nums[l]:
                    l += 1
                if pivot > nums[r]:
                    r -= 1
            nums[left], nums[r] = nums[r], nums[left]
            return r
        
        l = 0
        r = len(nums) - 1
        while True:
            pivot_index = partition(l, r)
            if pivot_index == k-1:
                return nums[pivot_index]
            elif pivot_index > k-1:
                r = pivot_index -1
            else:
                l = pivot_index + 1
        return -1
        
        
