# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self,root):
        if root is None:
            return
        if root.left is None and root.right is None:
            od = self.odd
            if ( self.count[root.val] + 1) % 2 == 1:
                od += 1
            else:
                od -= 1

            if od <= 1:
                self.res += 1
            return
        self.count[root.val] += 1
        if self.count[root.val] % 2 == 1:
            self.odd += 1
        else:
            self.odd -= 1
        self.traverse(root.left)
        self.traverse(root.right)
        self.count[root.val] -= 1
        if self.count[root.val] % 2 == 1:
            self.odd += 1
        else:
            self.odd -= 1



    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        self.count = [0]*10
        self.odd = 0
        self.res = 0
        self.traverse(root)
        return self.res