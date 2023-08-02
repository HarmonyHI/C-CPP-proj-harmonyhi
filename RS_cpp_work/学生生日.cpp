#include<iostream>
using namespace std;
int num=0;
class Date
{
	public:
		int y,m,d;
		Date(int a,int b,int c):y(a),m(b),d(c){cout<<"Date "<<y<<"-"<<m<<"-"<<d<<" is created."<<endl;}
		~Date(){cout<<"Date "<<y<<"-"<<m<<"-"<<d<<" is erased."<<endl;
		}
};
class Person:public Date
{
	
	public:
	string name;
		Person(int a,int b,int c,string k):Date(a,b,c),name(k){num++;
		cout<<"The "<<num<<"th person "<<name<<" whose birthday is "<<y<<"-"<<m<<"-"<<d<<" is created."<<endl;
		}
		~Person(){
			cout<<"Person "<<name<<" whose birthday is "<<y<<"-"<<m<<"-"<<d<<" is erased."<<endl;
		}
};
class Student:public Person
{
	public:
		int id;
		Student(int a,int b,int c,string k,int e):Person(a,b,c,k),id(e){
		cout<<"The "<<num<<"th student "<<name<<" whose birthday is "<<y<<"-"<<m<<"-"<<d<<" and id is "<<id<<" is created."<<endl;
		}
		~Student(){cout<<"Student "<<name<<" whose birthday is "<<y<<"-"<<m<<"-"<<d<<" and id is "<<id<<" is erased."<<endl;}
};
int main()
{
    int year, month, day, id, i;
    string name;
    int num;
    cin>>num;
    Student **students = new Student*[num];
    for (i = 0; i < num; i++)
    {
        cin>>year>>month>>day>>id>>name;
        students[i] = new Student(year, month, day, name, id);
    }
    for (i = 0;i <num; i++)
        delete students[i];
    delete[] students;
    return 0;
}
