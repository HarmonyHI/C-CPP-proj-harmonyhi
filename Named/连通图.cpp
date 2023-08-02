#include<bits/stdc++.h>
using namespace std;
char mp[1005][1005];
int vis[1005][1005];
int dt[][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n;
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int xx=x+dt[i][0],yy=y+dt[i][1];
		if(xx>=0&&xx<n&&yy>=0&&yy<n&&!vis[xx][yy]&&mp[xx][yy]=='*'){
			dfs(xx,yy);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mp[i][j];
		}
	}
	memset(vis,0,sizeof vis);
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mp[i][j]=='*'&&!vis[i][j]){
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}