#include<stdio.h>
#include<stdlib.h>


struct node

{

    char info;

    struct node *left;

    struct node *right;


};

typedef struct node *NODE;


NODE newnode(char item)

{

    NODE temp;

    temp=(NODE)malloc(sizeof(struct node));

    temp->info=item;

    temp->left= NULL;
    temp->right= NULL;

    return temp;


}

int preced(char x)

{


    switch(x)

    {


    case '^': return 3;

    case '/':

    case '*':  return 2;

    case '+':

    case '-': return 1;


    }

return 0;

}

NODE createExpTree(char infix[15])

{


    int i=0;

    char symbol;



    NODE temp,t1,t2,t3;

    NODE operst[10],treest[10];

    int top1=-1,top2=-1;



    for(i=0;infix[i]!='\0';i++)

    {


        symbol=infix[i];

        if(isalnum(symbol))

        {

            temp=newnode(symbol);

            treest[++top2]=temp;

        }

        else

        {


            temp=newnode(symbol);

/*Symbol is a open bracket*/


            if(symbol=='(')

            operst[++top1]=temp;


/*If stack top is less precedence then push*/


            else if(top1 == -1 || preced (operst[top1]->info) < preced(symbol))

             operst[++top1]=temp;


/*If symbol is closing bracket*/


            else if(symbol == ')') {


 while((operst[top1]->info!='(')&&(top1!=-1) && (top2!=-1) && preced(operst[top1]->info) >= preced(symbol)) {


            t3= operst[top1--];

            t1=treest[top2--];

            t2=treest[top2--];

            t3->right=t1;

            t3->left=t2;

            treest[++top2] = t3;

            }


/*Remove opening brack*/

        if(operst[top1]->info=='(')

        top1--;

            }



            else

            {

            while((top1!=-1) && (top2!=-1) && preced(operst[top1]->info) >= preced(symbol)) {

            t3= operst[top1--];

            t1=treest[top2--];

            t2=treest[top2--];

            t3->right=t1;

            t3->left=t2;

            treest[++top2] = t3;

            }

            operst[++top1] = temp;

        }

    }

}

/*End of string*/

while(top1 != -1)

{


            t1=treest[top2--];

            t2=treest[top2--];

            temp=operst[top1--];

            temp->right=t1;

            temp->left=t2;

            treest[++top2]=temp;

}

return treest[top2];

}



void preorder(NODE root)

{

    if(root!=NULL)

    {

        printf("%c",root->info);

        preorder(root->left);

         preorder(root->right);

    }

}

void inorder(NODE root)

{

    if(root!=NULL)

    {

        inorder(root->left);

        printf("%c",root->info);

         inorder(root->right);

    }

}

void postorder(NODE root)

{

    if(root!=NULL)

    {

        postorder(root->left);

         postorder(root->right);

          printf("%c",root->info);

    }

}


int main()

{

    NODE root=NULL;

    char infix[15];

     printf("\n ENTER THE INFIX EXPRESSION\n");

     scanf("%s",infix);

     root= createExpTree(infix);

      printf("\nINFIX\n");

      inorder(root);

      printf("\nPOSTFIX\n");

      postorder(root);

      printf("\nPREFIX\n");

      preorder(root);

      return 0;

}
