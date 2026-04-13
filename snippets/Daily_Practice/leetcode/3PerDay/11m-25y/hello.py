from collections import deque

# print("hello","world","uuu",sep=",",end="")
lst = deque([1,4,6])
print(lst[1])
del lst[1]

# a = 1
# s = "hello"
# arr = [1,3,5,6]
# arr[2] = 1
# arr.insert(0,-1)
# # -1 3 1 6
# print(arr)
s = 'hello'
print(s%s)