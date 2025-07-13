import queue
from collections import deque
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.res = 0
    def traverse(self,root, pre):
        if root is None:return
        pre = pre * 10
        pre += root.val
        if root.left is None and root.right is None:
            self.res += pre
        self.traverse(root.left, pre)
        self.traverse(root.right, pre)
        
    def sumNumbers(self, root: TreeNode) -> int:
        self.traverse(root,0)
        return self.res

# q = deque()
# for i in range(10):
#     q.append(i)

# print(q)
# q.append('a')
# l = list(q)
# print(l)
# while q:
#     print(q.pop())  

# l = [i for i in range(10)]
# print(l)

# while l :
#     print(l[-1])
#     l.pop(-1)

# ll =[]

# if not ll :
#     print('ll is empty')

# ll.append(2)

# if ll:
#     print('ll is not empty')

# if 1 !=2 :
#     print('q')
l = [1,2,3]
l.pop(0)
print(l)
l = []
print(l)
q = deque()
q.append(1)
q.append(1)
q.append(1)
q.appendleft(2)
print(q[0])
        
