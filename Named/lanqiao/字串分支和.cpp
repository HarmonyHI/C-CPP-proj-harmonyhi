#include<bits/stdc++.h>
using namespace std;
char st[200000];
class sto
{
	public:
		char data[200000];
		int ctr;
		sto():ctr(0){};
		void clear()
		{
			for(int i=0;i<ctr;i++)
			data[i]=0;
			ctr=0;
		}
		int yxinput(char c)
		{
			if(ctr==0)
			{
				data[ctr++]=c;
				return 1;
			}
			else
			{
				for(int i=0;i<ctr;i++)
				if(data[i]==c)
				return 0;
				data[ctr++]=c;
				return 1;
			}
		}
};
sto box;
int main()
{
	cin>>st;
	int ans=0;
	int temp;
	for(int i=0;i<strlen(st);i++)
	{
	box.clear();
	temp=0;
	for(int ii=i;ii<strlen(st);ii++)
	{
		temp+=box.yxinput(st[ii]);
		ans+=temp;
	}
	}
	cout<<ans;
}