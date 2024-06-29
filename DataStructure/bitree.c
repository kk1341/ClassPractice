#include<stdio.h>
#include<stdlib.h>

typedef struct s_node{
    int key;
    struct s_node *left, *right;
} NODE;

NODE *newnode(void){

    NODE *p;

    p = (NODE *)malloc(sizeof(NODE));
    if(p == NULL){
        fputs("malloc failed\n", stderr);
        exit(1);
    }else{
        return p;
    }

}

NODE *insert(int k, NODE *pp){

    if(pp == NULL){
        pp = newnode();
        pp->key = k;
        pp->left = NULL;
        pp->right = NULL;
    }else{
        if(k < pp->key){
            pp->left = insert(k, pp->left);
        }
        if(k > pp->key){
            pp->right = insert(k, pp->right);
        }
    }

    return pp;

}

void print_tree(NODE *p, int h){

    int i;

    if(p != NULL){
        print_tree(p->right, h+1);
        for(i=1; i <= 3*h; ++i){
            printf(" ");
        }
        printf("%d\n", p->key);
        print_tree(p->left, h+1);
    }

}

int main(void){

    int key;
    NODE *p;

    p = NULL;
    printf("Input Number \n");
    while(scanf("%d", &key) != EOF){
        p = insert(key, p);
        printf("Input Number \n");
    }
    print_tree(p, 0);
    return 0;

}
