#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*start;

void create_list(int data){
    struct node *q,*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if(start==NULL){
        start=temp;
    }else{
        q=start;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next = temp;
    }

}

void  addfirst(int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = start;
    start=temp;
}



void addafter(int data, int pos){
    struct node *temp ,*q;
    int i;
    q=start;

    //Finding the postion to add new element into the linkedlist

    for(i=0;i<pos;i++){
        q=q->next;
        if(q==NULL){
            printf("\n There are less than %d elements",pos);
            return;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = q->next;
        q->next = temp;
    }
}

void reverse(){
    struct node *p1,*p2,*p3;
    if(start->next==NULL){
        return;
    }
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next = p1;
    while(p3!=NULL){
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
}


void display(){
    struct node *q;
    if(start == NULL){
        printf("\n List is empty");
        return;
    }
    q=start;
    printf("\nList is : ");
    while(q != NULL){
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}

int main(void)
{
     int node; 
    //createnode(node);
    int i,item, new;

    printf("Enter how many nodes you want : ");
    scanf("%d",&node);
        for ( i = 0; i < node; i++)
        {
            printf("Enter Value : ");
            scanf("%d",&item);
            create_list(item);
        }
        display();
        reverse();
        display();
        printf("Enter first Value : ");
            scanf("%d",&new);
        addfirst(new);
        display();

// return 0;

return 0;
}