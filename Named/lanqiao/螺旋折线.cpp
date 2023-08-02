#include<bits/stdc++.h>
using namespace std;
bool sx(int a,int b)
{
	return a>b;
}
int main()
{
	int n,a[100005],b[100005],c[100005];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];	
	for(int i=0;i<n;i++)
	cin>>b[i];	
	for(int i=0;i<n;i++)
	cin>>c[i];	
	sort(a,a+n,sx);
	sort(b,b+n,sx);
	sort(c,c+n,sx);
	int ans=0;
	for(int i=0;i<n;i++)
	for(int ii=0;ii<n;ii++)
		if(a[i]<b[ii])
			for(int iii=0;iii<n;iii++)
			{
				if(b[ii]<c[iii])
				ans++;
				else
				break;
			}
		else
			break;
	cout<<ans;
	return 0;
}