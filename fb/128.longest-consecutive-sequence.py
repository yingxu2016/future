class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        longestStreak = 0
        numSet = set(nums)
        
        for num in nums:
            if num-1 not in numSet:
                localStreak = 1
                curNum = num
                
                while curNum+1 in numSet:
                    localStreak += 1
                    curNum += 1
                    
                longestStreak = max(longestStreak, localStreak)
        return longestStreak
