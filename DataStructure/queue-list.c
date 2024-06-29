#include<stdio.h>
#include<stdlib.h>

#define size 100

typedef struct s_queue{
    int key;
    struct s_queue *next;
} QUEUE;

//プロトタイプ宣言
QUEUE *newqueue(void);
void enqueue(int k);
int dequeue(void);

QUEUE *queuetop;
QUEUE *queuerear;

QUEUE *newqueue(void){

    QUEUE *p;

    p = (QUEUE *)malloc(sizeof(QUEUE));
    if(p == NULL){
        fputs("malloc failed\n", stderr);
        exit(1);
    }else{
        return p;
    }
}

void enqueue(int k){

    QUEUE *new;
    QUEUE *w;

    new = newqueue();
    new->key = k;
    new->next = NULL;
    if(queuerear == NULL && queuetop == NULL){
        queuerear = new;
        queuetop = new;
    }else{
        w = queuerear;
        queuerear = new;
        w->next = new;
    }

}

int dequeue(void){

    QUEUE *w;
    int k;

    if(queuerear == NULL && queuetop == NULL){
        printf("Queue is empty.\n");
        return 0;
    }else if (queuerear == queuetop){
        k = queuetop->key;
        queuerear = NULL;
        queuetop= NULL;
    }else{
        k = queuetop->key;
        w = queuetop;
        queuetop = w->next;
        free(w);
    }

    return k;
}

int main(void){

    int n;
    char s[2];
    queuetop = NULL;
    queuerear = NULL;

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