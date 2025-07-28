import qrcode
# 冒泡、选择、插入、希尔、快排、归并排序、堆排序
class Sort:
    @staticmethod
    def bubbleSort(arr: list):
        for i in range(len(arr),-1,-1):
            for j in range(1,i):
                if arr[j-1] > arr[j]:
                    arr[j-1], arr[j] = arr[j], arr[j-1]
    @staticmethod
    def selectSort(arr: list):
        for i in range(len(arr)):
            minIndex = i
            for j in range(i,len(arr)):
                if arr[j] < arr[minIndex]:
                    minIndex = j
            arr[i], arr[minIndex] = arr[minIndex], arr[i]
    @staticmethod
    def insertSort(arr: list):
        for end in range(len(arr)):
            cur = arr[end]
            i = end - 1
            while i >= 0:
                if arr[i] > cur:
                    arr[i+1] = arr[i]
                else:
                    break
                i-=1
            arr[i+1] = cur
    #先把数组排大致有序，再插入排序，效率更高
    @staticmethod
    def shellSort(arr: list):
        n = len(arr)
        gap = n // 2

        while gap > 0:
            for i in range(gap, n):
                temp = arr[i]
                j = i
                while j >= gap and arr[j - gap] > temp:
                    arr[j] = arr[j - gap]
                    j -= gap
                arr[j] = temp
            gap //= 2
    @staticmethod
    def quickSort(arr, start, end):
        if start >= end:
            return
        pivot = arr[start]
        small = [x for x in arr[start:end+1] if x <  pivot]
        big   = [x for x in arr[start+1:end+1] if x >= pivot]
        Sort.quickSort(small,0,len(small) - 1)
        Sort.quickSort(big,0,len(big) - 1)
        arr[:] = small + [pivot] + big

arr1 = [3,0,1,-5,6,4,8,9,-2]
arr2 = [1]
arr3 = []

print(arr1[1:3])
print(arr2)
print(arr3)

# img1 = qrcode.make('祁政儒真帅')
# img2 = qrcode.make('www.youtube.com')
# img1.save('img1.png')
# img2.save('img2.png')