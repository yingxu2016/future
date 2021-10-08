# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []
        if root is None:
            return result
        queue = deque([root])
        tempLevel = deque()
        isFromLeft = True
        
        while len(queue) > 0:
            for i in range(len(queue)):
                node = queue.popleft()
                if isFromLeft:
                    tempLevel.append(node.val)
                else:
                    tempLevel.appendleft(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                    
            result.append(tempLevel)
            tempLevel = deque()
            isFromLeft = not isFromLeft
                    
        return result
