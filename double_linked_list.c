#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct dlinklist
{
struct dlinklist *left;
int data;
struct dlinklist *right;
};

typedef struct dlinklist node;
node *start = NULL,*newnode,*temp;
node* getnode()
{
newnode = (node *) malloc(sizeof(node));
printf("\n Enter data: ");
scanf("%d", &newnode -> data);
newnode -> left = NULL;
newnode -> right = NULL;
return newnode;
}
void createlist( int n)
{
int i;
for(i = 0;i<n; i++)
{
newnode = getnode();
if(start == NULL)
{
start = newnode;
}
else
{
temp = start;
while(temp -> right)
temp = temp -> right;
temp -> right = newnode;
newnode->left = temp;
}
}
}
void insert_begin()
{
newnode=getnode();
if(start==NULL)
start=newnode;
else
{
newnode -> right = start;
start -> left = newnode;
start = newnode;
}
}
void insert_end()
{
newnode=getnode();
if(start==NULL)
start=newnode;
else
{
temp = start;
while(temp -> right != NULL)
temp = temp -> right;
temp -> right = newnode;
newnode -> left = temp;
}
}
void insert_middle()
{
int cnt=0,pos;
printf("Enter position");
scanf("%d",&pos);

newnode=getnode();
temp=start;
while(cnt<pos-1)
{
temp=temp->right;
cnt+=1;
}
newnode -> left = temp;
newnode -> right = temp -> right;
temp -> right -> left = newnode;
temp -> right = newnode;
}


void delete_begin()
{

if(start==NULL)
printf("List empty");
else
{
temp = start;
start = start -> right;
start -> left = NULL;
free(temp);
printf("\n node deleted..");
}
}
void delete_end()
{

if(start==NULL)
printf("List empty");
else
{
temp = start;
while(temp -> right != NULL)
{
temp = temp -> right;
}
temp -> left -> right = NULL;
free(temp);
printf("\n node deleted..");
}
}
void delete_middle()
{
int i,pos;
printf("Enter position");
scanf("%d",&pos);


temp = start;
i = 1;
while(i < pos)
{
temp = temp -> right;
i++;
}
temp -> right -> left = temp -> left;
temp -> left -> right = temp -> right;
free(temp);
printf("\n node deleted..");

}
void traverse()
{
temp = start;
while(temp != NULL)
{
printf("\n%d\t",temp -> data);
temp = temp -> right;
}

}

int menu()
{
int ch;
//clrscr();
printf("\n 1.Create");
printf("\n	");
printf("\n 2. Insert a node at beginning ");
printf("\n 3. Insert a node at end");
printf("\n 4. Insert a node at middle");
printf("\n	");
printf("\n 5. Delete a node from beginning");
printf("\n 6. Delete a node from Last");
printf("\n 7. Delete a node from Middle");
printf("\n	");
printf("\n 8. Traverse the list from Left to Right ");
printf("\n 9. Traverse the list from Right to Left ");
printf("\n	");
printf("\n 10.Count the Number of nodes in the list");
printf("\n 11.Exit ");
printf("\n\n Enter your choice: ");
scanf("%d", &ch);
return ch;
}

void main(void)
{
int ch, n;
//clrscr();
while(1)
{
ch = menu();
switch( ch)
{
case 1 :
    printf("\n Enter Number of nodes to create: ");
    scanf("%d", &n);
    createlist(n);
    printf("\n List created.."); break;
case 2 :
    insert_begin(); break;
case 3 :
    insert_end(); break;
case 4 :
    insert_middle(); break;
case 5 :
    delete_begin(); break;
case 6 :
    delete_end(); break;
case 7 :
    delete_middle(); break;
case 8 :
    traverse(); break;
case 11:
    exit(0);
}
    getch();
}
}

