#include<stdio.h>
#include<stdlib.h>

#define size 100
#define N 8

int G[N+1][N+1] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 0, 1},
    {0, 1, 0, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 1, 0, 0}
};
int visited[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int A[size];
int queuetop = -1;
int queuerear = -1;

//プロトタイプ宣言
void init();
void enqueue(int n);
int dequeue();

void init(){
    
    for(int i=0; i<size; i++){
        A[i] = 0;
    }
}

void enqueue(int n){

    if(queuerear == size-1){
        printf("queue is full.\n");
        exit(1);
    }else{
        queuerear++;
        A[queuerear] = n;
    }
}

int dequeue(){

    if(queuetop == queuerear){
        printf("queue is empty.\n");
        return 0;
    }else{
        queuetop++;
        return A[queuetop];
    }
}

int main(void){

    int i;

    init();
    enqueue(1);
    visited[1] = 1;
    do{
        i = dequeue();
        for(int j=1; j<N+1; j++){
            if(G[i][j] == 1 && visited[j] == 0){
                printf("%d->%d ", i,j);
                enqueue(j);
                visited[j] = 1;
            }
        }
    }while(queuetop!=queuerear);
    
    printf("\n");
    return 0;
}