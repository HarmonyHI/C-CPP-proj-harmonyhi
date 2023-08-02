#include<bits/stdc++.h>
using namespace std;
string data;
int pos=1;
char deal(int tmp){
	if(tmp%3==0){
		return 'B';
	}
	else if(tmp%5==0){
		return 'F';
	}
	else{
		return 'N';
	}
}
string max_the_data(string data, int slen){
	while(data.length()<slen*100){
		char tmp=deal(pos++);
		if(tmp=='B'||tmp=='F'){
			data.push_back(tmp);
		}
	}
}
bool sin(string sm, string bg){
	int idx=bg.find(sm);
	if(idx==string::npos){
		return true;
	}
	return false;
}
int main(){
	int na,nb;
	cin>>na;
	string s;
	for(int ia=0;ia<na;ia++){
		cin>>nb;
		cin>>s;
		int slen=s.length();
		data=max_the_data(data,slen);
		if(sin(s,data)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
	}
	cout<<endl;
	return 0;
}
