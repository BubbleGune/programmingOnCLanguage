#include <stdio.h>

int CountDigits(int x);
int SumDigits(int x);

int main()
{
	printf("count = %d\n", CountDigits(243));	
	printf("sum = %d\n", SumDigits(243));
}
int CountDigits(int x)
{
	int count = 1;
	while(x /= 10)
		count++;
	return count;
}
int SumDigits(int x)
{
	int sum = x % 10;
	while (x /= 10)
		sum += x % 10;
	return sum;
}
