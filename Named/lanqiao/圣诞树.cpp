#include<iostream>
using namespace std;
int main()
{
	int h;
	cin>>h;
	for(int i=0;i<h;i=i+3)
	{
		for(int ii=0;ii<(h-i)+6;ii++)
		cout<<" ";
		for(int ii=0;ii<i*2;ii++)
		cout<<"*";
		cout<<endl;
	}
	h=h+5;
	for(int i=0;i<h;i=i+3)
	{
		for(int ii=0;ii<(h-i)+4;ii++)
		cout<<" ";
		for(int ii=0;ii<i*2;ii++)
		cout<<"*";
		cout<<endl;
	}
	h=h+5;
	for(int i=0;i<h;i=i+3)
	{
		for(int ii=0;ii<(h-i)+2;ii++)
		cout<<" ";
		for(int ii=0;ii<i*2;ii++)
		cout<<"*";
		cout<<endl;
	}h=h+5;
	for(int i=0;i<h;i=i+3)
	{
		for(int ii=0;ii<(h-i);ii++)
		cout<<" ";
		for(int ii=0;ii<i*2;ii++)
		cout<<"*";
		cout<<endl;
	}
	for(int i=0;i<h/4;i=i+1)
	{
		for(int ii=0;ii<h*2/5;ii++)
	cout<<" ";
	cout<<"**"<<endl;	
	}
	
}
