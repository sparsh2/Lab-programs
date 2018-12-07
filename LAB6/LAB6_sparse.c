#include<stdio.h>
#include<stdlib.h>

struct node{
  int row,col,val;
  struct node *next,*prev;
};

struct node * getnode()
{
  struct node *t;
  t=(struct node *)malloc(sizeof(struct node));
  t->next=t->prev=NULL;
  return t;
}

int main()
{
  int m,n,value,t,row,col;
  struct node *head=NULL,*temp;
  printf("Enter the order of the matrix: ");
  scanf("%d %d", &m,&n);
  printf("\nEnter the no of values to be stored in the matrix: ");
  scanf("%d", &t);
  for(int i=0;i<t;i++)
  {
    scanf("%d %d %d",&row,&col,&value);
    temp=getnode();
    temp->row=row;
    temp->col=col;
    temp->val=value;
    if(head==NULL)
    {
      head=temp;
    }
    else
    {
      temp->next=head->next;
      if(head->next!=NULL)
      head->next->prev=temp;
      head->next=temp;
      temp->prev=head;
    }
  }
  printf("\nMatrix: \n\n");
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      temp=head;
      while(temp)
      {
        if(temp->row==i &&temp->col==j)
        {
          printf("%d ", temp->val);
          break;
        }
        temp=temp->next;
      }
      if(temp==NULL)
      printf("0 ");
    }
    printf("\n");
  }
}
