#include<stdio.h>
void transfer(int n,char s,char t,char d)
{
 if(n==0)
 return;
 transfer(n-1,s,d,t);
 printf("Move disc %d from %c to %c\n",n,s,d);
 transfer(n-1,t,s,d);
}
void main()
{
 int n;
 printf("Enter the number of discs:\n");
 scanf("%d",&n);
 transfer(n,'A','B','C');
}