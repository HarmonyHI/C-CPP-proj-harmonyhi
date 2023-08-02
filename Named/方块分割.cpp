#include<iostream>
#include<queue>
#include<algorithm>
#include<set>
#include<string.h>
using namespace std;

int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int vis[10][10];
int ans = 0;
void display(int map[][10])
{
	system("cls");
	for(int i=0;i<7;i++)
	{
		for(int ii=0;ii<7;ii++)
		{
			if(map[i][ii]==1)
			cout<<" I ";
			else
			cout<<"   ";
		}
		
		cout<<endl;
		cout<<" ";
		for(int ii=0;ii<7&&i!=6;ii++)
		cout<<" 0 ";
		cout<<endl;
	}
	system("pause");
	
}
void dfs(int x, int y)
{
	display(vis);
    if(x == 0 || y == 0 || x == 6 || y == 6)//�������߽�λ��
    {
        ans++;
        cout<<"GET"<<endl; 
        system("pause");
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];
        
        int x2 = 6 - x1;//�ԳƷ���
        int y2 = 6 - y1;
        
        if(x1 >= 0 && y1 >= 0 && x1 <= 6 && y1 <= 6)
        {
            if(!vis[x1][y1])//���ǶԳƵģ��ж�һ������
            {
                vis[x1][y1] = vis[x2][y2] = 1;
                dfs(x1,y1);
                vis[x1][y1] = vis[x2][y2] = 0;//����
            }
        }
    }
}
 
 
int main(){
    memset(vis, 0, sizeof(vis));
    vis[3][3] = 1;
    dfs(3,3);
    printf("%d\n",ans/4);//���·����ǶԳƵģ��ѵ�ʱ����ظ����㣬���ҷ���ͬ�����������Ҫ����4
    
    return 0;
}
