#include<bits/stdc++.h>
#define END -214748364
using namespace std;
typedef double dt;
class Node
{
	public:
	dt data;
	Node *next;
	Node(dt deft=10086):next(NULL){}
};
class Queue
{
	public:
	Queue():head(NULL),end(NULL){}
	Node *head,*end;
	void insert(dt tmp)
	{
	if(head==end&&head==NULL)
	{
		head=new Node;
		end=head;
	}
	end->next=new Node;
	end=end->next;
	end->data=tmp;
}
	dt pop()
	{
	if(head->next==NULL)
	return END;
	dt tmp=head->next->data;
	head=head->next;
	return tmp;
}
	void empty()
	{
	Node *tmp=head->next;
	Node *del;
	while(tmp->next!=NULL)
	{
		del=tmp->next;
		delete tmp;
		tmp=del;
	}
}
bool is_empty()
	{
		if(head==end)
		return true;
		return false;
	}
};
class Stack
{
	public:
	Stack():head(NULL),end(NULL){}
	Node *head,*end;
	void insert(dt tmp)
	{
	if(head==end&&head==NULL)
	{
		head=new Node;
		end=head;
	}
	end->next=new Node;
	end=end->next;
	end->data=tmp;
}
	dt pop()
	{	
		if(is_empty())
		return END;
		Node *temp=head;
		while(temp->next!=end)
			temp=temp->next;
		end=temp;
		dt tmp=temp->next->data;
		return tmp;
}
	void empty()
	{
	Node *tmp=head->next;
	Node *del;
	while(tmp->next!=NULL)
	{
		del=tmp->next;
		delete tmp;
		tmp=del;
	}
}
	bool is_empty()
	{
		if(head==end)
		return true;
		return false;
	}
};
int main()
{
	Queue test;
	for(int i=0;i<100;i++)
	test.insert(i+800);
	while(1)
	{
		dt tmp=test.pop();
		if(test.is_empty())
		break;
		cout<<tmp<<endl;
	}
	
}

