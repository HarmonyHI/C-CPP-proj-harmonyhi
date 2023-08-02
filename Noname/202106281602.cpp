#include<stdio.h>
#include<string.h>
int main()
{
	int a,b;
	char c;
	while(1)
	{
		scanf("%d%c%d",&a,&c,&b);
		if((a==0)&&(b==0))break;
	else if(c=='+')printf("%d\n",a+b);
	else if(c=='-')printf("%d\n",a-b);
	else if(c=='*')printf("%d\n",a*b);
	else if(c=='/')printf("%d\n",a/b);
	else if(c=='%')printf("%d\n",a%b);
	else printf("invalid op\n");
	}
	
}
