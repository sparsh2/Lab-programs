#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

struct node{
  struct node *next;
  int co;
  int po;
};

struct linkedl
{
  struct node *head;
};

void insert_term(struct linkedl *poly, int co, int po)
{
  struct node *p=(struct node*)malloc(sizeof(struct node));
  p->co=co;
  p->po=po;
  p->next=NULL;
  if(poly->head==NULL)
  {
    poly->head=p;
  }
  else
  {
    struct node *ptr = poly->head;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
      if(ptr->po==po)
      {
        ptr->co=ptr->co+co;
        free(p);
        return;
      }
    }
    ptr->next=p;
  }
}

void input(struct linkedl *poly)
{
  int deg,i,co;
  printf("Enter the degree of polynomial: ");
  scanf("%d", &deg);
  for(i=deg;i>=0;i--)
  {
    printf("Enter the coeff for the power %d: ",i);
    scanf("%d",&co);
    insert_term(poly,co,i);
  }
}

void mul(struct linkedl *poly1, struct linkedl* poly2, struct linkedl* res)
{
  struct node *p1,*p2;
  for(p1=poly1->head;p1!=NULL;p1=p1->next)
  {
    for(p2=poly2->head;p2!=NULL;p2=p2->next)
    {
      insert_term(res, p1->co*p2->co,p2->po+p1->po);
    }
  }
}

void display(struct linkedl *poly)
{
  struct node *p=poly->head;
  while(p!=NULL)
  {
    printf("%dx^%d",abs(p->co),p->po);
    if(p!=NULL && p->next->co>=0)
    {
      printf(" + ");
    }
    else if(p!=NULL && p->next->co<0)
    {
      printf(" - ");
    }
    p=p->next;
  }
}

void delete(struct linkedl *l)
{
  struct node *p=l->head, *q;
  while(p!=NULL)
  {
    q=p->next;
    free(p);
    p=q;
  }
}

int main()
{
  struct linkedl poly1, poly2, res;
  poly1.head=poly2.head=res.head=NULL;
  input(&poly1);
  input(&poly2);
  mul(&poly1, &poly2, &res);
  display(&res);
  delete(&poly1);
  delete(&poly2);
  delete(&res);
}
