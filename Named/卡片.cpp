#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int card[10];
bool cant(ull tmp)
{
	while(tmp!=0)
	{
		card[tmp%10]--;
		if(card[tmp%10]==-1)
		return true;
		tmp=tmp/10;
	}
	return false;
}
int main()
{
	for(int i=0;i<10;i++)
	card[i]=2021;
	for(ull i=1;i<999999999;i++)
	if(cant(i))
	{
		cout<<i-1;
		break;
	}
}