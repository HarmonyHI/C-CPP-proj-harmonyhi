#include<iostream>
using namespace std;
class Array
{
	public:
		Array():mems(NULL),length(0){}
		int length;
		int *mems;
 }; 
istream &operator>>(istream &is,Array &a)
{
	is>>a.length;
	a.mems=new int[a.length];
	for(int i=0;i<a.length;i++)
	is>>a.mems[i];
	return is;
}
ostream &operator<<(ostream &os,const Array &a)
{
	for(int i=0;i<a.length;i++)
	{
	os<<a.mems[i];
	if(i!=a.length-1)
	os<<" ";
	}
	return os;
}
int operator==(Array &a,Array &b)
{
	if(&a==&b)
	return 1;
	else
	{
		if(a.length==b.length)
		{
			for(int i=0;i<a.length;i++)
			if(a.mems[i]!=b.mems[i])
			{
				return 0;
			}
			return 1;
		}
		return 0;
	}
	
}

int main()
{
    int cases;
    cin>>cases;
    Array arraies[cases];
    for (int i = 0; i < cases; i++)
    {
        cin>>arraies[i];
    }
    cout<<arraies[0]<<endl;
    for (int i = 1; i < cases; i++)
    {
        if (arraies[i] == arraies[i - 1])
        {
            cout<<arraies[i]<<" "<<"equal to above."<<endl;
        }
        else
        {
            cout<<arraies[i]<<" "<<"unequal to above."<<endl;
        }
    }
    return 0;
}
