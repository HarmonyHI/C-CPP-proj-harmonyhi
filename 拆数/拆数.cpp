#include<stdio.h>
int cifang(int p)
{
	int iin,ret=1;
	if(p==0)
	return 1;
	for(iin=1;iin<=p;iin++)
	ret=ret*10;
	return ret;
}
int main()
{	
	while(1)
	{
	int db[10]={0},ting,i;
	scanf("%d",&ting);
	if(ting==-1)
	return 0;
	for(i=0;i<10;i++)
	while(ting%cifang(i+1)>=cifang(i))
	{
		ting=ting-cifang(i);
		db[i]++;
	}
	for(i=9;i>=0;i--)
	if(db[i]!=0)
	break;
	for(;i>=0;i--)
	printf("%d\n",db[i]);
	}
 }
