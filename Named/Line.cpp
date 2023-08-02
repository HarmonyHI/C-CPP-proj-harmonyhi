#include<iostream>
using namespace std;
class Point
{
	private:
		double x,y;
	public:
		Point(double inx=0,double iny=0):x(inx),y(iny){cout<<"Point : ("<<x<<", "<<y<<") is created."<<endl;}
		~Point(){cout<<"Point : ("<<x<<", "<<y<<") is erased."<<endl;}
		void editpoint(double edx,double edy){x=edx;y=edy;}
		Point(const Point &ting):x(ting.x),y(ting.y){cout<<"Point : ("<<x<<", "<<y<<") is copied."<<endl;}
		void show(){cout<<"Point : ("<<x<<", "<<y<<")"<<endl;}
		double gex(){return x;}
		double gey(){return y;}
};
class Line
{
	private:
		Point temp1,temp2;
	public:
		Line & setLine(Line &templ){temp1.editpoint(templ.temp1.gex(),templ.temp1.gey());temp2.editpoint(templ.temp2.gex(),templ.temp2.gey());return *this;}
		Line & setLine(Point &tempa,Point &tempb){temp1=tempa;temp2=tempb;return *this;}
		void readLine(){double a,b,c,d;char usl;cin>>a>>usl>>b>>c>>usl>>d;temp1.editpoint(a,b);temp2.editpoint(c,d);}
		Line(double inx1=0,double iny1=0,double inx2=0,double iny2=0){temp1.editpoint(inx1,iny1);temp2.editpoint(inx2,iny2);cout<<"Line : ("<<temp1.gex()<<", "<<temp1.gey()<<") to ("<<temp2.gex()<<", "<<temp2.gey()<<")"<<" is created."<<endl;}
		Line(Point &t1,Point &t2):temp1(t1),temp2(t2){cout<<"Line : ("<<temp1.gex()<<", "<<temp1.gey()<<") to ("<<temp2.gex()<<", "<<temp2.gey()<<")"<<" is created."<<endl;}
		Line(const Line &l1):temp1(l1.temp1),temp2(l1.temp2){cout<<"Line : ("<<temp1.gex()<<", "<<temp1.gey()<<") to ("<<temp2.gex()<<", "<<temp2.gey()<<")"<<" is copied."<<endl;} 
		~Line(){cout<<"Line : ("<<temp1.gex()<<", "<<temp1.gey()<<") to ("<<temp2.gex()<<", "<<temp2.gey()<<")"<<" is erased."<<endl;}
		void show(){cout<<"Line : ("<<temp1.gex()<<", "<<temp1.gey()<<") to ("<<temp2.gex()<<", "<<temp2.gey()<<")"<<endl;}	
};
int main()
{
    int num, i;
    Point p(1, -2), q(2, -1), t;
    t.show();
    std::cin>>num;
    Line line[num];
    for(i = 0; i < num; i++)
    {
        line[i].readLine();
        line[i].show();
    }
    Line l1(p, q), l2(p,t), l3(q,t), l4(l1);
    l1.show();
    l2.setLine(l1).show();
    l3.show();
    l4.setLine(t,q).show();
}
