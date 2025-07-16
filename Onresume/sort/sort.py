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
    def quickSort(arr,start, end):
        
    # @staticmethod
    # def shellSort(arr: list):
# void shell_sort(vector<int>& v) {
#     int n = v.size();
#     int gap = n;

#     while (gap > 1) {
#         gap /= 2;
#         for (int i = gap; i < n; i++) {
#             int tmp = v[i];
#             int j = i;
#             while (j >= gap && v[j - gap] > tmp) {
#                 v[j] = v[j - gap];
#                 j -= gap;
#             }
#             v[j] = tmp;
#         }
#     }
# }
        





arr1 = [3,0,1,-5,6,4,8,9,-2]
arr2 = [1]
arr3 = []
# Sort.bubbleSort(arr1)
# Sort.bubbleSort(arr2)
# Sort.bubbleSort(arr3)
# Sort.selectSort(arr1)
# Sort.selectSort(arr2)
# Sort.selectSort(arr3)
Sort.insertSort(arr1)
Sort.insertSort(arr2)
Sort.insertSort(arr3)
print(arr1)
print(arr2)
print(arr3)



            
