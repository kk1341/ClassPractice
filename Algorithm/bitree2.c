#include<stdio.h>
#include<stdlib.h>

typedef struct s_node{
    int key;
    struct s_node *left, *right;
} NODE;

//プロトタイプ宣言
NODE *newnode(void);
NODE *insert(int k, NODE *pp);
NODE *member(int k, NODE *pp);
void print_tree(NODE *p, int h);


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

NODE *member(int k, NODE *pp){

    if(pp == NULL){
        return NULL;
    }else if(k == pp->key){
        return pp;
    }else if(k < pp->key){
        return member(k, pp->left);
    }else{
        return member(k, pp->right);
    }
    
}

void result(int k, NODE *pp){

    if(pp == NULL){
        printf("%d is not found\n", k);
    }else{
        printf("%d is found\n", k);
    }

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
    char s[2];
    NODE *p = NULL;
    NODE *result_p;

    printf("insert: i, member: m\n");
    while(scanf("%1s", s) != EOF){
        switch (s[0]){
            case 'i':
            case 'I':
                printf("Input key\n");
                scanf("%d", &key);
                p = insert(key, p);
                break;
            case 'm':
            case 'M':
                printf("Input key\n");
                scanf("%d", &key);
                result_p = member(key, p);
                result(key, result_p);
                break;
        }
        printf("insert: i, member: m\n");
    }

    return 0;

}