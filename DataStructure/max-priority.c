#include<stdio.h>
#include<stdlib.h>

#define N 100

// プロトタイプ宣言
void init(int *A);
void swap(int i, int j, int *A);
void insert(int x, int *A, int *n);
void upmax(int i, int *A, int n);
int deletemax(int *A, int *n);
void downheapmax(int i, int *A, int n);

void init(int *A){

    for(int i=0; i<N+1; i++){
        A[i] = 0;
    }

}

void swap(int i, int j, int *A){

    int tmp;

    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;

}

void insert(int x, int *A, int *n){

    int n1;

    n1 = *n;
    if(n1 >= N){
        printf("Error: Priority queue A is full\n");
        exit(1);
    }
    A[n1] = x;  //新しい頂点を葉として追加
    upmax(n1, A, n1+1);     //ヒープの更新
    *n = n1 + 1;
    
}

void upmax(int i, int *A, int n){
    
    int j;
    if(i >= N){
        printf("Error: i is incorrect.\n");
        exit(1);
    }
    if(i == 0) return;
    
    j = (i - 1) / 2;
    if(A[i] > A[j]){
        swap(i, j, A);
        upmax(j, A, n);
    }
}

int deletemax(int *A, int *n){

    int max, n1;

    n1 = *n;
    if(n1 < 1){
        printf("Error: Priority queue is empty\n");
        exit(1);
    }
    max = A[0];         //後で出力するために最小値を保存
    A[0] = A[n1 - 1];   // 根に右端の葉の値を移動
    if(n1 > 1){
        downheapmax(0, A, n1-1);    //ヒープの更新
    }
    *n = n1 - 1;        //ヒープサイズの更新
    return max;
}

void downheapmax(int i, int *A, int n){

    int j;

    if(i >= N){
        printf("Error: i is incorrect\n");
    }
    j = 2*i + 1;
    if(j >= n) return;
    if(A[2*(i+1)] > A[j] && 2*(i+1) <= N){
        j = 2*(i+1);
    }
    if(A[i] < A[j]){
        swap(i, j, A);
        downheapmax(j, A, n);
    }
}

int main(void){

    int x;
    int queue_point = 0;
    int A[N+1];
    char s[2];

    init(A);
    printf("insert: i, delete: d\n");
    while(scanf("%1s", s) != EOF){
        switch (s[0]){
            case 'i':
            case 'I':
                printf("Input key\n");
                scanf("%d", &x);
                insert(x, A, &queue_point);
                break;
            case 'd':
            case 'D':
                printf("key:%d\n", deletemax(A, &queue_point));
                break;
        }
        printf("insert: i, delete: d\n");
    }

    return 0;

}