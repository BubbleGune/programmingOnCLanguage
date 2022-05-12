#include <stdio.h>

void GetPosNegNumWithIf();
void GetCountPositiveNum();
void GetPosNegNumWithoutIf();

int main()
{
//	GetPosNegNumWithIf();
//	GetCountPositiveNum();
	GetPosNegNumWithoutIf();
}
void GetCountPositiveNum()
{
	int a, n, max;
	puts("Enter number: ");
	scanf("%d", &a);
	while (a != 0)
	{
		n = 0;
		while (a > 0){
			n++;
			puts("Enter a: ");
			scanf("%d", &a);
		}	
		if (n > max)
			max = n;
		while (a < 0){
			puts("Enter a: ");
			scanf("%d", &a);
		}
		printf("n = %d\n", n);
	}
}
void GetPosNegNumWithIf()
{
	int a, nPlus, nMin;
	nPlus = nMin = 0;
	printf("a: ");
	scanf("%d", &a);
	while (a != 0)
	{
		if (a > 0)
		{
			nPlus++;
			if (nMin > 0)
			{
				printf("-: %d\n", nMin);
				nMin = 0;
			}
		}
		else
		{
			nMin++;
			if (nPlus > 0)
			{
				printf("+: %d\n", nPlus);
				nPlus = 0;
			}
		}	
		printf("Enter a: ");
		scanf("%d", &a);
	}
	if (nMin > 0)
		printf("-: %d\n", nMin);
	if (nPlus > 0)
		printf("+: %d\n", nPlus);
}
void GetPosNegNumWithoutIf()
{
	int a, n;
	printf("Enter a: ");
	scanf("%d", &a);

	while (a != 0)
	{	
		while (a > 0)
		{
			n++;
			printf("Enter a: ");
			scanf("%d", &a);	
		}
		if (n > 0)
		{
			printf("+: %d\n", n);
			n = 0;
		}	
		while (a < 0)
		{
			n++;
			printf("Enter a: ");
			scanf("%d", &a);
		}
		if (n > 0)
		{
			printf("-: %d\n", n);
			n = 0;
		}	
	}
}
