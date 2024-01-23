#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next; 
}*start;

typedef struct node *Double;

void create(int num){
    Double q,temp;
    temp =(Double)malloc(sizeof(struct node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = NULL;

    if(start==NULL){
        start=temp;
    }
    else{
        q=start;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next = temp;
        temp->prev = q;
    }
}

void delete(int num){
    Double temp,q;
    if(start->data == num){
        temp=start;
        start =start->next;
    start->prev = NULL;
    free(temp);
    return;
    }
    q=start;
    while(q->next->next!= NULL){
        if(q->next->data == num){ // element in between
            temp=q->next;
            q->next = temp->next;
            temp->next->prev = q;
            free(temp);
            return;
        }
        q=q->next;
    }
    if(q->next->data == num){
        temp = q->next;
        free(temp);
        q->next=NULL;
        return;
    }
    printf("%d Element not found",num);
}

void display(){
    Double q;
    if(start==NULL){
        printf("\n List is Empty\n");
    }
    q=start;
    printf("\n List is : \n");
    while(q!=NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}
int main(){

int n,node,i;
start = NULL;

printf("\n How many nodes you want:");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("\n Enter the element:");
    scanf("%d",&node);
    //create linkedlist function is called
    create(node);
}

// delete
printf("\n Enter the element for delettion:");
scanf("%d",&node);
delete(node);

display();

    
return 0;
}