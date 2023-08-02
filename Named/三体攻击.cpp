#include<bits/stdc++.h>
using namespace std;
void get_location(int A,int B,int C,int times,int &i,int &j,int &k)
{
	static int tmpii=times;
	bool is_same=(times==tmpii);
	for(int ii=0;ii<A;ii++)
	for(int iii=0;iii<B;iii++)
	for(int iiii=0;iiii<C;iiii++)
	if(((ii-1)*B+(iii-1))*C+(iiii-1)+1==times)
	{
		cout<<"get"<<" "<<ii<<" "<<iii<<" "<<iiii<<" okto "<<times<<endl;
		if(is_same)
		continue;
		else
		{
			i=ii;
			j=iii;
			k=iiii;
			return;
		}
	}
}
int main()
{
	int A,B,C;
	cin>>A>>B>>C;
	int boat[A+5][B+5][C+5];
	int n;
	cin>>n;
	for(int ii=0;ii<A*B*C;ii++)
	{
		int i=0,j=0,k=0;
		get_location(A,B,C,ii,i,j,k);
		cin>>boat[i][j][k];
		cout<<"give "<<i<<" "<<j<<" "<<k<<" "<<"for HP "<<boat[i][j][k]<<endl;
	}
	int xa,xb,ya,yb,za,zb,ht;
	for(int i=0;i<n;i++)
	{
		cin>>xa>>xb>>ya>>yb>>za>>zb>>ht;
		for(int ii=(xa>0?xa:0);ii<=(xb<A?xb:A);ii++)
		for(int iii=(ya>0?ya:0);iii<=(yb<B?yb:B);iii++)
		for(int iiii=(za>0?za:0);iiii<=(zb<C?zb:C);iiii++)
		{
			cout<<"attack boat "<<ii<<" "<<iii<<" "<<iiii<<" "<<"whose HP was "<<boat[ii][iii][iiii]<<"will be attacked for HP "<<ht<<endl;
			boat[ii][iii][iiii]-=ht;
			if(boat[ii][iii][iiii]<0)
			cout<<"in the Num."<<i+1<<" attack,"<<ii<<" "<<iii<<" "<<iiii<<" "<<"was ruined"<<",remain HP is "<<boat[ii][iii][iiii]<<endl;
		}
	}
 } 
 
