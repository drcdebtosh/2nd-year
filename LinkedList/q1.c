#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next,*prev;
}dl;
dl *start = NULL;

void create(int item){
    dl *p,*s;
    p=(dl*)malloc(sizeof(dl));
    p->data = item;
    p->next = NULL;
    p->prev = NULL;

    if(start==NULL){
        start=p;

    }else{
        s=start;
        while(s->next!=NULL){
            s=s->next;
        }
            p->prev=s;
            s->next=p;
    }
}

void insert_first(int item){
    dl *p;
    p=(dl*)malloc(sizeof(dl));
    p ->data=item;
    p->next=NULL;
    p->prev=NULL;
    p->next =start;
    start=p;
    (p->next)->prev=p;
}

int delete_last(){
    int x;
    dl *p;
    p=start;
    while(p->next!=NULL)
        p=p->next;
    
    x=p->data;
    (p->prev)->next=NULL;
    free(p);
    return x;

}

void search(int val){
    dl *s;
    int count=0,flag=0;
    s=start;
    while(s!=NULL){
        count++;
        if(s->data==val){
            printf("the item found in %d th node .",count);
            flag++;
            break;
        }
        s=s->next;
    }
    if(flag==0)
        printf("item is not present.\n");
}

void display(){
    dl *p;
    p=start;
    printf("The items are :\n");
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int main(void)
{
    int node,choice; 
    //createnode(node);
    int i,item,val;

    printf("Enter how many nodes you want : ");
    scanf("%d",&node);
        for ( i = 0; i < node; i++)
        {
            printf("Enter Value : ");
            scanf("%d",&item);
            create(item);
        }
    while(1){
        printf("\n1.insert at first\n2.delete at last\n3.Search any Item\n4.Display\n5.exit\n");
        printf("enter the choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: printf("Enter the Number :");
                scanf("%d",&val);
                insert_first(val);
                break;
        case 2: delete_last();
                break;
        case 3: printf("Enter the Number to search:");
                scanf("%d",&val);
                search(val);
                break;
        case 4: display();
                break;
        case 5: exit(1);
                break;                                
        }

    }

return 0;
}