#include "Heap.h"
void DataCreat()
{
	srand((unsigned int)time(0));
	const char* file = "data.txt";
	FILE* fout = fopen(file, "w");
	if (fout == NULL)
	{
		perror("file open fail!");
		return;
	}
	int i = 0;
	int a[1000];
	while (i < 1000)
	{
		a[i] = (rand() + i) % 1000;
		i++;
	}
	for (i = 0; i < 1000; i++)
	{
		fprintf(fout, "%d\n", a[i]);
	}
	fclose(fout);
}
void Topk()
{
	FILE* fout = fopen("data.txt", "r");
	int k = 0;
	scanf_s("%d", &k);
	int* a = (int*)malloc(sizeof(int) * k);
	int i = 0;
	int x;
	while (i < k)
	{
		fscanf_s(fout, "%d", &a[i++]);
	}
	for (i = (k - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, i, k);
	}
	while (fscanf_s(fout, "%d", &x) != EOF)
	{
		if (x > a[0])
		{
			a[0] = x;
			AdjustDown(a, 0, k);
		}
	}
	for (i = 0; i < k; ++i)
	{
		printf("%d ", a[i]);
	}
	fclose(fout);
	free(a);
}
int main()
{
    DataCreat();
    Topk();

    return 0;
}