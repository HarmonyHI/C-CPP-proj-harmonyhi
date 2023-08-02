#include<iostream>
#define STRLEN 50
#include<cstring>
using namespace std;
typedef char data;
class dot {
	public:
		dot *next,*head;
		data *a;
		bool ishead;
		int pos,length;
		dot(int len,bool ih,int i=0,dot *hd=0):length(len),ishead(ih) {
			a=new char[STRLEN];
			if(ih==true) {
				head=this;
				pos=0;
			} else {
				head=hd;
				pos=i;
			}
			next=NULL;
			if(pos<length)longeritself(pos);
		}
		~dot() {
			delete []a;
			length=0;
			if(pos!=length)
				(*next).~dot();
		}
		void longeritself(int pos) {
			next=new dot (length,false,pos+1,head);
		}
		void prt() {
			if (length==0);
			else {
				cout<<a<<endl;
				if(pos!=length)
					(*next).prt();
			}

		}
		void writeindata(int inpos,data ipt[],bool startchk) {
			if (startchk!=true)
				(*head).writeindata(inpos,ipt,true);
			else {
				if(pos!=inpos)
					(*next).writeindata(inpos,ipt,true);
				else
					strcpy(a,ipt);
			}
		}
		dot* findposdata(int inpos,bool startchk) {
			if (startchk!=true)
				(*head).findposdata(inpos,true);
			else {
				if(pos!=inpos)
					(*next).findposdata(inpos,true);
				else
					return this;
			}
		}
		data* operator[](int p) {
			return (*findposdata(p,false)).a;
		}
		void queuename() {
			char bkp[100];
			int num=0,i,iwei,iout,bschange[10000][20]= {{0},{0}},ruler[10000][20]= {{0},{1}};
			for(i=0; i<20; i++) {
				if(((*this)[num][i]>='A')&&((*this)[num][i]<='Z')) {
					bschange[num][i]++;
					(*this)[num][i]=(*this)[num][i]+('a'-'A');
				}
			}
			num++;
			for(iwei=19; iwei>=0; iwei--)
				for(iout=0; iout<num; iout++)
					for(i=0; i<num; i++)
						if (((*this)[i][iwei])>((*this)[i+1][iwei])) {
							strcpy(bkp,(*this)[i]);
							strcpy((*this)[i],(*this)[i+1]);
							strcpy((*this)[i+1],bkp);
						}
		}


};

int main() {
	int n;
	cout<<"登入条数"<<endl;
	cin>>n;
	dot a(n-1,true);
	char s[STRLEN];
	cout<<"登入信息"<<endl;
	for(int i=1; i<=n; i++) {
		cout<<"当前：第"<<i<<"位"<<endl;
		cin>>s;
		a.writeindata(i-1,s,false);
	}
	int menuctrl=true,menutimes=0;
	while(menuctrl) {
		if(menutimes==0)
		cout<<"请选择："<<endl<<"1.按名称排序"<<endl<<"2.按总成绩排序并打印"<<endl<<"3.生成科目平均分并打印"<<endl<<"4.原顺序打印"<<endl<<"5.删除数据"<<endl<<"6.添加数据"<<endl<<"7.删除全表"<<endl<<"8.建立新表"<<endl<<"9.导出"<<endl<<"10.退出"<<endl<<"11.查找"<<endl;
		int i=0;
		cin>>i;
		if(i==1) {
			a.queuename();
			cout<<"完成"<<endl; 
		}
		if(i==4)
			a.prt();
		if(i==7) {
			a.~dot();
			cout<<"已删除全表"<<endl;
		}
		if(i==10)
			menuctrl=false;
		if(i==11) {
			int tmp;
			cout<<"位置"; 
			cin>>tmp;
			cout<<"数据为"<<a[tmp-1]<<endl;
		}
		menutimes++;
	}

	cout<<"Thank you!"<<endl;
	return 0;
}
