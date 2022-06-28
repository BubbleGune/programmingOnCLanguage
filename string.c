#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define set "asdfghjkl;' "
#define system "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ"
#define words "ABDFE032"

void Initialize(char *s, int n);
int Sum_digit(const char *s);
void Init_with_space(char *s, int n);
void Init_from_set(char *s, int n);
void Itoa(int a, int p, char *s);
int Itoi(char *s, int p);
int Count_from_words(char *s);
int Check(char *s);
void my_strtok();

int main() {
	char s[100] = "aWDJSAW032 sdpweADW";
	int a, p;
//	printf("%d\n", Count_from_words(s));
	my_strtok();
}

#define N 1000
#define delimiters " .,:;?!\n\t"
typedef unsigned char uchar;
void my_strtok() {
	char sentence[N];
	char *word;
	int i, j, flag[256] = {0};
	fgets(sentence, 1000, stdin);
	for(i = 0; delimiters[i]; i++)
		flag[delimiters[i]] = 1; 
	for(i = 0; sentence[i] && flag[(uchar)sentence[i]]; i++);

	while(sentence[i]) {
		word = &sentence[i];
		while(sentence[i] && !flag[(uchar)sentence[i]])
			i++;
		j = i;
		while(sentence[i] && flag[(uchar)sentence[i]])
			i++;
		sentence[j] = '\0';
		puts(word);
	}
}

// Check if all symbols this line is different in pairs
typedef unsigned char uchar;
int Check(char *s) {
	int i, flag = 1, count[256] = {0};
	for(i = 0; s[i] && flag; i++) {
		count[(uchar)s[i]]++;
		if(count[(uchar)s[i]] > 1)
			flag = 0;
	}	
	return flag;
}

int Count_from_words(char *s) {
/*	int i, n;
	for (i = n = 0; s[i]; i++)
		if(strchr(words, s[i]))
			n++;
	return n; */
/*	char *ps = s;
	int count = 0;
	while(ps = strpbrk(ps, words)) {
		count++;
		ps++;
	}
*/
	int i, count, flag[256] = {0};
	for(i = 0; words[i]; i++)
		flag[words[i]] = 1;
	for(i = count = 0; s[i]; i++)
		count += flag[s[i]];
	return count;
}

int Itoi(char *s, int p) {
	int i, a, digit[256] = {0};
	for (i = 0; system[i]; i++)
		digit[system[i]] = i;
	for (i = a = 0; s[i]; i++)
		a = a*p + digit[s[i]];
	return a;
}

void Itoa(int a, int p, char *s) {
	//conversion from 10 numeral system(a) into p
	int i, j, buf;
	i = 0;
	do {
		s[i] = system[a%p];
		a /= p;
		i++;
	} while (a != 0);
	s[i] = '\0';
	j = i-1;
	i = 0;
	while (i < j) {
		buf = s[i]; s[i] = s[j]; s[j] = buf;
		i++; j--;
	}
}

void Init_from_set(char *s, int n) {
	int i, len;
	i = 0;
	len = strlen(set);
	while (i < n-1) {
		s[i] = set[rand()%len];
		i++;
	}
	s[i] = '\0';
}

void Init_with_space(char *s, int n) {
	int i;
	i = 0;
	while (i < n - 1) {
		if (rand() % 4 == 0)
			s[i] = ' ';
		else if (rand() % 13 == 0)
			s[i] = 'A' + rand() % 26;
		else
			s[i] = 'a' + rand() % 26;
		i++;
	}	
	s[n-1] = '\0';
}

int Sum_digit(const char *s) {
	int i, sum;
	i = sum = 0;
	while (s[i]) {
		if (isdigit(s[i]))
			sum += s[i] - '0';
		i++;
	}
	return sum;
}

void Initialize(char *s, int n) {
	if (n < 1 || n > 26) {
		printf("Number must be between 1 and 26\n"); 
		exit(-1); 
	}
	int i, k;
	i = k = 0;
	while (i < n) {
		s[k] = 'a' + i;	
		s[k+1] = 'A' + i;
		i++;
		k += 2;
	}
}
