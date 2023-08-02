#include<stdio.h>
#include<ctype.h>
#include<math.h>
int isrun(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	return 1;
	return 0;
}
int daymonth(int month,int year)
{
	//printf("ss\n");
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	return 31;
	else
	{
		if(month==2)
		{
			if(isrun(year)==1)
			return 29;
			return 28;
		}
		return 30;
	}
}
int Isleagle(int year,int mon,int day)
{
	if(day>daymonth(mon,year)||mon>12||day<1||mon<1||year<1)
	return 0;
	return 1;
}
int cal(int year,int mon,int day)
{
	int ting=0;
	for(int i=1;i<mon;i++)
	ting=ting+daymonth(i,year);
	ting=ting+day;
	return ting;
}
int main()
{
	int n,year,mon,day;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d-%d-%d",&year,&mon,&day);
		if(Isleagle(year,mon,day)==0)
		printf("error date!\n");
		else
		printf("%d\n",cal(year,mon,day));
	}
}
