#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int x=-1;

struct queue{
    int front;
    int rear;
    char *msg[SIZE];
};

void cqenqueue(struct queue* q, char *s)
{
    if(q->rear==-1 && q->front==-1)
    {
        q->rear=q->front=0;
        q->msg[q->rear]=s;
        printf("\nMessage sent\n");
        x++;
    }
    else if((q->rear+1)%SIZE == q->front)
    {
        printf("\nQueue is full!\n");
    }
    else
    {
        q->rear=(q->rear+1)%SIZE;
        q->msg[q->rear]=s;
        printf("\nMessage sent\n");
        if(q->rear>x)
        x=q->rear;
    }
}

char* cqdequeue(struct queue* q)
{
    if(q->rear==-1 && q->front==-1)
    {
        printf("\nQueue is empty!\n");
        return NULL;
    }
    else if(q->rear==q->front)
    {
        char* s=q->msg[q->front];
        q->front=q->rear=-1;
        return s;
    }
    else
    {
        char *s=q->msg[q->front];
        q->front=(q->front+1)%SIZE;
        return s;
    }
}

void display(struct queue *q)
{
    int i;
    if(q->front==-1 && q->rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else if(q->front<=q->rear)
    {
        printf("\n");
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%s\n", q->msg[i]);
        }
    }
    else
    {
        printf("\n");
        for(i=q->front;i<SIZE;i++)
        {
            printf("%s\n", q->msg[i]);
        }
        for(i=0;i<=q->rear;i++)
        {
            printf("%s\n", q->msg[i]);
        }
    }
}

void freeq(struct queue *q)
{
    int i;
    char *str;
    printf("%d", x);
    if(x==-1)
    {
        return;
    }
    for(i=0;i<=x;i++)
    {
        str=q->msg[i];
        free(str);
    }
}

int main()
{
    int ch,i;
    char *str, *s;
    struct queue q;
    q.front=q.rear=-1;
    while(1)
    {
        printf("\n1.Send\n2.Receive\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            if((q.rear+1)%SIZE!=q.front)
            {
                str=(char *)malloc(50*sizeof(char));
                scanf("%s", str);
                cqenqueue(&q, str);
            }
            break;

            case 2:
            s=cqdequeue(&q);
            if (s!=NULL)
            printf("\nReceived message is: %s",s);
            break;

            case 3:
            display(&q);
            break;

            case 4:
            freeq(&q);
            exit(0);
        }
    }
}
