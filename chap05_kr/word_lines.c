#include <stdio.h>

#define IN 1 /*inside a word*/
#define OUT 0 /*outside a word*/

int main() {
    char c;
    int nc = 0, nl = 0, nw = 0;
    int state = OUT;

    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n') {
            nl++;
        }

        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            state = OUT;
        } else if (state == OUT) {
            state = IN; /*we are inside a word*/
            nw++;
        }
    }

    printf("c = %d\nw = %d\nl = %d\n", nc, nw, nl);
}