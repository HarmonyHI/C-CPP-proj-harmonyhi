#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		bool isPalindrome(int x){
			if(x<0)
			return false;
			int ctr=0;
			char temp1[100];
			while(x!=0)
			{
				temp1[ctr++]=x%10+'0';
				x=x/10;
			}
			temp1[ctr]=0;
			ctr=0;
			char temp2[100];
			for(int i=strlen(temp1)-1;i>=0;i--)
				temp2[ctr++]=temp1[i];
			temp2[ctr]=0;
			return !strcmp(temp1,temp2);
		}
};
int main()
{
	while(1)
	{
	Solution temp;
	int te;
	cin>>te;
	cout<<(temp.isPalindrome(te)?"true":"false")<<endl;	
	}
	
}
