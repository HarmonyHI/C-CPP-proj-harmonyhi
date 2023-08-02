#include<bits/stdc++.h>
using namespace std;
bool fun(int a,int b)
{
	if(a<b)
	return 1;
	else
	return 0;
}
int main()
{
	int n;
	cin>>n;
	int data[n];
	for(int i=0;i<n;i++)
	cin>>data[i];
	sort(data,data+n,fun);
	for(int i=0;i<n;i++)
	if(i!=0)
	cout<<" "<<data[i];
	else
	cout<<data[i];
 } 
