# LarryNY's Code
# Will solve on my own - after today's Meeting

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        best = 0
        
        def goLeft(node, depth):
            if node is None:
                return

            nonlocal best
            goLeft(node.left, 1)
            right = goRight(node.right, depth + 1)
            best = max(best, depth)

        def goRight(node, depth):
            if node is None:
                return

            nonlocal best
            goRight(node.right, 1)
            left = goLeft(node.left, depth + 1)
            best = max(best, depth)

        goLeft(root.left, 1)
        goRight(root.right, 1)
        return best