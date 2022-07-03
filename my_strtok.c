#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Init(int *flag, char *s);
char *my_strtok(char *s, const int *flag);
char *my_strtok2(char *s, const int *flag);

#define delimiters " .,:;\n\t"
#define N 1000

typedef unsigned char UCHAR;

int main() {
	char s[N], *word;
	int flag[256];
	fgets(s, N, stdin);
	Init(flag, delimiters);
	word = my_strtok2(s, flag);
	while(word != NULL) {
		puts(word);
		free(word);
		word = my_strtok2(NULL, flag);
	}
	puts(s);
}

// this option is not to damage string *s
char *my_strtok2(char *s, const int *flag) {
	static char *beg = NULL;
	char *pstr, *pword = NULL;
	int len;
	if (s != NULL) {
		for(pstr = s; *pstr && flag[(UCHAR)*pstr]; ++pstr);
		beg = pstr;
	}
	else
		pstr = beg;
	for(; *beg && !flag[(UCHAR)*beg]; ++beg);
	if (*pstr) {
		pword = (char*)malloc(beg-pstr+1);
		if (pword != NULL) {
			len = (beg-pstr) / sizeof(char);
			strncpy(pword, pstr, len);
			pword[len] = '\0';
		}
	}
	for(; *beg && flag[(UCHAR)*beg]; ++beg);
	return pword;
}

// this option is to damage a string *s
char *my_strtok(char *s, const int *flag) {
	static char *beg = NULL;
	char *pword, *pbuf;
	if (s != NULL) {
		for(pword = s; *pword && flag[(UCHAR)*pword]; ++pword);
		beg = pword;
	}		
	else
		pword = beg;
	for(; *beg && !flag[(UCHAR)*beg]; ++beg);
	pbuf = beg;
	for(; *beg && flag[(UCHAR)*beg]; ++beg);
	*pbuf = '\0';
	return *pword ? pword : NULL;
}

void Init(int *flag, char *s) {
	int i;
	for(i = 0; i < 256; i++)
		flag[i] = 0;
	for(i = 0; s[i]; i++)
		flag[s[i]] = 1;
}
