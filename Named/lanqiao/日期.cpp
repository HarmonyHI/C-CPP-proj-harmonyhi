#include<bits/stdc++.h>
using namespace std;
class date
{
	public:
	int y,m,d;
};
bool sx(date a,date b)
{
	if(a.y!=b.y)
	return a.y<b.y;
	if(a.m!=b.m)
	return a.m<b.m;
	if(a.d!=b.d)
	return a.d<b.d;
	return false;
	
}
bool run(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
	return true;
	return false;
}
int monthday(int y,int m)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	return 31;
	else if(m==2)
	{
		if(run(y))
		return 29;
		else
		return 28;
	}
	else
	return 30;
}
bool ill(date a)
{
	if(a.m>12||a.m<1||a.d<1)
	return false;
	if(a.d>monthday(a.y,a.m))
	return false;
	return true;
}
date tick[5];
void print(date tmp)
{
	static int ctr=0;
	if(ctr!=0)
	{
		if(tmp.y==tick[ctr-1].y&&tmp.m==tick[ctr-1].m&&tmp.d==tick[ctr-1].d)
		return;
	}
	tick[ctr].y=tmp.y;
	tick[ctr].m=tmp.m;
	tick[ctr].d=tmp.d;
	ctr++;
	if(tmp.y<60)
	printf("20%02d-%02d-%02d\n",tmp.y,tmp.m,tmp.d);
	else
	printf("19%02d-%02d-%02d\n",tmp.y,tmp.m,tmp.d);
}
int main()
{
	//容器及输入
	date a[3];
	char w;
	cin>>a[0].y>>w>>a[0].m>>w>>a[0].d;
	//三种可能
	a[1].y=a[0].d;
	a[1].m=a[0].y;
	a[1].d=a[0].m;
	a[2].y=a[0].d;
	a[2].m=a[0].m;
	a[2].d=a[0].y;
	//有序
	sort(a,a+3,sx);
	for(int i=0;i<3;i++)
	if(ill(a[i]))//合法
	print(a[i]);//去重
}