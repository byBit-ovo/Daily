#pragma once
#include <vector>
#include <iostream>
using namespace std;
void insert_sort(vector<int>& v);
void shell_sort(vector<int>& v );
void select_sort(vector<int>& v);
void quick_sort1(vector<int>& v,int begin,int end);
void quick_sort2(vector<int>& v,int left,int right);
void quick_sort3(vector<int>& v,int left,int right);
void bubble_sort(vector<int>& v);
void heap_sort(vector<int>& v);
void _merge_sort(vector<int>& v, vector<int>& tmp, int left, int right);
void merge_sort(vector<int>& v);
