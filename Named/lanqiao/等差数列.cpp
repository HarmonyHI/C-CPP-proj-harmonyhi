#include<bits/stdc++.h>
bool jx(int a,int b)
{
	return a>b;
}
using namespace std;
int main()
{
	int number[200000],symbol[200000];
	int N,M;
	cin>>N>>M;
	for(int i=0;i<(N+M+1);i++)
		cin>>number[i];
	sort(number,number+N+M+1,jx);
	int ctr=1;
	if(M>N)
	{
		int t=M;
		M=N;
		N=t;
	}
	int sum=number[0];
	for(int i=0;i<M;i++)
	sum=sum+number[ctr++];
	for(int i=0;i<N;i++)
	sum=sum-number[ctr++];
	cout<<sum;
}