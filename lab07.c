#include<stdio.h>
#define MAX_ITEMS 10
int KnapSack(int w,int wt[],int val[],int n);
int max(int a,int b);
int main()
{
int n,i,j,wt[50],val[50],maxcap;
printf("enter the no of values:");
scanf("%d",&n);
printf("enter the maximum capacity:");
scanf("%d",&maxcap);
printf("enter the weights:\n");
for(i=1;i<=n;i++)
{
scanf("%d",&wt[i]);
}
printf("enter the values:\n");
for(i=1;i<=n;i++)
scanf("%d",&val[i]);
printf("the maximum value is: %d\n",KnapSack(maxcap,wt,val,n));
return 0;
}
int KnapSack(int w,int wt[],int val[],int n)
{
int i,j;
int v[MAX_ITEMS+1][w+1];
for(i=0;i<=n;i++)
{
for(j=0;j<=w;j++)
{
if(i==0||j==0){
v[i][j]=0;
}
else if(j-wt[i]<0)
{
v[i][j]=v[i-1][j];
}
else
{
v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
}
}
}
return v[n][w];
}
int max(int a,int b)
{
return(a>b)?a:b;
}