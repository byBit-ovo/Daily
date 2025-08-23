class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> list[str]:
        res = []
        def traverse(pre, root):
            if root is None:
                return
            
            pre += str(root.val)

            if root.left is None and root.right is None:
                res.append(pre)
    
            pre += "->"
            traverse(pre,root.left)
            traverse(pre,root.right)
        traverse("",root)
        return res

l = ["hello", "nice ", 'to','meet you']
s = ','.join(l)
print(s)
print(f"hello{s}")
        