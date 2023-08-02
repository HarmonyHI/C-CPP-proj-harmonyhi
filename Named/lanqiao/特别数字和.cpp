#include<bits/stdc++.h>
using namespace std;
bool allz(char *s)
{
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]!='z')
		return false;
	}
	return true;
}
void pls(char *s)
{
	if(strlen(s)==0)
	{
		s[0]='a';
		s[1]=0;
	}
	else if(s[strlen(s)-1]<'z')
	{
		if(strlen(s)-1==0||s[strlen(s)-1]>s[strlen(s)-2])
		s[strlen(s)-1]='z';
		else
		s[strlen(s)-1]++;
	}
	else if(s[strlen(s)-1]=='z')
	{
		if(allz(s))
		{
			int length=strlen(s);
			for(int i=0;i<=length;i++)
			s[i]='a';
			s[length+1]=0;
		}
		else
		{
			s[strlen(s)-1]++;
			for(int i=strlen(s)-1;i>=0;i--)
			{
				if(s[i]>'z')
				{
					s[i]='a';
					s[i-1]++;
				}
			}
		}
	}
	else;
}
int mptest(char *s1)
{
	char s[200000];
	strcpy(s,s1);
	char t;
	int ans=0;
	for(int i=0;i<strlen(s);i++)
	{
		bool needp=false;
		for(int ii=0;ii<strlen(s)-1;ii++)
			if(s[ii]>s[ii+1])
			{
				needp=true;
				ans++;
				t=s[ii];
				s[ii]=s[ii+1];
				s[ii+1]=t;
			}
		if(needp==false)
		break;
	}
	return ans;
}
int main()
{
	int goal;
	cin>>goal;
	char s[200000];
	while(1)
	{
		pls(s);
		if(mptest(s)==goal)
		{
			cout<<s<<endl;
			return 0;
		}
		
	}
}