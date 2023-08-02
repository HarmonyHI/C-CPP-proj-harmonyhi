#include<bits/stdc++.h>
using namespace std;
char mp[1000][1000];
void sp_killthestar(char *str,int xpos,int length){
	for(int i=xpos;i<length&&str[i]=='*';i++)
		str[i]='.';
}
void sz_killthestar(int xpos,int ypos,int length){
	for(int i=ypos;i<length&&mp[i][xpos]=='*';i++){
		mp[i][xpos]='.';
	}
}
int main(){
	int sidelength;
	int ans=0;
	cin>>sidelength;
	
	
	for(int i=0;i<sidelength;i++){
		int ii=0;
		for(;ii<sidelength;ii++)
			cin>>mp[i][ii];
		mp[i][ii]=0;
	}
		
	
	
	for(int r=0;r<sidelength-1;r++){
		for(int i=0;i<sidelength-1;i++){
			if(mp[r][i]=='*'&&mp[r][i+1]=='*'){
				sp_killthestar(mp[r],i,sidelength);
				ans++;
			}
			if(mp[r][i]=='*'&&mp[r+1][i]=='*'){
				sz_killthestar(i,r,sidelength);
				ans++;
			}
			if(mp[r][i]=='*'){
				mp[r][i]='.';
				ans++;
			}
		}
	}
	cout<<ans;
	}



orz
while(tmp!=0)
    tmp=tmp%(tmp/2+1);
    ans++;