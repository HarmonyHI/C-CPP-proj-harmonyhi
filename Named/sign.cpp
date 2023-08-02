#include<iostream>
using namespace std;
class line
{
  public:
	int data[110];
	bool alive[110];
	int indi;
	int ctr;
	  line()
	{
		for (int i = 0; i < 110; i++)
			alive[i] = false;
		ctr = 0;
		indi = 0;
	}
	bool writein(int tmp)
	{
		ctr++;
		// cout<<"CHECKED!!!!"<<tmp<<endl;
		if (tmp % 2 == 1)
		{
			data[indi] = tmp;
			alive[indi] = true;
			indi++;
			return true;
		}
		else
		{
			if(indi==0)
			{
				cout<<"NO"<<endl;
				turnprint(tmp);
			return false;	
			}
			
			else if (tmp - data[indi - 1] == 1)
			{
				indi--;
				alive[indi] = false;
				return true;
			}
			else
			{
				cout<<"NO"<<endl;
				if(data[indi-1]%2==1) 
				turnprint(data[indi-1]);
				
				
				else
				turnprint(tmp);
				//cout<<tmp<<endl;
				
				return false;
				}
				
		}
	}
	bool printfst()
	{
		int i;
		for (i = 0; i <indi; i++)
			if (alive[i])
			{
				cout << "NO" << endl;
				turnprint(data[i]);
				return false;
			}
			return true;
	}

	void turnprint(int a)
	{
		if (a == 1)
			printf("/*-?");
		if (a == 2)
			printf("?-*/");
		if (a == 3)
			printf("(-?");
		if (a == 4)
			printf("?-)");
		if (a == 5)
			printf("[-?");
		if (a == 6)
			printf("?-]");
		if (a == 7)
			printf("{-?");
		if (a == 8)
			printf("?-}");
	}

};

int main()
{
	char tmp;
	int doubletypesec = 0;
	line ting;
	int exit = 0;
	bool brk=false;
	while (1)
	{
		tmp = getchar();
		if (tmp == '.')
			exit = 1;
		else
		{
			if (tmp == '\n');
			else
				exit = 0;
		}

		if ((tmp == '\n') && (exit == 1))
			break;

		if (doubletypesec == 0)
		{
			if (tmp == '/')
			{
				// cout<<"half"<<endl;
				doubletypesec = 1;
				continue;
			}
			else if (tmp == '*')
			{
				doubletypesec = 2;
				continue;
			}
			else if (tmp == '(')
			if(ting.writein(3));
				else 
				{
					brk=true;
					break;
					}
			else if (tmp == ')')
				if(ting.writein(4));
				else 
				{
					brk=true;
					break;
					}
			else if (tmp == '[')
				if(ting.writein(5));
				else 
				{
					brk=true;
					break;
					}
			else if (tmp == ']')
			if(ting.writein(6));
				else 
				{
					brk=true;
					break;
					}
			else if (tmp == '{')
				if(ting.writein(7));
				else 
				{
					brk=true;
					break;
					}
			else if (tmp == '}')
				if(ting.writein(8));
				else 
				{
					brk=true;
					break;
					}
			else;
		}

		if (doubletypesec == 1)
		{
			// cout<<"halfcheck1"<<tmp<<endl;
			if (tmp == '.')
				exit = 1;
			else
			{
				if (tmp == '\n');
				else
					exit = 0;
			}

			if ((tmp == '\n') && (exit == 1))
				break;
			if (tmp == '*')
				if(ting.writein(1));
				else 
				{
					brk=true;
					break;
					}
			doubletypesec = 0;
		}
		if (doubletypesec == 2)
		{
			// cout<<"halfcheck2"<<endl;
			if (tmp == '.')
				exit = 1;
			else
			{
				if (tmp == '\n');
				else
					exit = 0;
			}

			if ((tmp == '\n') && (exit == 1))
				break;
			if (tmp == '/')
				if(ting.writein(2));
				else 
				{
					brk=true;
					break;
					}
			doubletypesec = 0;
		}
	}
	if(!brk)
	if(ting.printfst())
	cout<<"YES";
	}
	//if (ting.ctr)
	//{
		// ting.printall();
		// if(ting.indi%2)
		//ting.killdouble();
		// ting.printall();
		//ting.printlast();
	//}

//}

