#include<bits/stdc++.h>
using namespace std;
bool run(int y)
{
	return y%4==0&&y%100!=0||y%400==0;
}
int monthday(int y,int m)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	return 31;
	else if(m==2)
	{
		if(run(y))
		return 29;
		return 28;
	}
	return 30;
}
void plusdate(int &y,int &m,int &d)
{
	d++;
	if(d>monthday(y,m))
	{
		d=1;
		m++;
		if(m>12)
		{
			m=1;
			y++;
		}
		
	}
}
bool hui(int a,int b,int c)
{
	char tmp[20];
	int ctr=0;
	tmp[ctr++]=a/1000%10+'0';
	tmp[ctr++]=a/100%10+'0';
	tmp[ctr++]=a/10%10+'0';
	tmp[ctr++]=a%10+'0';
	tmp[ctr++]=b/10%10+'0';
	tmp[ctr++]=b%10+'0';
	tmp[ctr++]=c/10%10+'0';
	tmp[ctr++]=c%10+'0';
	tmp[ctr]=0;
	char ni[20];
	int ctr2=0;
	for(int i=ctr-1;i>=0;i--)
	ni[ctr2++]=tmp[i];
	ni[ctr2]=0;
	if(strcmp(ni,tmp)==0)
	return true;
	return false;
}
bool abab(int y,int m,int d)
{
	if((y/1000==(y%100/10))&&(y/1000==m%10)&&(y/1000==d%10)&&((y%10==y/100%10)&&(y%10==m/10)&&(y%10==d/10)))
	return true;
	return false;
}
int main()
{
	char tmp[20];
	cin>>tmp;
	int y,m,d;
	y=(tmp[0]-'0')*1000+(tmp[1]-'0')*100+(tmp[2]-'0')*10+(tmp[3]-'0');
	m=(tmp[4]-'0')*10+tmp[5]-'0';
	d=(tmp[6]-'0')*10+tmp[7]-'0';
	int ctr1=0,ctr2=0;
	while(ctr1==0||ctr2==0)
	{
		plusdate(y,m,d);
		if(hui(y,m,d)&&ctr1==0)
		{
			printf("%04d%02d%02d\n",y,m,d);
			ctr1++;
		}
		if(abab(y,m,d)&&ctr2==0)
		{
			printf("%04d%02d%02d\n",y,m,d);
			ctr2++;
		}
	}

	
	
}
