#include<iostream>
using namespace std;
class queuedot {
	public:
		int data;
		queuedot *nextone;
		queuedot():nextone(NULL) {}
};
class queuebox {
	public:
		queuedot *topptr,*endptr;
		queuedot defaultone;
		queuebox():topptr(&defaultone),endptr(&defaultone) {}
};
void linewrt(queuebox &tmp,int dataipt) {
	queuedot *newone;
	newone=new queuedot;
	(*newone).data=dataipt;
	(*tmp.endptr).nextone=newone;
	tmp.endptr=newone;
}
void popout(queuebox &tmp) {
	cout<<(*tmp.topptr).data;
	tmp.topptr=((*tmp.topptr).nextone);
}
void popoutre(queuebox &tmp) {
	tmp.topptr=((*tmp.topptr).nextone);
}
int main() {}
