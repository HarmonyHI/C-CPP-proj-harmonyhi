#include<bits/stdc++.h>
using namespace std;
bool block[30][30][30];
void writeblock(int x,int y,int z,int xx,int yy,int zz,bool enable=true){
	for(int i=x;i<=xx;i++)
		for(int ii=y;ii<=yy;ii++)
			for(int iii=z;iii<=zz;iii++)
				block[i][ii][iii]=enable;
}
int counter(int xx,int yy,int zz){
	int ans=0;
	for(int i=1;i<=xx;i++)
		for(int ii=1;ii<=yy;ii++)
			for(int iii=1;iii<=zz;iii++)
				if(block[i][ii][iii])
					ans++;
	return ans;
}
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	writeblock(1,1,1,x,y,z,true);
	int n;
	cin>>n;
	int x1,y1,z1,x2,y2,z2;
	for(int i=0;i<n;i++){
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		writeblock(x1,y1,z1,x2,y2,z2,false);
	}
	cout<<counter(x,y,z);
}