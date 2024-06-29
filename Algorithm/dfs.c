#include<stdio.h>
#include<stdlib.h>

#define size 100
#define N 8

int G[N+1][N+1] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 1},
    {0, 1, 0, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 1, 0, 0}
};
int A[size];
int visited[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
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
        stackpop += 1;
        A[stackpop] = n;
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
    int i, j;

    init();
    push(1);
    visited[1] = 1;
    do{
        i = pop();
        for(j = 1; j < N+1; j++){
            if(G[i][j] == 1 && visited[j] == 0){
                push(i);
                push(j);
                visited[j] = 1;
                printf("%d->%d ", i, j);
                break;
            }
        }

    }while(stackpop != -1);
    printf("\n");
    return 0;
}