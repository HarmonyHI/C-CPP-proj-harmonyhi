#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
void HideWindow()
{
	HWND hwnd=GetForegroundWindow();
	if(hwnd)
	ShowWindow(hwnd,SW_HIDE);
}
char box[4][4][20][50];
//void load(char ***s)
//{
//	s[1][1]={"��ʦ","����","����","��Ա","��ʦ","ҽ��","��ʿ","˾��","����","��ʦ"};
//	s[1][2]={"����","����","����","����","����Ա","��๤","����ʦ","��ʦ","�ɹ�Ա","���ʦ"}
//	s[1][3]={"����ʦ","����Ա","����Ա","��еʦ","������","���Ա","������","԰��ʦ","��ѧ��","������"}
//	s[2][1]={"��ʦ","����","����","��Ա","��ʦ","ҽ��","��ʿ","˾��","����","��ʦ"};
//	s[2][2]={"����","����","����","����","����Ա","��๤","����ʦ","��ʦ","�ɹ�Ա","���ʦ"}
//	s[2][3]={"����ʦ","����Ա","����Ա","��еʦ","������","���Ա","������","԰��ʦ","��ѧ��","������"}
//	s[3][1]={"��ʦ","����","����","��Ա","��ʦ","ҽ��","��ʿ","˾��","����","��ʦ"};
//	s[3][2]={"����","����","����","����","����Ա","��๤","����ʦ","��ʦ","�ɹ�Ա","���ʦ"}
//	s[3][3]={"����ʦ","����Ա","����Ա","��еʦ","������","���Ա","������","԰��ʦ","��ѧ��","������"}
//}
void append(char *s,char *ap)
{
	int length=strlen(s);
	int aplen=strlen(ap);
	for(int i=length,ib=0;ib<aplen;ib++,i++)
	{
		s[i]=ap[ib];
		if(ib==aplen-1)
		s[i+1]=0;
	}
 } 
char *createfunc(int cons,int tpe)
{
	char *tmp;
	tmp=new char[50];
	strcpy(tmp,box[cons][tpe][rand()*10]);
	return tmp;
}
void erase(char *s)
{
	int length=strlen(s);
	for(int i=0;i<=length;i++)
	s[i]=0;
}
int main()
{ 
	//load(box);
	int ret=0;
	char data[50]="7777777"; 
	HideWindow();
	while(1)
	{ret=MessageBox(NULL,data,"fjjcfjgngfnfg",3);
		erase(data);
		append(data,createfunc(1,ret==6?1:ret==7?2:3));
		append(data,createfunc(2,ret==6?1:ret==7?2:3));
		append(data,createfunc(3,ret==6?1:ret==7?2:3));
	}
	return 0;
}
