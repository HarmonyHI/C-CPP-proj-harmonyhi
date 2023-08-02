#include<bits/stdc++.h>
using namespace std;
typedef int TPE;
class sto
{
	public:
		TPE data[200000];
		int ctr;
		sto():ctr(0){};
		void clear()
		{
			for(int i=0;i<ctr;i++)
			data[i]=0;
			ctr=0;
		}
		int yxinput(TPE c)
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
int main()
{
	
}