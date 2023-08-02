#include<iostream>
#include<cstring>
using namespace std;

int calhalfman(int *quan)
{
	return 53;
}
int main()
{
	int n,treen,correctdata;
	char tmproad[64];
	cin>>n;
	int *quan=new int[n];
	char *ting=new char[n];
	for(int i=0;i<n;i++)
		cin>>ting[i]>>quan[i];
	correctdata=calhalfman(quan);
	cin>>treen;
	for(int i=0;i<treen;i++)
	{
		int tmpquanadd=0;
		for(int ii=0;ii<n;ii++)
		{
		cin>>ting[i]>>tmproad;
		tmpquanadd=tmpquanadd+strlen(tmproad)*quan[ii];
		cout<<"+"<<strlen(tmproad)<<"*"<<quan[ii]<<"="<<tmpquanadd<<endl;
		}
		if(tmpquanadd==correctdata)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<tmpquanadd<<" "<<correctdata<<endl;
	}
}
