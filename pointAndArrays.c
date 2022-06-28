#include <stdio.h>

int Sum(int *begin, int *end);

int main() {
	int size, a = { 1, 4, 3, 5, 6, 6, 10, 50 };
	size = sizeof(a)/sizeof(*a);
	printf("sum = %d\n", Sum(a, a + size));
}

int Sum(int *begin, int *end) {
	int sum = 0, *pa;
	for(pa = begin; pa < end; pa++)
		sum += *pa;
	return sum;
}
