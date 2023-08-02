#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int data[20];
	for(int in=0;in<n;in++)
	cin>>data[in];
	int ans=0;
	
	for(int i=0;i<n-1;i++)
	for(int ii=i+1;ii<n;ii++)
	{
		for(int iii=0;iii<n-1;iii++)
		for(int iiii=iii+1;iiii<n;iiii++)
		if(iii==i||iii==ii||iiii==i||iiii==ii)
		cout<<"debug1 "<<i<<ii<<iii<<iiii<<endl;
		else if(data[i]+data[ii]==data[iii]+data[iiii])
		ans++;
		else
		cout<<"debug2 "<<i<<ii<<iii<<iiii<<endl;
	}
	
	cout<<ans;
}