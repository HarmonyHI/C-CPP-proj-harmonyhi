#include<iostream>
using namespace std;
class Base
{
	private:
		int ting;
	public:
		int ret()const{return ting;
		}
		Base(int a):ting(a){cout<<"Base = "<<ting<<" is created."<<endl;	}
		Base(const Base &a):ting(a.ting){cout<<"Base = "<<ting<<" is copied."<<endl;
		}
		~Base(){cout<<"Base = "<<ting<<" is erased."<<endl;
		}
		
 }; 
 class Derived:public Base
 {
 	public:
 		int c;
 		Derived(int a,int b):Base(a),c(b){cout<<"Derived = "<<c<<" is created."<<endl;
		 }
		 Derived(const Derived &a):Base(a),c(a.c){cout<<"Derived = "<<c<<" is copied."<<endl;
		 }
		 ~Derived(){cout<<"Derived = "<<c<<" is erased."<<endl;
		 }
 };

int main()
{
    int cases, data1, data2;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>data1>>data2;
        Base base1(data1), base2(base1);

        Derived derived1(data1, data2), derived2(derived1);
    }
}
