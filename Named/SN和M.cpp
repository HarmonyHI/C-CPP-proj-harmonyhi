#include<iostream>
using namespace std;
int main(){
	double sum=0;
	unsigned long long int m,i;
	cin>>m;
	for(i=0;;)
		if(sum>m)
			break;
		else{
			i++;
			sum=sum+(1/(double)i);	
		}
	cout<<i;
}