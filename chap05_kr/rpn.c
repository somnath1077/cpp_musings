#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 1000
#define STACK_ERROR '1'
#define STACK_OK '0'


typedef struct {
    int buf[STACK_SIZE];
    int top_of_stack;
} stack;

typedef struct {
    int value;
    char error_code;
} stack_ret;

stack_ret push(stack *s, int c) {
    stack_ret ret;

    if (s->top_of_stack == STACK_SIZE) {
        printf("Stack full. Cannot push.\n");
        ret.error_code = STACK_ERROR;
    } else {
        s->buf[s->top_of_stack++] = c;
        ret.error_code = STACK_OK; 
        ret.value = c;
    }
    return ret;
}

stack_ret pop(stack *s) {
    stack_ret ret;

    if (s->top_of_stack == 0) {
        printf("Stack empty. Cannot pop.\n");
        ret.error_code = STACK_ERROR;
    } else {
        ret.value = s->buf[--s->top_of_stack];
        ret.error_code = STACK_OK;
    }
    
    return ret;
}

int is_int(char *p) {
    while (*p != '\0') {
        if (!isdigit(*p)) {
            return 0;
        }
        p++;
    }
    return 1;
}

char binary_operator(char *p) {
    char *ops[4] = {"+", "-", "*", "/"};
    
    for (int i = 0; i < 4; i++) {
        if (strcmp(p, ops[i]) == 0) 
            return *ops[i];
    }

    return '\0';
}

char unary_operator(char *p) {
    if (strcmp(p, "n") == 0) 
        return 'n';
    return '\0'; 
}

int main(int argc, char *argv[]) {
    stack stack;
    stack.top_of_stack = 0;
    char op = '\0';

    for (int i = 1; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);

        if (is_int(argv[i])) {
            stack_ret val =  push(&stack, atoi(argv[i]));  

            if (val.error_code == STACK_ERROR) {
                printf("Input too big. \n");
                return 1;
            }
        } 
        else if (
            (op = binary_operator(argv[i])) != '\0'
        ) {
            stack_ret val2 = pop(&stack);
            stack_ret val1 = pop(&stack);

            if  (val2.error_code == STACK_ERROR || val1.error_code == STACK_ERROR) {
                printf("Invalid expression (else if). \n");
                return 1;
            }

            switch (op) {
                case '+':
                    push(&stack, val1.value + val2.value);
                    break;
                case '-':
                    push(&stack, val1.value - val2.value);
                    break;
                case '*':
                    push(&stack, val1.value * val2.value);
                    break;
                case '/':
                    push(&stack, val1.value / val2.value);
                    break;
            }
            
        }
        else if (unary_operator(argv[i]) != '\0') {
            stack_ret val = pop(&stack);
            
            if  (val.error_code == STACK_ERROR) {
                printf("Invalid expression (else if 2). \n");
                return 1;
            }

            push(&stack, -1 * val.value);
        }
        else {
            printf("Invalid input (else). \n");
            return 1;
        }

    }
    if (stack.top_of_stack == 1) {
         printf("%d\n", pop(&stack).value);
    } else {
        printf("Invalid input.\n");
        return 1;
    }
   
    
    return 0;
}