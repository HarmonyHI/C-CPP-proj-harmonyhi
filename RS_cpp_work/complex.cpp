#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class Complex
{
public:
    double r,i;
    Complex( double r_=0.0,double i_=0.0):r(r_),i(i_){cout<<"created"<<endl;}
    Complex operator + (const Complex &c);

};

Complex Complex::operator +(const Complex &c)
{
	Complex temp(r+c.r,i+c.i);
    return temp;
}
int main()
{
    Complex a(4,4),b(1,1);

    cout<<(a+b).r<<" "<<(a+b).i<<endl;
    return 0;

}

