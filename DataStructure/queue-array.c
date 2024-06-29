#include<stdio.h>
#include<stdlib.h>

#define size 5

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

    int n;
    char s[2];

    init();
    printf("enqueue: e, dequeue: d\n");
    while(scanf("%1s", s) != EOF){
        switch (s[0]){
            case 'e':
            case 'E':
                printf("Input key\n");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 'd':
            case 'D':
                printf("key:%d\n", dequeue());
                break;
        }
        printf("enqueue: e, dequeue: d\n");
    }

    return 0;

}