#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct node{
    int front,rear;
    int arr[SIZE];
}Queue;

void intialize(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue){
    return(queue->front == -1);
}

int isFull(Queue *queue){
    return((queue->rear +1)% SIZE == queue->front);
}

void enqueue(Queue *queue, int value){
    if(isFull(queue)){
        printf("Queue is Full");
        return;
    }

    if(isEmpty(queue)){
        printf("Queue is Empty");
        queue->front = 0;
    }

    queue->rear = (queue->rear +1)%SIZE;
    queue->arr[queue->rear]= value;

    printf("%d enqueued to the queue.\n",value);
}

int dequeue(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is Empty cannot dequeue\n");
        return -1;
    }

    int value = queue->arr[queue->front];

    if(queue->front == queue->rear){
        intialize(queue);
    }else{
        queue->front = (queue->front +1)%SIZE;
    }

    printf("%d dequeued from the queue.\n");
    return value;
}

void display(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is Empty");
    }

    printf("Queue elements: ");
    int i = queue->front;
    do{
        printf("%d ",queue->arr[i]);
        i = (i+1)%SIZE;

    }while(i!=(queue->rear +1)%SIZE);
    printf("\n");
}
int main(){
    
    Queue queue;
    intialize(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    display(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display(&queue);

    enqueue(&queue, 6);
    enqueue(&queue, 7);

    display(&queue);
return 0;
}