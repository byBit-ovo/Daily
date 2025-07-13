class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> list[int]:
        if root is None: return []
        q = deque()
        q.append(root)
        res = []
        while q :
            size = len(q)
            for i in range(size):
                node = q.popleft()
                if node.left is not None: q.append(node.left)
                if node.right is not None: q.append(node.right)
                if i == size-1 : res.append(node.val)
        return res
    
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution2:

    def rightSideView(self, root: TreeNode) -> list[int]:
        def traverse(height,root,res):
            if root is None: return
            if height > len(res):
                res.append(root.val)
            traverse(height+1, root.right, res)
            traverse(height+1, root.left, res)
        res = []
        traverse(1,root,res)
        return res

a: list
b: list