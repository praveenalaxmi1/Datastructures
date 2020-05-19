#include<stdio.h>
#include<stdlib.h>
struct lnode
{
int data;
struct lnode *next;
};
typedef struct lnode node;
node *first=NULL,*temp,*newnode;

node* getnode()
{
newnode=(node *)malloc(sizeof(node));
printf("Enter data:");
scanf("%d",&newnode->data);
newnode->next=NULL;
return newnode;
}
void createlist()
{
int n,i;
printf("Enter no.of values in list");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
if(first==NULL)
first=getnode();
else
{
temp=first;
while(temp->next!=NULL)
temp=temp->next;
temp->next=getnode();
}
}
}
void reverseprint()
{
node  *last=NULL;
while(last!=first)
{
temp=first;  // start every time from begining
while(temp->next!=last)   // move upto previous last node
{
temp=temp->next;  // move the temp to next node
}
printf("%d\t",temp->data); // display present temp node data
last=temp;   // assign temp as present last node
}
}

void  main()
{
createlist();
reverseprint();
}
