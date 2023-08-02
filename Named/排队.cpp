#include<bits/stdc++.h>
using namespace std;
bool notequal(int *data,int n)
{
	for(int i=0;i<n;i++)
	if(data[i]!=data[0])
	return true;
	return false;
}
int main()
{
	int data[50000];
	int change[50000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>data[i];
	int ans=0;
	while(notequal(data,n))
	{
	for(int i=1;i<n;i++)
	change[i]=data[i-1]/2-data[i]/2;
	change[0]=data[n-1]/2-data[0]/2;
	for(int i=0;i<n;i++)
	{
		data[i]+=change[i];	
		if(data[i]%2==1)
		{
			data[i]++;
			ans++;
		}
	}
	}
	cout<<ans;
}