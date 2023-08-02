#include<iostream>
using namespace std;
class Student
{
	public:
		string name;
		int sex,grade;
		Student *next;
		Student(string a,int b,int c):name(a),sex(b),grade(c),next(NULL) 
		{
		cout<<"A student named by "<<name<<" is created!"<<endl;	
		}
		 ~Student(){cout<<"A student named by "<<name<<" is erased."<<endl;}
		void showInfo(){cout<<"name = "<<name<<", sex = "<<sex<<", grade = "<<grade<<";";
		}
		void setNext(Student* a){next=a;
		}
		Student* getNext(){return next;
		}
		
 } ;
class StudentCadre:public Student
{
	public:
		string position;
		void showInfo(){cout<<"name = "<<name<<", sex = "<<sex<<", grade = "<<grade<<";"<<"position = "<<position<<".";
		}
		~StudentCadre(){cout<<"A student named by "<<name<<" is erased."<<endl;};
		StudentCadre(string a,int b,int c,string d):Student(a,b,c),position(d)
		{
			cout<<"A student cadre with position "<<position<<" is created."<<endl;
		}
 } ;


int main()
{
    int num;
    string name, position;
    bool sex;
    int grade;
    Student *header, *student, *curStudent;
 
    cin>>name>>sex>>grade>>position;
    header = new StudentCadre(name, sex, grade,position);
    curStudent = header;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cin>>name>>sex>>grade;
        student = new Student(name, sex, grade);
        curStudent -> setNext(student);
        curStudent = curStudent -> getNext();
    }
    ((StudentCadre*)header) -> showInfo();
    cout<<endl;
    curStudent = header;
    while (curStudent -> getNext() != NULL)
    {
        curStudent = curStudent -> getNext();
        curStudent->showInfo();
        cout<<endl;
    }
 
    curStudent = header;
    while (curStudent != NULL)
    {
        student = curStudent;
        curStudent = curStudent -> getNext();
        delete student;
    }
    return 0;
}
