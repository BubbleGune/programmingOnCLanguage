#include <stdio.h>

void Delete(int *a, int *pn, int x);
int GetMinMax(int *a, int n, int *p_min, int *p_max);
void Replace(int *a, int *p, int x);

int main()
{
	int a[] = { 1, 2, 3, 3, 3, 5, 7, 2, 4, 5, 1, 2 };
	int i, size;
	size = sizeof(a)/sizeof(*a);
//	Delete(a, &size, 2);
	Replace(a, &size, 3);
	for (int i = 0; i < size; i++)
		printf("%d\n", a[i]);
	int min, max;
//	printf("is find - %d min = %d max = %d\n", GetMinMax(a, size, &min, &max), min, max);
}
void Delete(int *a, int *pn, int x)
{
	int j, i;
	for (j = 0; j < *pn && a[j] != x; j++);
	printf("%5d\n", j);
	for (i = j+1; i < *pn; i++)
	{	
		if (a[i] != x)
			a[j++] = a[i];	
	}
	*pn = j;
}
int GetMinMax(int *a, int n, int *p_min, int *p_max)
{
	int i;
	for (i = 0; i < n && a[i] <= 0; i++);
	if (i >= n) return 0;
	else
	{
		*p_min = *p_max = a[i];
		for (; i < n; i++)
			if (a[i] > 0)
				if (a[i] < *p_min) *p_min = a[i];
				else if (a[i] > *p_max) *p_max = a[i];
		return 1;
	}
}

void Replace(int *a, int *pn, int x)
{
	int i, j, k;
	i = j = 0;
	while(i < *pn) 
	{
		k = 0;
		while(i < *pn && a[i] == x) 
		{
			i++;
			k++;
		}
		if (k > 0)
			a[j++] = x;
		while (i < *pn && a[i] != x)
			a[j++] = a[i++];
	}
	*pn = j;
}
