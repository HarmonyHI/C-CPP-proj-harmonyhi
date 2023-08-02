#include<bits/stdc++.h>
using namespace std;
int sumit(int *data,int a,int b)
{
	int sum=0;
	for(int i=a;i<=b;i++)
	sum=sum+data[i];
	return sum;
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	int ctr=0;
	int data[n+5];
	for(int i=0;i<n;i++)
	cin>>data[i];
	for(int i=0;i<n;i++)
	for(int ii=i;ii<n;ii++)
	if(sumit(data,i,ii)%k==0)
		ctr++;
	cout<<ctr;
}
