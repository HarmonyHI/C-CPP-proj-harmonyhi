#include<bits/stdc++.h>
using namespace std;
bool sx(int a,int b)
{
	return a<b;
}
long long int findfirst(int *data,int n,int &temppos)
{
	for(int i=0;i<n;i++)
	if(data[i]!=0)
	{
		temppos=i;
		return data[i];
	}
	temppos=0;
	return 5;
}
long long int tickbest(int *data,int n,int type)
{
	cout<<"type"<<type<<endl;
	if(type==-1)
	{
		int temppos;
		int temp=abs(findfirst(data,n,temppos));
		for(int i=1;i<n;i++)
			if(data[i]==0)
			continue;
			else if(abs(data[i])>temp)
			{
				temp=abs(data[i]);
				temppos=i;
			}
		long long int ans=data[temppos];
		data[temppos]=0;
		cout<<"return "<<"data["<<temppos<<"]"<<ans<<endl;
		return ans;
	}
	else if(type==0)
	{
		int temppos;
		int temp=findfirst(data,n,temppos);
		for(int i=1;i<n;i++)
			if(data[i]==0)
			continue;
			else if(data[i]<temp)
			{
				temp=data[i];
				temppos=i;
			}
		long long int ans=data[temppos];
		data[temppos]=0;
		cout<<"return "<<"data["<<temppos<<"]"<<ans<<endl;
		return ans;
	}
	else
	{
		int temppos;
		int temp=findfirst(data,n,temppos);
		for(int i=1;i<n;i++)
			if(data[i]==0)
			continue;
			else if(data[i]>temp)
			{
				temp=data[i];
				temppos=i;
			}
		long long int ans=data[temppos];
		data[temppos]=0;
		cout<<"return "<<"data["<<temppos<<"]"<<ans<<endl;
		return ans;
	}
}
bool havezero(int *data,int n)
{
	for(int i=0;i<n;i++)
		if(data[i]==0)
		return true;
		return false;
}
int main()
{
	int n,k;
	int data[200000];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>data[i];
	sort(data,data+n,sx);
	bool havzero=havezero(data,n);
	long long int ans=1;
	for(int i=0;i<k;i++)
	ans=ans*tickbest(data,n,i==k-1?ans>0:-1);
	if(ans<0)
		ans=0-((0-ans)%1000000009);
	else
		ans=ans%1000000009;
	cout<<(havzero?0:ans);
}