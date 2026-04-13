#include "sort.h"
void insert_sort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i, tmp = v[end + 1];
		while (end >= 0)
		{
			if (tmp < v[end])
			{
				v[end + 1] = v[end]; --end;
			}
			else break;
		}
		v[end+1] = tmp;
	}
}
void shell_sort(vector<int>& v)
{
	int n = v.size(), gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n-gap;i++)
		{
			int end = i, tmp = v[end + gap];
			while (end >= 0)
			{
				if (tmp < v[end])
				{
					v[end + gap] = v[end]; end-=gap;
				}
				else break;
			}
			v[end + gap] = tmp;
		}
	}

}
void select_sort(vector<int>& v)
{
	int min_key, max_key, n = v.size();
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		min_key = begin; max_key = end;
		for (int i = begin; i <= end; ++i)
		{
			if (v[i] > v[max_key]) max_key = i;
			if (v[i] < v[min_key]) min_key = i;
		}
		swap(v[begin], v[min_key]);
		swap(v[end], v[max_key]);
		++begin; --end;
	}
}
void quick_sort1(vector<int>& v,int begin,int end)
{
	if (begin >= end) return;
	int left = begin, right = end;
	int aim = v[begin];
	while (left < right)
	{
		while (left<right && v[right] >= aim) --right;
		while (left<right && v[left] <= aim) ++left;
		swap(v[left], v[right]);
	}
	swap(v[begin], v[left]);
	quick_sort1(v, begin, left-1);
	quick_sort1(v, left+1,end);
}
void quick_sort2(vector<int>& v,int left,int right)
{
	if (left>=right) return;
	int begin = left, end = right;int aim = v[begin];
	while (begin < end)
	{
		while (begin < end && v[end] >= aim) --end;
		v[begin] = v[end];
		while (begin < end && v[begin] <= aim) ++begin;
		v[end] = v[begin];
	}

	v[begin] = aim;
	quick_sort2(v, left, begin - 1);
	quick_sort2(v, begin+1,right);
}
void quick_sort3(vector<int>& v,int left,int right)
{
	if (right <= left) return;
	int aim = v[left];
	int prev = left, cur = left+1;
	while (cur <= right)
	{
		if (v[cur] >= aim) ++cur;
		else
		{
			swap(v[++prev], v[cur]);
			++cur;
		}
			
	}
	swap(v[left], v[prev]);
	quick_sort3(v, left, prev - 1);
	quick_sort3(v, prev+1,right);
}
void bubble_sort(vector<int>& v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 1; j < n - i ; ++j)
		{
			if (v[j-1] > v[j]) swap(v[j-1], v[j]);
		}
	}
}
void adjust_down(vector<int>& v, int parent, int end)
{
	int child = parent * 2 + 1;
	while (child <= end)
	{
		if (child+1 <=end && v[child] < v[child + 1]) ++child;
		if (v[child] > v[parent])
		{
			swap(v[child], v[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}
void heap_sort(vector<int>& v)
{
	//creat heap up
	int end = v.size() - 1;
	int start = (end - 1) / 2;
	while (start >= 0)
	{
		adjust_down(v, start, end);
		--start;
	}
	//has completed the heap
	//sort
	while (end > 0)
	{
		swap(v[0], v[end--]);
		adjust_down(v, 0, end);
	}
}
void merge_sort(vector<int>& v)
{
	vector<int> tmp(v);
	_merge_sort(v, tmp, 0, v.size() - 1);
}
void _merge_sort(vector<int>& v,vector<int>& tmp, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	_merge_sort(v,tmp,left, mid);
	_merge_sort(v, tmp,mid+1,right);
	//[left,mid] [mid+1,right]
	int begin1 = left, begin2 = mid + 1, i = left;
	while (begin1 <= mid && begin2 <= right)
	{
		if (v[begin1] < v[begin2])
		{
			tmp[i++] = v[begin1++];
		}
		else
		{
			tmp[i++] = v[begin2++];
		}
	}
	while (begin1 <= mid)
	{
		tmp[i++] = v[begin1++];
	}
	while (begin2 <= right)
	{
		tmp[i++] = v[begin2++];
	}
	for (int j = left; j <= right; ++j) v[j] = tmp[j];
	
}

//1 0 2 3 0 0 3 4 5 0