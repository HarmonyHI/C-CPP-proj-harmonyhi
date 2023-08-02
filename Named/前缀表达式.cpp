#include<iostream>
#include<stdio.h>
#define PLUS 5487735
#define MINUS 6486714
#define MULTI 8496427
#define PER 5427774
#define SPACE 7664727
#define OTHER 8263217
#define DEL 9486747
#define MAXI 500
#define CHKNUM 5780011
using namespace std;
class queuedot {
	public:
		double data;
		queuedot *nextone;
		queuedot():nextone(NULL) {}
};
class queuebox {
	public:
		queuedot *topptr,*endptr;
		queuedot defaultone;
		queuebox():topptr(&defaultone),endptr(&defaultone) {}
};
class stackdot {
	public:
		double data;
		stackdot *nextone;
		stackdot():nextone(NULL) {}
};
class stackbox {
	public:
		stackdot *topestone;
		stackbox():topestone(NULL) {}
};
double cifang(int a) {
	double w=1;
	if(a>0)
		for(int i=1; i<=a; i++)
			w=w*10;
	if(a<0)
		for(int i=1; i<=-a; i++)
			w=w/10;
	return w;
}
void popin(queuebox &tmp,double dataipt) {
	queuedot *newone;
	newone=new queuedot;
	(*newone).data=dataipt;
	(*tmp.endptr).nextone=newone;
	if(tmp.topptr==NULL) {
		tmp.topptr=newone;
	}
	tmp.endptr=newone;
}
double popout(queuebox &tmp) {
	if(tmp.topptr==NULL)
		return EOF;
	double temp=(*tmp.topptr).data;
	tmp.topptr=((*tmp.topptr).nextone);
	return temp;
}
int translate(char tmp) {
	if((tmp>='0')&&(tmp<='9'))
		return tmp-'0';
	else if(tmp=='+')
		return PLUS;
	else if(tmp=='-')
		return MINUS;
	else if(tmp=='*')
		return MULTI;
	else if(tmp=='/')
		return PER;
	else if(tmp==' ')
		return SPACE;
	else if(tmp=='.')
		return DEL;
	else
		return OTHER;
}
void popin(stackbox &box,double data) {
	stackdot *temp;
	temp=new stackdot;
	(*temp).data=data;
	(*temp).nextone=box.topestone;
	box.topestone=temp;
}
double popout(stackbox &box) {
	if(box.topestone==NULL)
		return EOF;
	double bkp;
	bkp=(*box.topestone).data;
	stackdot *temp;
	temp=(*box.topestone).nextone;
	box.topestone=temp;
	return bkp;
}
void stacknewin(stackbox *temp,double data) {
	static double tempcal=0;
	static int tempcali=0;
	if(data==SPACE) {
		popin(*temp,tempcal);
		tempcal=0,tempcali=0;
	} else if((data>CHKNUM)&&(data<CHKNUM+7))
		tempcali=0-data+CHKNUM;

	else if(data==DEL);
	else if((data==PLUS)&&(tempcali!=0))
		tempcal=tempcal;
	else if((data==MINUS)&&(tempcali!=0))
		tempcal=0-tempcal;
	else {
		tempcal=tempcal+data*cifang(tempcali);
		tempcali++;
	}
}
void addnum_and_remove_empty(queuebox &tmp) {
	stackbox *a,*b;
	a=new stackbox;
	b=new stackbox;
	double chktmp;
	static int delnum=0;
	bool chkeddel=false;
	while(true) { //队列入站A实现添加小数标记颠倒
		chktmp=popout(tmp);
		if(chkeddel&&chktmp!=DEL&&chktmp!=SPACE)
			delnum++;
		if(chktmp==EOF)
			break;
		else if(chktmp==DEL)
			chkeddel=true;
		else if((chktmp==SPACE)&&(chkeddel)) {
			popin(*a,CHKNUM+delnum);
			chkeddel=false;
			delnum=0;
		}
		popin(*a,chktmp);
	}
	popout(*a);//排掉站A最后的空格
	while(true) { //站A入站B转化并还原
		chktmp=popout(*a);
		if(chktmp==EOF) {
			stacknewin(b,SPACE);
			break;
		}

		stacknewin(b,chktmp);
	}
	while(true) { //站B入原队列
		chktmp=popout(*b);
		if(chktmp==EOF)
			break;
		popin(tmp,chktmp);
	}
}
void printall(queuebox &ting) {
	while(true) {
		double chktmp=popout(ting);
		if(chktmp==EOF)
			break;
		printf("%.1lf\n",chktmp);
	}
}
queuedot* nexttwo(queuedot *a) {
	queuedot *tmp;
	tmp=(*a).nextone;
	tmp=(*tmp).nextone;
	return tmp;
}
bool Is_leagel_op(queuedot *aa) {
	double a;
	a=(*aa).data;
	if((a==PLUS)||(a==MINUS)||(a==MULTI)||(a==PER))
		return true;
	else
		return false;
}
void add_dot_on_next_three(queuedot &ting,double data) {
	queuedot *temp;
	temp=nexttwo(&ting);
	queuedot *newone;
	queuedot *newnext;
	newnext=(*temp).nextone;
	newone=new queuedot;
	(*newone).data=data;
	(*temp).nextone=newone;
	(*newone).nextone=newnext;
}
void remove_three_dot(queuedot &ting) {
	queuedot *a,*b,*c;
	a=ting.nextone;
	b=(*a).nextone;
	c=(*b).nextone;
	ting.nextone=(*c).nextone;
}
void getequal(queuebox &ting) {
	double ans;
	double a,b;
	bool funhead=true;
	queuedot *temp;
	temp=ting.topptr;
	queuedot *beforedelete;
	for(; (*(*temp).nextone).nextone!=NULL; temp=(*temp).nextone) {
		a=(*(*temp).nextone).data;
		b=(*nexttwo(temp)).data;
		if(!((Is_leagel_op(temp))&&(!Is_leagel_op((*temp).nextone))&&(!Is_leagel_op(nexttwo(temp)))))
			beforedelete=temp;
		else {
			if((*temp).data==PLUS)
				add_dot_on_next_three(*temp,a+b);
			if((*temp).data==MINUS)
				add_dot_on_next_three(*temp,a-b);
			if((*temp).data==MULTI)
				add_dot_on_next_three(*temp,a*b);
			if((*temp).data==PER)
				add_dot_on_next_three(*temp,a/b);
			if(((Is_leagel_op(temp))&&(!Is_leagel_op((*temp).nextone))&&(!Is_leagel_op(nexttwo(temp))))&&(funhead))
				ting.topptr=(*nexttwo(temp)).nextone;
			else
				remove_three_dot(*beforedelete);
		}
		funhead=false;
	}
}
bool listlonely(queuebox &ting) {
	if((ting.topptr!=NULL)&&((*ting.topptr).nextone==NULL))
		return true;
	else
		return false;
}
bool otherchk(queuebox &ting) {
	queuedot *tmp=ting.topptr;
	while(true) {
		if((*tmp).data==OTHER)
			return true;
		if((*tmp).nextone==NULL)
			break;
		tmp=(*tmp).nextone;
	}
	return false;
}
bool numchk(queuebox &ting) {
	queuedot *tmp=ting.topptr;
	while(true) {
		if((*tmp).data>=PER)
			return false;
		if((*tmp).nextone==NULL)
			break;
		tmp=(*tmp).nextone;
	}
	return true;
}
int main() {
	queuebox ting;
	char temp;
	while(scanf("%c",&temp)&&(temp!='\n'))
		popin(ting,translate(temp));
	popin(ting,translate(' '));
	popout(ting);
	addnum_and_remove_empty(ting);
	int i=0;
	bool chk=otherchk(ting);
	if(!chk) {
		while(!listlonely(ting)&&(i<MAXI)) {
			i++;
			getequal(ting);
		}
		if((i==MAXI)||(!numchk(ting)))
			printf("ERROR");
		else
			printall(ting);
	} else
		printf("ERROR");
}
