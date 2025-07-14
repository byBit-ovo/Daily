# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self,str, root):
        if root is None: return
        if root.left is None and root.right is None:
            str = chr(root.val + ord('a')) + str
            if self.res == "" : self.res = str
            else : self.res = min(self.res,str)
            return
        str = chr(root.val + ord('a')) + str
        self.traverse(str, root.left)
        self.traverse(str, root.right)

    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.res = ""
        self.traverse("",root)
        return self.res
            
        
