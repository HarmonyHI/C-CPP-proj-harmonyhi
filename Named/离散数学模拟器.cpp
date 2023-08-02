#include<bits/stdc++.h>
using namespace std;
bool youjian(bool a,bool b)
{
	if(a&&!b)
	return false;
	return true;
}
bool shjian(bool a,bool b)
{
	return a==b;
}
int main()
{
	bool p,q,r;
	while(1)
	{
	cin>>p>>q>>r;
	cout<<shjian(p&&q,r)<<endl;	
	}
	
}