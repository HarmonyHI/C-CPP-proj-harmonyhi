#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
ull gcd(ull a,ull b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
class Fract
{
	public:
		ull mu,zi;
		Fract():mu(0),zi(0){}
		void in(ull z,ull m)
		{
			if(z==m);
			else if(mu==0&&zi==0)
			{
				mu=m;
				zi=z;
			}
			else
			{
				mu=gcd(mu,m);
				zi=gcd(zi,z);
			}
		}
		void outmin()
		{
			cout<<zi<<"/"<<mu<<endl;
		}
};
int main()
{
	int n;
	ull data[100000];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>data[i];
	sort(data,data+n);
	Fract f;
	for(int i=0;i<n-1;i++)
	f.in(data[i+1],data[i]);
	f.outmin();
}