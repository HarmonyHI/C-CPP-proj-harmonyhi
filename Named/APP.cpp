#include<bits/stdc++.h>
using namespace std;
class Pointer{
	public:
		char str[300];
		void Write(char *s){
			strcpy(str,s);
		}
};
class BinPosition{
	public:
		double x,y;
		void Write(double xx,double yy){
			x=xx;
			y=yy;
		}
		bool check(double xx,double yy){
			return xx==x&&yy==y;
		}
};
class Botton {
	public:
		char pintext[50];
		BinPosition	pos;
		Pointer ptr;
		void editBotton(double xx,double yy,char *name,char *info){
			
			pos.Write(xx,yy);
			ptr.Write(info);
			strcpy(pintext,name);
		}
};
class Inputedge{
	public:
		char text[50];
		char message[200];
		BinPosition	pos;
		void input(){
			cin>>message;
		}
		char* read(){
			return message;
		}
		void editInputedge(double xx,double yy,char *tmp){
			strcpy(text,tmp);
			pos.Write(xx,yy);
		}
};
class Page{
	public:
		int length,width,bottonn,bottoni,edgen,edgei;
		Botton *botton;
		Inputedge *iptedge;
		Page(int ln,int wn,int btn,int egn):length(ln),width(wn),bottoni(0),edgei(0),bottonn(btn),edgen(egn){botton=new Botton[bottonn];iptedge=new Inputedge[edgen];}
		bool createbtn(double xx,double yy,char *name,char *info){
			if(bottoni<bottonn)
				botton[bottoni++].editBotton(xx,yy,name,info);
			
			else
			return false;
			return true;
		}
		bool createdge(double xx,double yy,char *s){
			if(edgei<edgen)
			iptedge[edgei++].editInputedge(xx,yy,s);
			else
			return false;
			return true;
		}
};
char* findstuff(double x,double y,Page &tmp)
{
	static char empty[10];
	strcpy(empty," ");
	for(int i=0;i<tmp.bottonn;i++)
	if(tmp.botton[i].pos.check(x,y))
	{
		tmp.bottoni=i;
		return tmp.botton[i].pintext;
	}
	
	for(int i=0;i<tmp.edgen;i++)
	if(tmp.iptedge[i].pos.check(x,y))
	{
		tmp.edgei=i;
		return tmp.iptedge[i].text;
	}
	return empty;
}
void draw(Page &page)
{
	sleep(1);
	system("cls");
	
	for(int i=0;i<page.width;i++)
	{
	for(int ii=0;ii<page.length;ii++)
		cout<<findstuff(ii,i,page);
	cout<<endl;
	}
	
}
void setup(Page &a,Page &b,Page &c,int &pos)
{
	pos=0;
	for(;pos<3;pos++)
	{
	Page &tmp=(pos==0?a:(pos==1?b:c));
	char name[100],command[100];
	strcpy(name,"APP DEMO (BUTTON)");
	strcpy(command,"Request for open app");
	tmp.createbtn(5,7,name,command);
	if(pos==0)
	strcpy(name,"NUM 1");
	else if(pos==1)
	strcpy(name,"NUM 2");
	else
	strcpy(name,"NUM 3");
	strcpy(command,"Request for open app");
	tmp.createbtn(7,7,name,command);	
	}
	pos=2;
}
void flash(Page &a,Page &b,Page &c,int pos)
{
	Page &tmp=(pos==0?a:(pos==1?b:c));
	draw(tmp);
}
int main()
{
	Page mainpage(30,30,50,10),mypage(30,30,50,10),search(30,30,50,10);
	int current;
	setup(mainpage,mypage,search,current);
	while(true)
	flash(mainpage,mypage,search,current);
}