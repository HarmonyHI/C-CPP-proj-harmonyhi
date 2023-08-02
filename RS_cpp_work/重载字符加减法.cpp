#include<iostream>
#include<string>
using namespace std;
char dealer(char a,int b)
{
	char temp;
	temp=a+b;
	while(temp>'z')
	temp=temp-26;
	while(temp<'a')
	temp=temp+26;
	return temp;
}
class Character
{
	public:
		char t;
		Character()
		{
		}
};
Character operator+(Character &a,int b)
{
	Character temp;
	temp.t=dealer(a.t,b);
	return temp;
}
Character operator-(Character &a,int b)
{
	Character temp;
	temp.t=dealer(a.t,-b);
	return temp;
}
istream &operator>>(istream &is,Character &a)
{
	is>>a.t;
}
ostream &operator<<(ostream &os,Character &a)
{
	os<<a.t;
}
int main()
{
    int cases, data;
    Character ch;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>ch;
        cin>>data;
        cout<<(ch+data)<<" "<<(ch-data)<<endl;
    }
}
