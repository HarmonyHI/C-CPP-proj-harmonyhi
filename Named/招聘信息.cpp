#include<bits/stdc++.h>
#define INUM 100
using namespace std;
class Student
{
	public:
	char score[INUM];
	char grouptype[INUM];
	char phone[INUM];
	char name[INUM];
	Student(){}
}; 
class School
{
	public:
		char name[INUM];
		char phone[INUM];
		char code[INUM];
		char address[INUM];
		Student mystud[200];
		int studctr;
		School():studctr(0){}
};
void find1(char *temp,char *s)
{
	int i;
	int ctr=0;
	for(i=0;s[i]!=':';i++)
	 temp[ctr++]=s[i];
	temp[ctr++]=0;
	
}
void find2(char *temp,char *s)
{
	int i,ctr=0;
	for(i=0;s[i]!=':';i++);
	i++;
	for(;s[i]!=':';i++)
	temp[ctr++]=s[i];
	temp[ctr++]=0;
}
void find3(char *temp,char *s)
{
	int i,ctr=0;
	for(i=0;s[i]!=':';i++);
	i++;
	for(;s[i]!=':';i++);
	i++;
	for(;s[i]!=':';i++)
	temp[ctr++]=s[i];
	temp[ctr++]=0;
}
void find4(char *temp,char *s)
{
	int i,ctr=0;
	for(i=0;s[i]!=':';i++);
	i++;
	for(;s[i]!=':';i++);
	i++;
	for(;s[i]!=':';i++);
	i++;
	for(;s[i]!=0;i++)
	temp[ctr++]=s[i];
	temp[ctr++]=0;
}
bool is_stud(char *tmp)
{
	int test;
	if(tmp[0]>='0'&&tmp[0]<='9'&&tmp[1]>='0'&&tmp[1]<='9'&&tmp[2]>='0'&&tmp[2]<='9')
	test=(tmp[0]-'0')*100+(tmp[1]-'0')*10+(tmp[2]-'0');
	else if(tmp[0]>='0'&&tmp[0]<='9'&&tmp[1]>='0'&&tmp[1]<='9')
	test=(tmp[1]-'0')*10+(tmp[2]-'0');
	else
	return false;
	return test>=0&&test<=100;
 } 
void write_stud_to_school(School &database,char *temp)
{
	char tmp[INUM];
	find1(tmp,temp);
	strcpy(database.mystud[database.studctr].score,tmp);
	find2(tmp,temp);
	strcpy(database.mystud[database.studctr].grouptype,tmp);
	find3(tmp,temp);
	strcpy(database.mystud[database.studctr].phone,tmp);
	find4(tmp,temp);
	strcpy(database.mystud[database.studctr].name,tmp);
	database.studctr++;
}
void createschool(School &database,char *temp)
{
	char tmp[INUM];
	find1(tmp,temp);
	strcpy(database.name,tmp);
	find2(tmp,temp);
	strcpy(database.phone,tmp);
	find3(tmp,temp);
	strcpy(database.code,tmp);
	find4(tmp,temp);
	
	strcpy(database.address,tmp);
}
void Print(School &tmpsch,Student &temp)
{
	cout<<tmpsch.code<<" "<<tmpsch.name<<" "<<tmpsch.phone<<" ";
	
	if(!strcmp(tmpsch.address,"xijing"))
	cout<<"����";
	else if(!strcmp(tmpsch.address,"lushan"))
	cout<<"³ɽ";
	else if(!strcmp(tmpsch.address,"pingyang"))
	cout<<"ƽ��";
	else if(!strcmp(tmpsch.address,"danling"))
	cout<<"����";
	else if(!strcmp(tmpsch.address,"xinyuan"))
	cout<<"��Ԫ";
	else
	cout<<tmpsch.address;
	cout<<" "<<temp.name<<" "<<temp.grouptype<<" "<<temp.score<<" "<<temp.phone<<endl;
}
bool valueable(char *s)
{
	return s[0];
}
School school[1050];
int main()
{
	int schctr=0;
	
	char temp[100];
	
	while(gets(temp))
	if(!valueable(temp));
	else if(!is_stud(temp))
	{
		createschool(school[schctr],temp);
		schctr++;
	}
	else
	write_stud_to_school(school[schctr-1],temp);
	for(int i=0;i<schctr;i++)
		for(int ii=0;ii<school[i].studctr;ii++)
		Print(school[i],school[i].mystud[ii]);
	return 0;
 } 
//aaa ���̼���ѧԺ:010-21345673:na005:xijing
//
//84:java:13553001115:��С��
//
//67:c:13725330616:������
//
//25:java:13312349988:ФΪ
//
//bbb ����ѧ:094-32421233:km008:lushan
//
//81:c:18997111533:��·
//
//92:java::����
//
//ccc ��ý��ѧ:041-44441233:mt009:linhai
//
//88:c++:15900010002:�ĺ�����

