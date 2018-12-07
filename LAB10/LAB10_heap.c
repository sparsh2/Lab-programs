#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

int n=0;
int arr[SIZE+1];

void swap(int *x, int *y)
{
  int temp;
  temp=*y;
  *y=*x;
  *x=temp;
}

void heapify(int i)
{
  int largest = i;
  int right=2*i+1;
  int left=2*i;
  if(left<=n && arr[largest]<arr[left])
  {
    largest=left;
  }
  if(right<=n && arr[largest]<arr[right])
  {
    largest=right;
  }
  if(largest!=i)
  {
    swap(&arr[i],&arr[largest]);
    heapify(largest);
  }
}

void insert(int a)
{
  int index;
  if(n+1>SIZE)
  {
    printf("\nHeap overflow!");
    return;
  }
  n++;
  index=n;
  arr[index]=a;
  while(index!=1 && arr[index/2]<a)
  {
    swap(&arr[index/2],&arr[index]);
    index/=2;
  }
  printf("\nHeap after inserted: ");
  for(int i=1;i<=n;i++)
  {
    printf("%d ",arr[i]);
  }

}

int delete()
{
  if(n==0)
  {
    printf("\nHeap is empty");
    return -1;
  }
  swap(&arr[1],&arr[n]);
  n--;
  heapify(1);
  return arr[n+1];
}

void createheap()
{
  for(int i=n/2;i>=1;i--)
  {
    heapify(i);
  }
}

int main()
{
  int ch,ele;
  while(1)
  {
    printf("\n1.Create heap\n2.Delete\n3.Insert\n4.exit\nEnter choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("Enter the value of n: ");
        scanf("%d",&n);
        printf("\nEnter elements: \n");
        for(int i=1;i<=n;i++)
        {
          scanf("%d",&arr[i]);
        }
        createheap();
        printf("\nAfter heapified: ");
        for(int i=1;i<=n;i++)
        {
          printf("%d ",arr[i]);
        }
        break;
      case 2:
        ele=delete();
        if(ele!=-1)
        {
        printf("The value deleted is %d\nHeap after deletion: ",ele);
        for(int i=1;i<=n;i++)
        {
          printf("%d ",arr[i]);
        }
        }
        break;
      case 4:
        exit(0);
        break;
      case 3:
        printf("\nEnter the element: ");
        scanf("%d",&ele);
        insert(ele);
        break;
    }
  }
}
