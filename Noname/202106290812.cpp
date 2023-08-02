#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int main()
{
	int n,i,ii;
	int *a;
	scanf("%d",&n);
	a=(int*)malloc(n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(ii=0;ii<(n-1);ii++)
	for(i=0;i<(n-1);i++)
	{
		if(a[i]>a[i+1])
		swap(a+i,a+i+1);
	}
		for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
 } 
