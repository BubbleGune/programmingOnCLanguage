#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3
#define M 2

void Print(int a[][N], int m, int n);
void Init(int a[][N], int m, int n);
int IsSort(int *a, int n);
void PrintMatrix(int a[][N], int i0, int j0, int size);
void SubMatrix(int a[][N], int n);

int main()
{
	//int t[3][2] = { {1, 2}, {5, 3}, {10, 0} };	
	// or
	//int t[3][2] = {1, 2, 3, 4, 5, 6};
	// something elem equal zero
	// int t[3][2] = {{1}, {2}, {5}};
	// all elem equal zero
	//int t[5][13] = {0};
//	int a[M][N];
//	srand(time(NULL));
//	Init(a, M, N);
//	int i, count;
//	for (i = count = 0; i < M; i++)
//		if (IsSort(a[i], N))
//			count++;
//	printf("count - %d\v", count);
//	Print(a, M, N);
//	int a[N][N];
//	SubMatrix(a, N);
}
void Print(int a[][N], int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%5d", a[i][j]);
		putchar('\n');
	}
}
void Init(int a[][N], int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a[i][j] = rand() % 100;
}
int IsSort(int *a, int n)
{
	int i;
	for (i = 0; i < n && a[i-1] < a[i]; i++);
	return (i >= n);
}
void PrintMatrix(int a[][N], int i0, int j0, int size)
{
	int i, j;
	for (i = i0; i < i0 + size; i++)
	{
		for (j = j0; j < j0 + size; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
	printf("\n");
}
void SubMatrix(int a[][N], int n)
{
	int i0, j0, size;
	for (size = 1; size <= n; size++)
		for (i0 = 0; i0 < n - size + 1; i0++)
			for (j0 = 0; j0 < n - size + 1; j0++)
				PrintMatrix(a, i0, j0, size);	
}
