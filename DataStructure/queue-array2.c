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

    //queueが満杯になる条件
    //・topが一度も動かずにrearがsize-1の値になること
    //・topとrearの値が等しくA[rear]の部分に何も入っていないこと
    //  → 今回はある場所に要素が何も入ってないときは0が格納されていると定義した
    if((queuetop == -1 && queuerear == size-1) || (queuetop == queuerear && A[queuerear] != 0)){
        printf("queue is full.\n");
        exit(1);
    }else if(queuerear == size-1){
        queuerear = 0;
    }else{
        queuerear++;
    }
    A[queuerear] = n;
}

int dequeue(){

    int return_value;

    if(queuetop == queuerear){
        printf("queue is empty.\n");
        return 0;
    }else if(queuetop == size-1){
        queuetop = 0;
    }else{
        queuetop++;
    }

    //値を取り出した後に値が格納されていないことを
    //示す0を格納しないとならないため，dequeueで返す値を別の変数に退避させる
    return_value = A[queuetop];
    A[queuetop] = 0;
    return return_value;
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