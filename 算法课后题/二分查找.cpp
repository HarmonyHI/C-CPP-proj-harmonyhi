#include<bits/stdc++.h>
using namespace std;
int binarysearch(int *data,int goal,int st,int ed){
	int pos=(ed+st)/2;
	if(ed<st)
		return -1;
	if(data[pos]==goal)
		return pos;
	if(data[pos]>goal)
		return binarysearch(data,goal,st,pos-1);
	else
		return binarysearch(data,goal,pos+1,ed);
}
int wbinarysearch(int *data,int goal,int st,int ed){
	while(st<=ed){
		int pos=(st+ed)/2;
		if(data[pos]==goal)
			return pos;
		else if(data[pos]>goal)
			ed=pos-1;
		else
			st=pos+1;
	}
	return -1;
}
int main(){
	int data[5000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	int goal;
	for(int i=0;i<10;i++){
		cin>>goal;
		cout<<wbinarysearch(data,goal,0,n-1)<<endl;
	}
	
}