#include<stdio.h>
int main()
{
	char answer[100];
	char tinga;
	int num=0,sum=0,i=0;
	while(scanf("%c",&answer[sum])!=EOF)
	sum++;
	while(1)
	{
		scanf("%c",&tinga);
		if(tinga>='0'&&tinga<='9')
		num++;
		else
		{
		if(tinga=='.'&&num!=0)
		{
		printf("´ð°¸ÊÇ ¡¶%c¡· ",answer[i]);
		i++;	
		}
		num=0;	
		}
	}
}
