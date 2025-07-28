#include "sort.h"
#define N 1000000
void test()
{
    srand((unsigned int)time(0));
    int* a1 = new int[N];
    int* a2 = new int[N];
    int* a3 = new int[N];
    int* a4 = new int[N];
    int* a5 = new int[N];
    int* a6 = new int[N];
    int* a7 = new int[N];
    for (int i = 0; i < N; ++i)
    {
        a1[i] = rand();
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
        a7[i] = a1[i];
    }
    /*int begin1 = clock();
    select_sort(a1, N);
    int end1 = clock();*/

    int begin2 = clock();
    shell_sort(a2, N);
    int end2 = clock();

    int begin3 = clock();
    quick_sort1(a3, 0, N - 1);
    int end3 = clock();

    /* int begin4 = clock();
     bubble_sort(a4, N);
     int end4 = clock();*/

     /* int begin5 = clock();
      insert_sort(a5, N);
      int end5 = clock();*/

    int begin6 = clock();
    heap_sort(a6, N);
    int end6 = clock();

    int begin7 = clock();
    merge_sort(a7, 0, N - 1);
    int end7 = clock();

    //cout << "select_sort: " << end1 - begin1 << endl;
    cout << "shell_sort: " << end2 - begin2 << endl;
    cout << "quick_sort: " << end3 - begin3 << endl;
    /*   cout << "bubble_sort: " << end4 - begin4 << endl;
       cout << "insert_sort: " << end5 - begin5 << endl;*/
    cout << "heap_sort: " << end6 - begin6 << endl;
    cout << "merge_sort: " << end7 - begin7 << endl;
    delete[]a1;
    delete[]a2;
    delete[]a3;
    delete[]a4;
    delete[]a5;
    delete[]a6;
    delete[]a7;
}

int main()
{
    //test();
    int a[10] = { 2,6,1,8,6 };
    quick_sort3(a, 0, 4);
  
    return 0;
}



