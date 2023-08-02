#include<bits/stdc++.h>
using namespace std;
int mp[9][9];
int black[9];
int white[9];
int n;
int ans=0;
bool big(int a,int b)
{
	return a<b;
}
bool avilable()
{
	
	for(int i=0;i<n;i++)
	if(white[i]==i||white[i]==n-i||mp[i][white[i]]==0)
	return false;
	
	int bkp[9];
	for(int i=0;i<n;i++)
	bkp[i]=white[i];
	
	sort(bkp,bkp+n,big);
	
	
	for(int i=0;i<n-1;i++)
	if(bkp[i]==bkp[i+1])
	return false;
	
	return true;
}
bool avilable1()
{
	for(int i=0;i<n;i++)
	if(black[i]==i||black[i]==n-i||mp[i][black[i]]==0||white[i]==black[i])
	return false;
	
	int bkp[9];
	for(int i=0;i<n;i++)
	bkp[i]=black[i];
	
	sort(bkp,bkp+n,big);
	
	
	for(int i=0;i<n-1;i++)
	if(bkp[i]==bkp[i+1])
	return false;
	
	return true;
}
bool findblack(int hang)
{
	if(hang==n)
		return avilable1();
	for(int i=0;i<n;i++)
	{
	black[hang]=i;
	findblack(hang+1);
	}
	return false;
}
void findwhite(int hang)
{
	if(hang==n)
	{
		if(avilable()&&findblack(0))
				ans++;
		return;
	}
	
	for(int i=0;i<n;i++)
	{
	white[hang]=i;
	findwhite(hang+1);
	}
	
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	for(int ii=0;ii<n;ii++)
	cin>>mp[i][ii];
	findwhite(0);
	findblack(0);
	cout<<ans;
}