#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLEN 1000
#define MAXLINES 100

int get_line(char *pch, int maxlen) {
    char ch;
    int l = 0;

    for (int i = 0; i < maxlen - 1; i++) {
        ch = getchar();
        if (ch == '\n' || ch == EOF) {
            break;
        }
        // count the character ONLY if it is not a newline and not an EOF
        l++;
        *pch++ = ch;
    }
    *pch = '\0';
    
    return l;
}

int readlines(char *lineptr[], int maxlines) {
    /* 
        lineptr is a pointer to an array of pointers to text lines; 
        maxlines is the maximum number of lines to read. 
    */
    char line[MAXLEN], *p;
    int nlines = 0, len = 0;
    
    while ((len = get_line(line, MAXLEN)) > 0) {
        p = (char *) malloc(len * sizeof(char));
        if (p == NULL || nlines > MAXLINES) 
            return -1;

        strcpy(p, line);
        lineptr[nlines++] = p;
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    printf("nlines = %d\n", nlines);
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void swap(char *a[], int i, int j) {
    char *t = a[i];
    a[i] = a[j];
    a[j]= t;
}


int partition(char *a[], int left, int right) {
    char *pivot = a[right];
    int i = left - 1;
    
    printf("pivot = %s\n", pivot);
    for (int j = left; j <= right - 1; j++) {
        if (strcmp(a[j], pivot) < 0) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, right);

    return (i + 1);
}


int partition_2(char *a[], int left, int right) {
    char *pivot = a[right];
    int i = left, j = right - 1;
    while (true) {
        while (strcmp(a[i], pivot) <= 0 && i < right) {
            i++;
        }

        while (strcmp(a[j], pivot) >= 0 && j > left) {
            j--;
        }

        if (i >= j) {
            break;
        }

        swap(a, i, j);
    }
    
    swap(a, i, right);

    return i;
}


void quick_sort(char *array[], int first, int last) {
    if (first >= last) {
        return;
    }

    int mid = partition_2(array, first, last); 
    quick_sort(array, first, mid - 1);
    quick_sort(array, mid + 1, last);

}


int main() {
    char *lineptr[MAXLINES];
    int nlines = readlines(lineptr, MAXLINES);
    quick_sort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
}