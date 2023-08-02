#include <iostream>
#define ended_function "over"
using namespace std;
class stack
{
	private:
		char data[1024];
		int pointer;
		int chk;
	public:
		stack():pointer(0),chk(0){}
		~stack(){}
		void stackin(char character)
			{	
				pointer++;
				data[pointer]=character;
			}
		char stackout()
			{
				char temp;
				temp=data[pointer];
				data[pointer]=0;
				if (pointer!=0)
				pointer--;
				return temp;
			}
		int getpointer()
			{
				return pointer;
			}
		int clock()
			{
				chk++;
				if(chk>1)
				chk=chk-2;
				return chk;
			}
};

bool write_in_stack(stack &stk)
{
	char tmp;
	string standard(ended_function);
	static int ender=0,test_out_hit_type=0;
	scanf("%c",&tmp);
	if(standard.find(tmp)!=string::npos)
		test_out_hit_type++;
	else
		test_out_hit_type=0;
	ender++;
	if(test_out_hit_type==4)
	{
		for(int i=0;i<4;i++)
		stk.stackout();
		return false;
	}
	stk.stackin(tmp);
}
void pop_out_stack(stack &stk)
{
	int ptr=stk.getpointer();
	for(int i=0;i<ptr;i++)
	printf("%c",stk.stackout());
	printf("\n");
}
int main()
{
	stack testtmp;
	while(write_in_stack(testtmp));
	pop_out_stack(testtmp);
}




