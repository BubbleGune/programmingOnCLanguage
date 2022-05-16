#include <stdio.h>
#include <stdlib.h>

#define N 10
int IsProgression(const int *a, const int n);
int IsEquals(const int *a, const int n);
int IsEqualsIfOrderedArray(const int *a, const int n);
int IsElementsDifferent(const int *a, const int n);
void Exchange(int *a, int n, int x);

int main()
{
	int a[N] = {0};
	for (int i = 0; i < N; i++){
		a[i] = rand() % 10;	
		printf("%d\n", a[i]);
	}
	putchar('\v');
	Exchange(a, N, 6);
	putchar('\v');
	for (int i = 0; i < N; i++)
		printf("%d\n", a[i]);		
//	printf("%d\n", IsElementsDifferent(a, N));
//	printf("%d\n", IsEqualsIfOrderedArray(a, N));
//	printf("%d\n", IsProgression(a, N));		
//	printf("%ld\n", sizeof(a) / sizeof(*a));	
}
int IsProgression(const int *a, const int n)
{
	int d = a[1] - a[0], i;
	for (i = 2; i < n && a[i] - a[i - 1] == d; i++);
	return (i >= n);
}
int IsEquals(const int *a, const int n)
{
	int i, j, is_not_equals = 1;
	for (int i = 1; i < n && is_not_equals; i++)
	{
		for (j = 0; j < i && a[i] != a[j]; j++);
		is_not_equals = (i == j);
	}
	return is_not_equals;
}
int IsEqualsIfOrderedArray(const int *a, const int n)
{
	int i;
	for (i = 1; i < n && a[i] != a[i - 1]; i++);
	return i >= n;
}
int IsElementsDifferent(const int *a, const int n)
{
	int i, is_different = 1, count[256] = {0};
//	for (int i = 0; i < n && is_different; i++)
//	{
//		count[a[i]]++;
//		if (count[a[i]] > 1)
//			is_different = 0;
//		if(++count[a[i]] > 1)
//			is_different = 0;
//	}	
	for (int i = 0; i < n && ++count[a[i]]; i++);
	return i >= n;
}
void Exchange(int *a, int n, int x)
{
	int i = 0, j = n - 1, buf;
	while (i < j)
	{
		while (i < j && a[i] < x)
			i++;
		while (i < j && a[j] >= x)
			j--;
		if (i < j)
		{		
			buf = a[i]; a[i] = a[j]; a[j] = buf;
		}
	}	
}
