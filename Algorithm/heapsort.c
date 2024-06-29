#include<stdio.h>
#include<stdlib.h>

//プロトタイプ宣言
void swap(int i, int j, int *A);
void downheapmax(int i, int *A, int n);
void heapsort(int *A, int n);
int pow2(int n);
void print_data(int *A, int n);
void print_heap(int *A, int n);

void swap(int i, int j, int *A){

    int tmp;

    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;

}

void downheapmax(int i, int *A, int n){

    int j;

    j = 2*i + 1;
    if(j >= n) return;
    if(A[2*(i+1)] > A[j] && 2*(i+1) <= n){
        j = 2*(i+1);
    }
    if(A[i] < A[j]){
        swap(i, j, A);
        downheapmax(j, A, n);
    }
}


void heapsort(int *A, int n){
    
    for(int j=n/2-1; j>=0; j--){
        downheapmax(j, A, n-1);
    }
    print_heap(A, n);
    for(int i=n-1; i>0; i--){
        print_heap(A, i);
        swap(0, i, A);
        downheapmax(0, A, i-1);
    }
}

int pow2(int n){

    int return_value = 1;
    for(int i=0; i<n; i++){
        return_value *= 2;
    }

    return return_value;
}

void print_data(int *A, int n){

    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void print_heap(int *A, int n){

    int i, w, level;
    int height = 1;     //木の高さ

    i = n;
    while((i = i/2) > 0) height++;
    i = 0;
    w = 1;
    for(level=0; level < height; level++){
        int k;
        printf("%*s", pow2(height-level)-2, "");
        for(k=0; k<w; k++){
            printf("%02d", A[i++]);
            if(i > n-1) goto Exit;
            printf("%*s", pow2(height-level+1)-2, "");
        }
        putchar('\n');
        printf("%*s", pow2(height-level)-3, "");
        for(k=0; k<w; k++){
            if(2*k + i < n) printf("／");
            if(2*k + i + 1 < n) printf("＼");
            printf("%*s", pow2(height-level+1)-4, "");
        }
        putchar('\n');
        w *= 2;
    }

Exit:
    putchar('\n');
    putchar('\n');
}

int main(void){

    int n;
    int A[100];
    int size_x = sizeof(A)/sizeof(A[0]);

    do{
        printf("要素数(1~%d)は : ", size_x);
        scanf("%d", &n);
    }while(n < 1 || n > size_x);
    printf("%d個の整数を入力せよ.\n", n);
    for(int i = 0; i < n; i++){
        printf("A[%d] :", i);
        scanf("%d", &A[i]);
    }
    heapsort(A, n);
    puts("昇順にソートしました.");
    print_data(A, n);
    return 0;
}