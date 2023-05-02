// This is a collection of several useful string functions implemented using pointers.
// These examples are to be found in  KR, Chapter5.

#include <stdio.h>
#include <stdlib.h>

#define N 100

/*
	strcmp compares two strings s and t and returns < 0, 0, > 0 if s is lexicographically lesser
 	than, equal to, or greater than t
*/

int strcmp(char *s, char *t) {
	int i = 0;
	for (; s[i] == t[i]; i++) {
		if (s[i] == '\0') 
			return 0;
	}
	return s[i] - t[i];
}

int strcmp_p(char *s, char *t) {
	for (; *s == *t; s++, t++) {
		if (*s == '\0') {
			return 0;
		}
	}

	return *s - *t;
}

char *my_strncpy(char *s, char *t, int n) {
	for (int i = 0; i < n; i++) {
		t[i] = s[i];
		if (s[i] == '\0') {
			break;
		}
	}
	return t;
}

char *strcpy_2(char *s, char *t) {
	/*
		Copies t to s
	*/
	int i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;

	return s;
}

char *strcpy_3(char *s, char *t) {
	/*
		Copies t to s
	*/
	char *init = s;

	while ((*s++ = *t++) != '\0') 
		;
	
	return init;
}

void strcpy_4(char *s, char *t) {
	/* Copies t to s*/
	while((*s++ = *t++) != '\0') 
		;
}

void strcpy_5(char *s, char *t) {
	/* Copies t to s*/
	while(*s++ = *t++) 
		;
}

size_t len(char *s) {
	size_t l = 0;
	while (s[l] != '\0') {
		l++;
	}

	return l;
}

char *strcat(char *s, char *t) {
	/**Copies t to the end of s */
	size_t len_s = len(s), len_t = len(t);
	char *ret = (char *) malloc((len_s + len_t + 1) * sizeof(char));
	
	for (; *s != '\0'; s++, ret++) {
		*ret = *s;
	}

	for (; *t != '\0'; t++, ret++) {
		*ret = *t;
	}

	*ret = '\0';

	return ret - len_s - len_t;
}


int main() {
	char s[N]; 
	char t2[N] = "strcpy_2: That cat blew a hole in my hat.";
	char t3[N] = "strcpy_3: No cat can blow a hole in my hat!!!";
	char t4[N] = "strcpy_4: Three cats blew a hole in my hat!";
	char t5[N] = "strcpy_5: Three cats blew a hole in my hat!";
	printf("%s\n", strcpy_2(s, t2));
	printf("%s\n", strcpy_3(s, t3));
	strcpy_4(s, t4);
	printf("%s\n", s);

	strcpy_5(s, t5);
	printf("%s\n", s);
}
