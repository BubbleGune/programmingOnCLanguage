#include <stdio.h>
#include <stdlib.h>

int CountDigits(int x);
int SumDigits(int x);
int Search(int n, int digit);

int main()
{
	printf("count = %d\n", CountDigits(243));	
	printf("sum = %d\v", SumDigits(243));
	
	int n, digit;
	scanf("%d%d", &n, &digit);
	printf("%s\n", Search(n, digit) ? "yes" : "no");	
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
int Search(int n, int digit)
{
	n = abs(n);
	while (n >= 10 && n % 10 != digit)
		n /= 10;
	return n >= 10 || n == digit;
}
