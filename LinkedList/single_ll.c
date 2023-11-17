#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}ll;
ll* start = NULL;

void create(int item){
    ll *p,*s;
    p=(ll*)malloc(sizeof(ll));
    p->data = item;
    p->next = NULL;
    
    if(start==NULL){
        start = p;
        
    }else{
        s=start;
        while(s->next!=NULL){
            s=s->next;
        }
            s->next=p;
    }
}

void createnode(int node){
    // int i,item;

    // printf("Enter how many nodes you want : ");
    // scanf("%d",node);
    //     for ( i = 0; i < node; i++)
    //     {
    //         printf("Enter Value : ");
    //         scanf("%d",&item);
    //         create(item);
    //     }
        
}

void display(){
    ll *p;
    p=start;

    while (p!=NULL)
    {
        printf("\n%d ",p->data );
        p=p->next;
    }
    
    
}
int main(void)
{
    int node; 
    //createnode(node);
    int i,item;

    printf("Enter how many nodes you want : ");
    scanf("%d",&node);
        for ( i = 0; i < node; i++)
        {
            printf("Enter Value : ");
            scanf("%d",&item);
            create(item);
        }
    display();

return 0;
}