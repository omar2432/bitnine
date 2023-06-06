#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    DIV,
    FIBO
} TypeTag;

typedef struct Node {
    TypeTag type;
} Node;


typedef struct FibMemo {
    int values[100];
} FibMemo;

int fibonacci(int n, FibMemo* memo) {
    if (n <= 1) {
        return n;
    }

    if (memo->values[n] != -1) {
        return memo->values[n];
    }

    int result = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    memo->values[n] = result;
    return result;
}

Node* makeFunc(TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    return node;
}

void calc(Node* node,int first, int second) {
    if (node->type == ADD) {
        int a = first, b = second;
        int result = a + b;
        printf("add: %d\n", result);
    } else if (node->type == MUL) {
        int a = first, b = second;
        int result = a * b;
        printf("mul: %d\n", result);
    } else if (node->type == SUB) {
        int a = first, b = second;
        int result = a - b;
        printf("sub: %d\n", result);
    } else if (node->type == DIV) {
        double a = first, b = second;
        double result = a/b;
        printf("div: %lf\n", result);
    } else if (node->type == FIBO) {
        int n = first;
        FibMemo memo;
        for (int i = 0; i < 100; i++) {
            memo.values[i] = -1;
        }
        int result = fibonacci(n, &memo);
        printf("fibo: %d\n", result);
    }
}

int main() {
    Node* add = makeFunc(ADD);
    Node* mul = makeFunc(MUL);
    Node* sub = makeFunc(SUB);
    Node* div = makeFunc(DIV);
    Node* fibo = makeFunc(FIBO);

    calc(add,10,6);
    calc(mul,3,5);
    calc(sub,13,7);
    calc(div,12,4);
    calc(fibo,4,NULL);

    free(add);
    free(mul);
    free(sub);
    free(div);
    free(fibo);

    return 0;
}
