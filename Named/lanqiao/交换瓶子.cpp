#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int gz=n;
	while(1)
	{
		n+=gz/3;
		int newg=gz/3;
		gz=gz%3;
		gz+=newg;
		if(gz<3)
		break;
	}
	cout<<n;
}