#include<iostream>
using namespace std;
int maxer(int *data,int n)
{
	int con=data[0],tik=0;
	for(int i=1;i<n;i++)
	{
		if(data[i]>con)
		{
			con=data[i];
			tik=i;
		}
	}
	return tik;
}
class checkdot
{
	public:
		int data;
};
class pic
{
	public:
		int **activechart;
		bool *vis;
		checkdot *dot;
		int dotnum;
		pic(int dotn)
		{
			vis=new bool[dotn];
			for(int i=0;i<dotn;i++)
			vis[i]=false;
			dotnum=dotn;
			activechart=new int*[dotn];
			for(int i=0;i<dotn;i++)
			activechart[i]=new int[dotn];
			dot=new checkdot[dotn];
			for(int i=0;i<dotn;i++)
			for(int ii=0;ii<dotn;ii++)
			activechart[i][ii]=-1;
			for(int i=0;i<dotn;i++)
			activechart[i][i]=0;
			for(int i=0;i<dotn;i++)
				dot[i].data=i;
			
		}	
};
void for_test_readpic(pic &tmp)
{
	for(int i=0;i<tmp.dotnum;i++)
	{
	for(int ii=0;ii<tmp.dotnum;ii++)
	cout<<tmp.activechart[i][ii]<<" ";
	cout<<endl;	
	}
	cout<<endl;
}
void ban_the_unimportant(pic &tmp)
{
	for(int i=0;i<tmp.dotnum;i++)
	{
		int maxitick=maxer(tmp.activechart[i],tmp.dotnum);
		for(int ii=0;ii<tmp.dotnum;ii++)
		if(ii!=maxitick)
		tmp.activechart[i][ii]=-1;	
	}
}
int read_all_road_in_pic_and_cal(pic &tmp,bool Isview)
{
	ban_the_unimportant(tmp);
	int sum=0,bef=0;
	for(int i=0;;)
	{
		if(tmp.vis[i]==true)
			return 0;
		if(i!=0)
		{
			if(Isview)
			cout<<bef<<"->"<<i+1<<endl;	
			sum=sum+tmp.activechart[bef-1][i];		
		}
		bef=i+1;
		tmp.vis[i]=true;
		if(i==tmp.dotnum-1)
			break;
		i=maxer(tmp.activechart[i],tmp.dotnum);
	}
	return sum;	
}
int main()
{
	int m,n;
	cin>>m>>n;
	pic ting(m),bkp(m);
	for(int i=0;i<n;i++)
			{
				int st,en,hvy;
				cin>>st>>en>>hvy;
				ting.activechart[st-1][en-1]=hvy;
				bkp.activechart[st-1][en-1]=hvy;
			}
	cout<<read_all_road_in_pic_and_cal(ting,false)<<endl;
	read_all_road_in_pic_and_cal(bkp,true);
}
