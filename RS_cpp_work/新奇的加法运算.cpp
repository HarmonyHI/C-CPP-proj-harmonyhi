#include<iostream>
using namespace std;
int cifang(int a)
{
	int p=1;
	for(int i=1;i<=a;i++)
	p=p*10;
	return p;
}
void breakup(int ting,int *core)
{
	for(int i=0;i<12;i++)
	{
	core[i]=ting/cifang(i);
	core[i]=core[i]%10;
	}
}
class newInt
{
	public:
		int ting;
		int core[12];
		newInt(){
		}
		
 } ;
newInt operator+ (newInt &a,newInt &b)
{
	newInt s;
	for(int i=0;i<12;i++)
	{
		s.core[i]=a.core[i]+b.core[i];
		s.core[i]=s.core[i]%10;
	}
	return s;
}
istream &operator>>(istream &is,newInt &a)
{
	is>>a.ting;
	breakup(a.ting,a.core);
	return is;
}
ostream &operator<<(ostream &os,const newInt &a)
{
	int skip=1;
	for(int i=11;i>=0;i--)
	{
		if(a.core[i]!=0)
		skip=0;
		if(skip==0)
		os<<a.core[i];
}
	return os;
}
int main()
{
    int cases;
    newInt a, b, c;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>a>>b;
        c = a + b;
        cout<<a<<" + "<<b<<" = "<<c<<endl;
    }
    return 0;
}
