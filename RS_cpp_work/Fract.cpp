#include<iostream>
#include<iomanip>
#include <cstdio>
#include<cmath>
using namespace std;
int fun(int a,int b)
{
	if(b==0)
	return a;
	return fun(b,a%b);
}
void deal(int &a,int &b)
{
	int pub=fun(a,b);
	a=a/pub;
	b=b/pub;
	if((a==0)||(b==0))
	cout<<"0"<<endl;
	else if((a==b)||(b==1))
	cout<<a<<endl;
	else if((a<0)||(b<0))
	cout<<"-"<<abs(a)<<"/"<<abs(b)<<endl;
	else
	cout<<a<<"/"<<b<<endl;
}
class Fract
{
	public:
		int a,b;
		Fract(int aa,int bb):a(aa),b(bb){}
		Fract(){
		}
		void show(){deal(a,b);}
};
Fract operator* (Fract &aa,Fract &bb)
{
	Fract temp;
	temp.a=aa.a*bb.a;
	temp.b=aa.b*bb.b;
	return temp;
 } 

int main()
{
    int n, m, p, q;
    while(cin >> n >> m >> q >> p)
    {
        Fract f1(n, m), f2(q, p);
        Fract fr = f1 * f2;
        fr.show();
    }
}
