#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct s_cbox {
    int num;
    char name[20];
    struct s_cbox *next;
} CBOX;

int main(void);
void listprint(CBOX *tail);
CBOX *makelist(void);
CBOX *newcbox(void);

int main(void){

    CBOX *p;

    p = makelist();
    listprint(p);

    return 0;
}

CBOX *makelist(void){

    CBOX *tail, *new;
    char d[20];
    int n;

    tail = NULL;
    n = 0;

    while(n >= 0){

        printf("Input ID-number\n");
        scanf("%d", &n);

        if(n < 0) continue;

        printf("Input Nanme\n");
        scanf("%19s", d);

        new = newcbox();
        new->num = n;
        strcpy(new->name, d);
        new->next = tail;
        tail = new;
    }

    return tail;

}

void listprint(CBOX *tail){
    
    CBOX *this;

    this = tail;
    while(this != NULL){
        printf("%d, %s \n", this->num, this->name);
        this = this->next;
    }

}

CBOX *newcbox(void){

    CBOX *p;

    p = (CBOX *)malloc(sizeof(CBOX));
    if(p == NULL){
        fputs("malloc failed\n", stderr);
        exit(1);
    }else{
        return p;
    }

}