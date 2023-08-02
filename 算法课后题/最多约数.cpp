#include<bits/stdc++.h>
using namespace std;
int cal(int a){
	int ans=0;
	for(int i=1;i<=a;i++){
		if(a%i==0){
			ans++;
		}
	}
	return ans;
}
int fun(int a,int b){
	int ans=cal(a);
	for(int i=a;i<=b;i++){
		int tmp=cal(i);
		if(tmp>ans){
			ans=tmp;
		}
	}
	return ans;
}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<fun(a,b);
}
