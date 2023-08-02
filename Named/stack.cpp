#include<iostream>
using namespace std;
class stackdot
{
	public:
		int data;
		stackdot *nextone;
		stackdot():nextone(NULL){}
};
class stackbox
{
	public:
		stackdot *topestone;
		stackbox():topestone(NULL){}
 };
void popin(stackbox &box,int data)
{
	stackdot *temp;
	temp=new stackdot;
	(*temp).data=data;
	(*temp).nextone=box.topestone;
	box.topestone=temp;
}
int popout(stackbox &box)
{
	if(box.topestone==NULL)
	return EOF;
	int bkp;
	bkp=(*box.topestone).data;
	stackdot *temp;
	temp=(*box.topestone).nextone;
	box.topestone=temp;
	return bkp;
}
int main()
{
	stackbox ting;
	popin(ting,10086);
	cout<<popout(ting)<<endl;
	cout<<popout(ting)<<endl;cout<<popout(ting)<<endl;cout<<popout(ting)<<endl;
}
