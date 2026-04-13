# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0
    def traverse(self,root):
        if root is None:
            return
        if root.left is not None and root.left.left is  None and root.left.right is None:
            self.sum += root.left.val
        self.traverse(root.left)
        self.traverse(root.right)

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        self.traverse(root)
        return self.sum
        
        
    