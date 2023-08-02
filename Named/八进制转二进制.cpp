#include<bits/stdc++.h>
using namespace std;
void translate(char c,string &s)
{
	if(c>='a'&&c<='z')
	c=c-'a'+'A';
	if(c=='0')
	s="0000";
	else if(c=='1')
	s="0001";
	else if(c=='2')
	s="0010";
	else if(c=='3')
	s="0011";
	else if(c=='4')
	s="0100";
	else if(c=='5')
	s="0101";
	else if(c=='6')
	s="0110";
	else if(c=='7')
	s="0111";
	else if(c=='8')
	s="1000";
	else if(c=='9')
	s="1001";
	else if(c=='A')
	s="1010";
	else if(c=='B')
	s="1011";
	else if(c=='C')
	s="1100";
	else if(c=='D')
	s="1101";
	else if(c=='E')
	s="1110";
	else if(c=='F')
	s="1111";
	else;
}
char twotoeight(string &s,int pos)
{
	return (s[0+pos]-'0')*4+(s[1+pos]-'0')*2+(s[2+pos]-'0')*1+'0';
}
void trans(string &s)
{
	string ejz;
	int ctr=0;
	string temp;
	for(int i=0;i<s.length();i++)
	{
		translate(s[i],temp);
		ejz+=temp;
	}
	int buling=ejz.length()%3==0?0:3-ejz.length()%3;
	if(buling%3==1)
	ejz.insert(0,"0");
	else if(buling%3==2)
	ejz.insert(0,"00");
	else;
	s.clear();
	for(int i=0;i<ejz.length();i=i+3)
	{
		s+=twotoeight(ejz,i);
		ctr++;
	}
	for(int i=0;i<3;i++)
	if(s[0]=='0')
	s.erase(0,1);
	else
	break;
}
int main()
{
	int n;
	cin>>n;
	string data;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		trans(data);
		cout<<data<<endl;
	}
	return 0;
}