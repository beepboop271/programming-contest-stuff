#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack {
    int * data;
    int top;
    int length;
};

typedef stack stack;

stack * createStack(int size) {
    stack * s = malloc(sizeof(stack));
    s->length = 0;
    s->data = calloc(size, sizeof(int));
    s->top = -1;
    return s;
}

void destroyStack(stack * s) {
    free(s->data);
    free(s);
}

void push(stack * s, int data) {
    s->top += 1;
    s->data[s->top] = data;
}

int pop(stack * s) {
    if(s->top == -1) {
        return INT_MAX;
    } else {
        int result = s->data[s->top];
        s->data[s->top] = 0;
        s->top -= 1;
        return result;
    }
}

int peek(stack * s) {
    if(s->top == -1) {
        return INT_MAX;
    } else {
        return s->data[s->top];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int test = 0; test < t; test++) {
        int n, input, hold, required=1;
        scanf("%d", &n);
        stack * m = createStack(n+10);
        for(int car = 0; car < n; car++) {
            scanf("%d", &input);
            push(m, input);
        }
        stack * b = createStack(n+10);
        while(required <= n) {
            //printf("%d %d %d\n", peek(m), peek(b), required);
            if(peek(m) == required) {
                //printf("a\n");
                required++;
                pop(m);
            } else if(peek(b) == required) {
                //printf("b\n");
                required++;
                pop(b);
            } else {
                hold = pop(m);
                if(hold != INT_MAX) {
                    //printf("c\n");
                    push(b, hold);
                } else {
                    //printf("d\n");
                    hold = pop(b);
                    while(hold == required) {
                        required++;
                        hold = pop(b);
                    }
                    break;
                }
            }
        }
        if(required-1 == n) printf("Y\n");
        else printf("N\n");
        destroyStack(b);
        destroyStack(m);
    }

    return 0;
}
