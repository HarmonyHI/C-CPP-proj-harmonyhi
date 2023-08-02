#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,i,q=0;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		if((i%b==0)||(i%c==0))
		if((i%b==0)&&(i%c==0));
		else
		{
			if(q!=0)
			printf(" ");
			printf("%d",i);
			q++;
		}
	}
}
