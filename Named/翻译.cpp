#include<bits/stdc++.h>
#define MAXLEN 500
#define WORDLEN 50
#define CHI 0
#define ENG 1
#define MAXWORDNUM 100
#define CHITOENG 8
#define Z 1
#define W 2
#define I 3
#define D 4
#define U 5
#define B 6
using namespace std;
int struction[20]={Z,U,W,D,I,B};
class word
{
	public:
		bool type;
		char *data;
		int function;
		word(){data=new char[CHITOENG*WORDLEN];}
		~word(){delete data;}
		void cleard(){for(int i=0;i<CHITOENG*WORDLEN;i++)data[i]=0;}
};
int wordbreaker(char *s,word *database)
{
	int ctr=0,inneri=0;
	for(int i=0;i<=strlen(s);i++)
	{
		if(s[i]==' '||s[i]==0)
		{
			database[ctr].data[inneri]=0;
			database[ctr].type=ENG;
			inneri=0;
			ctr++;
		}
		else
		database[ctr].data[inneri++]=s[i];
	}
	return ctr;
}
void getfun(word *database,int n)
{
	for(int i=0;i<n;i++)
	database[i].function=i+1;
}
int trans(char *a,char *b,int i)
{
	if(!strcmp(a,"I"))
	{
		strcpy(b,"ÎÒ");
		return i==0?Z:I;
	}
	else if(!strcmp(a,"very"))
	{
		strcpy(b,"ºÜ");
		return U;
	}
	else if(!strcmp(a,"love"))
	{
		strcpy(b,"°®");
		return W;
	}
	else if(!strcmp(a,"me"))
	{
		strcpy(b,"ÎÒ");
		return I;
	}
	else if(!strcmp(a,"you"))
	{
		strcpy(b,"Äã");
		return i==0?Z:I;
	}
	else
	{
		strcpy(b,a);
		return struction[i];
	}
		
}
void translator(word *eng,word *chi,int n)
{
	for(int i=0;i<n;i++)
	{
		chi[i].type=CHI;
		chi[i].function=trans(eng[i].data,chi[i].data,i);
	}
}
void addwordtofun(char *a,char *b)
{
	int pos=strlen(a);
	for(int i=0;i<strlen(b);i++)
		a[pos+i]=b[i];
	a[pos+strlen(b)]=0;
}
void wordmaker(word *eng,int n,char *chi)
{
	
	int inneri=0,ctr1=0,ctr2=0;
	for(int i=0;i<6;i++)
		for(int ii=0;ii<n;ii++)
		if(eng[ii].function==struction[i])
		addwordtofun(chi,eng[ii].data);
	for(int i=0;i<strlen(chi)-1;i++)
	chi[i]=chi[i+1];
	chi[strlen(chi)-1]=0;
}
int main()
{
	char inputs[MAXLEN],outputs[MAXLEN];
	word engword[MAXWORDNUM],chiword[MAXWORDNUM];
	int n;
	for(int i=0;i<MAXWORDNUM;i++)
	{
		engword[i].cleard();
		chiword[i].cleard();
	}
	gets(inputs);
	n=wordbreaker(inputs,engword);
	getfun(engword,n);
	translator(engword,chiword,n);
	wordmaker(chiword,n,outputs);
	cout<<outputs<<endl;
	for(int i=0;i<MAXLEN;i++)
	{
		inputs[i]=0;
		outputs[i]=0;
	}
}
