#include<stdio.h>
#include<stdlib.h>

#define size 100

int A[size];
int stackpop = -1;


void init(){
    
    for(int i=0; i<size; i++){
        A[i] = 0;
    }
}

void push(int n){

    if(stackpop == size-1){
        printf("stack is full\n");
        exit(1);
    }else{
        A[++stackpop] = n;
    }
}

int pop(void){

    if(stackpop == -1){
        printf("stack is empty\n");
        return 0;
    }else{
        return A[stackpop--];
    }
}

int main(void){

    int n;
    char s[2];

    init();
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