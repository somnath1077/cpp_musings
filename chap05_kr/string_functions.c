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
	char s[N] = "Pat sat on a cat. ", t[N] = "That cat blew a hole in my hat.";
	printf("%s\n", strcat(s, t));
	printf("%s\n", my_strncpy(s, t, 7));
}
