#include <stdio.h>

int main()
{
	int k, a, max;
	puts("Enter k: ");
	scanf("%d", &k);
	puts("Enter number: ");
	scanf("%d", &a);	
	
	while (a != 0)
	{
		if (a > k)
			k = a;
		puts("Enter a: ");
		scanf("%d", &a);
	}
	printf("k = %d\n", k);
}
