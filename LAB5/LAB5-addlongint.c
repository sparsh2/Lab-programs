/*Write a C program to implement addition of long positive integers using circular single linked list with header node*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int num;
    struct node *next;
};

void insert(struct node* head, int digit)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next=ptr;
    ptr->num=digit;
    if(head->next==head)
    {
        head->next=ptr;
        ptr->next=head;
    }
    else
    {
        ptr->next=head->next;
        head->next=ptr;
    }
}

void add(struct node *num1, struct node *num2, struct node *res)
{
    int carry=0,sum,x,y;
    struct node *ptr, *p;
    if(num1->next==num1)
    {
        res->next=num2->next;
        ptr=num2->next;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=res;
    }
    else if(num2->next==num2)
    {
        res->next=num1->next;
        ptr=num1->next;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=res;
    }
    else
    {
        p=(struct node *)malloc(sizeof(struct node));
        struct node *ptr1, *ptr2;
        ptr1=num1->next;
        ptr2=num2->next;
        while(ptr1!=num1 || ptr2!=num2)
        {
            if(ptr1==num1)
            x=0;
            else
            x=ptr1->num;

            if(ptr2==num2)
            y=0;
            else
            y=ptr2->num;

            sum=x+y+carry;

            if(sum>=10)
            carry=1;
            else
            carry =0;

            insert(res, sum%10);
            if(ptr1!=num1)
            ptr1=ptr1->next;
            if(ptr2!=num2)
            ptr2=ptr2->next;
        }
        if(carry!=0)
        insert(res, 1);
    }
}


void display(struct node *res)
{
    struct node *ptr=res;
    ptr=ptr->next;
    while(ptr!=res)
    {
        printf("%d", ptr->num);
        ptr=ptr->next;
    }
}
int main()
{
    int i;
    struct node num1,num2,res;
    num1.next=&num1;
    num2.next=&num2;
    res.next=&res;
    char str[100];
    printf("Enter the first num: ");
    scanf("%s", str);
    for(i=0;i<strlen(str); i++)
    {
        insert(&num1, str[i]-'0');
    }
    printf("Enter the second num: ");
    scanf("%s", str);
    for(i=0;i<strlen(str); i++)
    {
        insert(&num2, str[i]-'0');
    }
    add(&num1,&num2,&res);
    display(&res);
}
