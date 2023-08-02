#include<bits/stdc++.h>
int sum(int *data,int n){
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=data[i];
	}
	return ans;
}
void make_change(int *data,int n){
	for(int i=0;i<n-1;i++){
		if(data[i+1]==data[i]){
			data[i]=0;
		}
	}
}
using namespace std;
int main(){
	int n;
	cin>>n;
	int data[n];
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	cout<<sum(data,n)<<endl;
	make_change(data,n);
	cout<<sum(data,n);
}
