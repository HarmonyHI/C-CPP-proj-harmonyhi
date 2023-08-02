#include <iostream>
#include<math.h>
using namespace std;
int n;
int map[9][9];
int bq[9], wq[9];
//定义bq，wq分别用于存储 在每一行都在哪一个位置摆放了黑（black queen），白皇后 (write queen)
//设bq[i]=j，则表示第i列的黑皇后放在第j行上
int sum = 0;
bool Ispos(int cur, int* q)//判断皇后是否满足条件
{
	for (int i = 1; i < cur; i++)
		if (q[i] == q[cur] || (abs(i - cur) == abs(q[i] - q[cur])))
			return false;
			//若有一个满足上面的条件的，就会返回false
	return true;
}
void WQ(int cur)
{
	if (cur == n + 1)//白皇后也全部放置，次数+1
		sum++;
	for (int i = 1; i <= n; i++)
	{
		if (bq[cur] == i)continue;//判断是否黑皇后已摆放的位置 
		if (map[cur][i] == 0)continue;
		wq[cur] = i;
		if (Ispos(cur, wq))
			WQ(cur + 1);
	}
}
void BQ(int cur)
{
	if (cur == n + 1) //若黑皇后放置完，再处理白皇后
		WQ(1);
	for (int i = 1; i <= n; i++)
	{
		if (map[cur][i] == 0)continue;//若map对应的位置为0,即不能放置皇后 ，跳过这次循环 
		bq[cur] = i;
		if (Ispos(cur, bq))
			BQ(cur + 1);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)// i = 1为了与一般认识一样
		for (int j = 1; j <= n; j++)// j = 1为了与一般认识一样
			cin >> map[i][j];
	BQ(1);//执行摆放黑皇后函数（当然先摆放白皇后也行，不过要改一些），
	//里面是1，表示从第1列开始,放置
	cout << sum;
	return 0;
}
//4
//1 1 1 1
//1 1 1 1
//1 1 1 1
//1 1 1 1