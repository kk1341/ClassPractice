#include<stdio.h>
#include<stdlib.h>

#define size 100

typedef struct s_stack{
    int key;
    struct s_stack *prev;
} STACK;


int A[size];
STACK *stacktop;

STACK *newstack(void){

    STACK *p;

    p = (STACK *)malloc(sizeof(STACK));
    if(p == NULL){
        fputs("malloc failed\n", stderr);
        exit(1);
    }else{
        return p;
    }

}

void push(int k){
    
    STACK *new;

    new = newstack();               //新しい要素のために領域を確保
    new->key = k;                   //新しい要素のkeyにkを代入
    new->prev = stacktop;           //stackpopがさしている場所を新しい要素のprevに指させる
    stacktop = new;                 //stacktopに新しい要素を指させる

}

int pop(void){

    STACK *w;
    int k;

    if(stacktop == NULL){
        printf("Stack is empty.\n");
        return 0;
    }else{
        k = stacktop->key;      //stacktopが指している場所のkeyを後で返すためにkに代入
        w = stacktop;
        stacktop = w->prev;
        free(w);
    }

    return k;
}

int main(void){

    int n;
    char s[2];
    stacktop = NULL;

    printf("push: u, pop: o\n");
    while(scanf("%1s", s) != EOF){
        switch (s[0]){
            case 'u':
            case 'U':
                printf("Input key\n");
                scanf("%d", &n);
                push(n);
                break;
            case 'o':
            case 'O':
                printf("key:%d\n", pop());
                break;
        }
        printf("push: u, pop: o\n");
    }

    return 0;

}