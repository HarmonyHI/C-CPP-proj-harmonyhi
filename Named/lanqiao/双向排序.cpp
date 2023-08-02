#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int data;
	cin>>data;
	data=data/1000;
	int h,m,s;
	s=data%60;
	m=(data/60)%60;
	h=(data/3600)%24;
	printf("%02d:%02d:%02d",h,m,s);
}
