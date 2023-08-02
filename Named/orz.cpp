#include<bits/stdc++.h>
using namespace std;
int ans;
int maxer(int input,bool AC=false){
	static int data=input;
	if(input>data)
		data=input;
	if(AC)
		data=0;
	return data;
}
void cal(int needal){
	//cout<<needal<<"test"<<endl;
	if(needal==0){
		maxer(ans);
		return;
	}
	else
	for(int i=1;i<=needal;i++){
		ans++;
		cal(needal%i);
		//system("pause");
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int needal;
		cin>>needal;
		ans=0;
		maxer(0,true);
		cal(needal);
		cout<<maxer(0)<<endl;
	}
}