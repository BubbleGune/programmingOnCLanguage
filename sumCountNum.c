#include <stdio.h>
#include <stdlib.h>

int CountDigits(int x);
int SumDigits(int x);
int Search(int n, int digit);
int Reverse(int a);
int Degree5(unsigned long a);
unsigned long GetNumber(unsigned long a);

int main()
{
	printf("count = %d\n", CountDigits(243));	
	printf("sum = %d\v", SumDigits(243));
	
	int n, digit;
	scanf("%d%d", &n, &digit);
	printf("%s\n", Search(n, digit) ? "yes" : "no");	
	printf("%d\n", Reverse(234));
	printf("%d\n", Degree5(225));
	printf("%lu\n", GetNumber(102035));
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
int Reverse(int a)
{
	int b = 0;
	do 
		b = b * 10 + a % 10;
	while (a /= 10);
	return b;
}
int Degree5(unsigned long a)
{
	if (a == 0) 
		return 0;
	while (!(a % 5))
		a /= 5;
	return (a == 1);
}
unsigned long GetNumber(unsigned long a)
{
	unsigned long p = 1, b = 0, digit;
	while(a)
	{
		digit = a % 10;
		if(digit != 0 && digit != 5)
		{
			b += digit * p;
			p *= 10;
		}
		a /= 10;
	}
	return b;
}
