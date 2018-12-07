#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
  char arr[50];
  int top;
};

void push(struct stack *s, char ch)
{
  s->top++;
  s->arr[s->top]=ch;
}

char pop(struct stack *s)
{
  char ch;
  ch=s->arr[s->top];
  s->top--;
  return ch;
}

int precedence(char ch)
{
  if(ch=='$')
  return 3;
  if(ch=='*' || ch=='/')
  return 2;
  if(ch=='+' || ch=='-')
  return 1;
  return 0;
}

int main()
{
  int ch;
  char infix[50];
  struct stack s;
  s.top=-1;
  printf("Enter infix expression: ");
  scanf("%s", infix);
  for(int i=0;i<strlen(infix);i++)
  {
    if(isalnum(infix[i]))
    {
      printf("%c",infix[i]);
    }
    else
    {
      if(s.top==-1)
      {
        push(&s,infix[i]);
      }
      else if(infix[i]=='(')
      push(&s,'(');
      else if(infix[i]==')')
      {
        while(s.arr[s.top]!='(')
        {
          printf("%c",pop(&s));
        }
        ch=pop(&s);
      }
      else if(precedence(infix[i])>precedence(s.arr[s.top]))
      {
        push(&s,infix[i]);
      }
      else if(precedence(infix[i])<=precedence(s.arr[s.top]))
      {
        while(precedence(infix[i])<=precedence(s.arr[s.top]) && s.top!=-1)
        {
          printf("%c",pop(&s));
        }
        push(&s,infix[i]);
      }
    }
  }
  while(s.top!=-1)
  {
    printf("%c",pop(&s));
  }
  return 0;
}
