#include<stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *left;
  struct node *right;
};

struct node *inordersuccessor(struct node *root)
{
  while(root->left!=NULL)
  {
    root=root->left;
  }
  return root;
}

struct node * deleteb(struct node *root, int key)
{
  struct node *temp;
  if(root==NULL)
  return root;
  if(key<root->info)
  root->left=deleteb(root->left, key);
  else if(key>root->info)
  root->right=deleteb(root->right, key);
  else
  {
    if(root->right==NULL)
    {
      temp=root->left;
      free(root);
      return temp;
    }
    if(root->left==NULL)
    {
      temp=root->right;
      free(root);
      return temp;
    }
    temp=inordersuccessor(root->right);
    root->info=temp->info;
    root->right=deleteb(root->right, temp->info);
  }
  return root;
}

struct node * insert(struct node *root, int key)
{
  if(root==NULL)
  {
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    temp->info=key;
    return temp;
  }
  else
  {
    if(key<root->info)
    {
      root->left=insert(root->left, key);
    }
    else if(key>root->info)
    {
      root->right=insert(root->right, key);
    }
    return root;
  }
}

void inorder(struct node *root)
{
  if(root)
  {
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
  }
}

void preorder(struct node *root)
{
  if(root)
  {
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root)
{
  if(root)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->info);
  }
}

int main()
{
  struct node *root=NULL;
  int ch,ele;
  while(1)
  {
    printf("\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\nEnter choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1:
      printf("Enter the element: ");
      scanf("%d", &ele);
      root=insert(root, ele);
      break;

      case 2:
      printf("Enter the element: ");
      scanf("%d", &ele);
      root=deleteb(root, ele);
      break;

      case 3:
      inorder(root);
      break;

      case 4:
      preorder(root);
      break;

      case 5:
      postorder(root);
      break;

      case 6:
      exit(0);
      break;
    }
  }
}
