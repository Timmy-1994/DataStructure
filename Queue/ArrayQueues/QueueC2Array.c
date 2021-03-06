#include<stdio.h>
#include<stdlib.h>

#define Qsize 6

void enqueue(int* q);
void dequeue(int* q);
void listQueue(int* q);

int front= 0;
int rear= 0;
int flag = 0;

int main(void){
    int select;
    int queue[Qsize]={0}; //array items initail = 0
    while(1){
        printf("\n*******************\nQueue size is %d\n(0)enqueue\n(1)dequeue\n(2)List Queue\n",Qsize-1);
        scanf("%d",&select);
        switch(select){
            case 0:
                enqueue(queue);
                break;
            case 1:
                dequeue(queue);
                break;
            case 2:
                listQueue(queue);
                break;
            default:
                printf("\nerr format\n");
        }
    }
}

void enqueue(int* q){
    if(rear==front&&flag==1){
        printf("Queue is full\n");
    }else{
        int value;
        printf("value?\n");
        scanf("%d",&value);
        rear=(rear+1)%(Qsize-1);
        q[rear]=value;
        if(rear==front){
            flag = 1;
        }
    }
}
void dequeue(int* q){
    if(rear==front&&flag==0){
        printf("Queue is empty\n");
    }else{
        front=(front+1)%(Qsize-1);
        printf("dequeue %d\n",q[front]);
        if(rear==front){
            flag = 0;
        }
    }
}

void listQueue(int* q){
    int cnt=0;
    while(cnt<Qsize){
        if(q[cnt]==0){
            printf("(%d) empty",cnt);
        }else{
            printf("(%d) %d",cnt,q[cnt]);
        }
        if(rear==cnt){
            printf(" (rear) ");
        }
        if(front==cnt){
            printf(" (front) ");
        }
        printf(" ; ");
        cnt++;
    }
}