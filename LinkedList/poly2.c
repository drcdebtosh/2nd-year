#include<stdio.h>
#include<stdlib.h>

struct node{
    float coef;
    int expo;
    struct node *next;
    

}*start;
typedef struct node *poly;

poly insert(poly start,float co, int ex){
    poly ptr,temp;
    temp=(poly)malloc(sizeof(struct node));
    temp->coef = co;
    temp->expo = ex;
    // list empty or exp greater than first one

    if(start==NULL || ex>start->expo){
        temp->next = start;
        start=temp;
    }else{
        ptr= start;
        while(ptr->next!=NULL && ptr->next->expo > ex){
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        if(ptr->next == NULL){
            temp->next = NULL;
        }
    }
    return start;
}

poly enter(poly start){
    int i,n,ex;
    float co;
    printf("\n How many terms u want to enter: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("\n Enter coefficient for term %d:", i);
        scanf("%f",&co);
        printf("Enter exponent for term %d: ",i);
        scanf("%f",&ex);

        start = insert(start,co,ex);
    }

    return start;
}

void display(poly ptr){
    if(ptr == NULL){
        printf("\n Empty");
        return;
    }

    while(ptr!=NULL){
        printf("(%.1fx^%d)+",ptr->coef,ptr->expo);    
        ptr= ptr->next;
        }
        printf("\b\b \n");
}
int main(){

poly p1_start;

p1_start = NULL;

printf("\n Enter Plynnomial No 1: \n");
p1_start = enter(p1_start);

printf("Plynnomial No 1:\n");
display(p1_start);


    
return 0;
}