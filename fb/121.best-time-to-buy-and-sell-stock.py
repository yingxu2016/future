class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices is None:
            return 0
        
        maxProfit = 0
        minPrice = prices[0]
        for i in range(1, len(prices)):
            if minPrice > prices[i]:
                minPrice = prices[i]
            else:
                maxProfit = max(prices[i] - minPrice, maxProfit)
                
        return maxProfit
