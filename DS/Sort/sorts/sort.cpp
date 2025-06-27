#include"sort.h"
void Print_arr(int* a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}
void Adjust_down(int* a, int n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }
        if (a[child] > a[parent])
        {
            swap(a[child], a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
void heap_sort(int* a, int n)
{
    int parent = (n - 1 - 1) / 2;
    while (parent >= 0)
    {
        Adjust_down(a, n, parent--);
    }
    //堆已经建好
    for (int i = n - 1; i > 0; --i)
    {
        swap(a[0], a[i]);
        Adjust_down(a, i, 0);
    }
}
void insert_sort(int* a, int n)
{
    //[0..end]end+1
    int end = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (a[end] > tmp)
            {
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

void shell_sort(int* a, int n)
{
    int gap = n;
    while (gap >= 1)
    {
        gap /= 2;
        for (int j = 0; j < gap; ++j)
        {
            for (int i = j; i < n - gap; i += gap)
            {
                int end = i;
                int tmp = a[end + gap];
                while (end >= 0)
                {
                    if (a[end] > tmp)
                    {
                        a[end + gap] = a[end];
                        end -= gap;
                    }
                    else
                    {
                        break;
                    }
                }
                a[end + gap] = tmp;

            }
        }
    }
}

void select_sort(int* a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

int Get_Mid(int* a, int left, int right)
{
    int mid = (left + right) / 2;
    if (a[mid] > a[left])
    {
        if (a[mid] < a[right])
        {
            return mid;
        }
        else if (a[left] > a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    else
    {
        if (a[right] < a[mid])
        {
            return mid;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

void merge_sort(int* a, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);

}
void bubble_sort(int* a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (a[j + 1] < a[j])
                swap(a[j + 1], a[j]);
        }
    }
}
void quick_sort1(int* a, int left, int right)
{
    //区间只有一个值或不存在就是最小子问题
    if (left >= right)
    {
        return;
    }
    //    //小区间选择插入排序，可以减少90%左右的递归
    if (right - left + 1 <= 10)
    {
        insert_sort(a + left, right - left + 1);
    }
    else
    {

        //随机取数法*/ 
        //选取区间【left，right】内的一个随机数
        //int randomi = rand() % (right - left + 1);
        //randomi += left;
        //Swap(a[randomi], a[left]);//

        //三数取中法，把三个数的中位数交换到key位置
        int key = Get_Mid(a, left, right);
        swap(a[key], a[left]);
        key = left;
        int begin = left;
        int end = right;
        while (begin < end)
        {
            while (begin < end && a[end] >= a[key])
            {
                --end;
            }
            while (begin < end && a[begin] <= a[key])
            {
                ++begin;
            }
            swap(a[begin], a[end]);
        }
        swap(a[key], a[begin]);
        key = begin;
        //[left,1,..key-1]key[key+1,,right]
        quick_sort1(a, left, key - 1);
        quick_sort1(a, key + 1, right);
    }


}
void quick_sort2(int* a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int key = Get_Mid(a, left, right);
    swap(a[key], a[left]);
    key = a[left];
    int point = left;
    int begin = left;
    int end = right;
    while (begin < end)
    {
        while (begin < end && a[end] >= key)
        {
            --end;
        }
        a[point] = a[end];
        point = end;
        while (begin < end && a[begin] <= key)
        {
            ++begin;
        }
        a[point] = a[begin];
        point = begin;
    }
    a[point] = key;
    key = point;
    quick_sort2(a, left, key - 1);
    quick_sort2(a, key + 1, right);
}

void quick_sort3(int* a, int left, int right)
{
    ST st;
    STInit(&st);
    STPush(&st,left);
    STPush(&st,right);
    while (!STEmpty(&st))
    {
        int end = STPop(&st);
        int begin = STPop(&st);
        int et = end, bt = begin;
        int key = Get_Mid(a, begin, end);
        swap(a[key], a[begin]);
        key = begin;
        while (begin < end)
        {
            while (begin < end && a[end] >= a[key])
            {
                --end;
            }
            while (begin < end && a[begin] <= a[key])
            {
                ++begin;
            }
            swap(a[begin], a[end]);
        }
        swap(a[key], a[begin]);
        key = begin;
      
        if (key + 1 > et)
        {
            STPush(&st,key + 1);
            STPush(&st, et);
        }
        if (bt > key - 1)
        {
            STPush(&st, bt);
            STPush(&st, key - 1);
        }
    }
    STDestroy(&st);
}
