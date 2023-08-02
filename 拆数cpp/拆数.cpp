#include<iostream>
using namespace std;
int cifang(int p)
{
	int iin,ret=1;
	if(p==0)
	return 1;
	for(iin=1;iin<=p;iin++)
	ret=ret*10;
	return ret;
}
void breakup (int ting,int *db) 
{	
	int i;
	for(i=0;i<10;i++)
	db[i]=0;
	for(i=0;i<10;i++)
	while(ting%cifang(i+1)>=cifang(i))
	{
		ting=ting-cifang(i);
		db[i]++;
	}
 }
int main()
{
	int array[10];
	int number,i;
	cin>>number;
	breakup(number,array);
	for(i=9;array[i]==0;i--);
	for(;i>=0;i--)
	cout<<array[i];
}
