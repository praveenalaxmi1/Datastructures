#include<stdio.h>
void main()
{
int bin[20],dec,rem,top=0;
printf("Enter decimal no");
scanf("%d",&dec);
while(dec>0)
{
rem=dec%2;
bin[top++]=rem;
dec=dec/2;
}
printf("Binary no=");
while(top>0)
{
printf("%d",bin[--top]);
}
}
