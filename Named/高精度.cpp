#include<bits/stdc++.h>
using namespace std;
class mynum
{
    public:
        char data[91];
        mynum(int temp)
        {
        for(int i=0;i<91;i++)
            data[i]='0';
        data[90]=0;
        int ctr=89;
        while(temp!=0)
        {
            data[ctr--]=temp%10+'0';
            temp=temp/10;
         } 
        }
        void print()
        {
        int ctr=0;
        while(1)
        {
            if(data[++ctr]!='0')
            break;
        }
        for(int i=ctr;data[i]!=0;i++)
        cout<<data[i];
        if(ctr==89&&data[89]=='0')
        cout<<"a";
        cout<<endl;
        }
        void plus(mynum a)
        {
        int tmp1[91],tmp2[91];
        for(int i=0;i<90;i++)
        {
            tmp1[i]=data[i]-'0';
            tmp2[i]=a.data[i]-'0';
        }
        for(int i=0;i<90;i++)
        tmp1[i]=tmp1[i]+tmp2[i];
        for(int i=89;i>=0;i--)
        while(tmp1[i]>9)
        {
            tmp1[i-1]++;
            tmp1[i]=tmp1[i]-10;
        }
        for(int i=0;i<90;i++)
        data[i]=tmp1[i]+'0';
        }
        void multi(int a)
        {
            int tmp1[90];
        for(int i=89;i>=0;i--)
            tmp1[i]=data[i]-'0';
        for(int i=89;i>=0;i--)
            tmp1[i]=tmp1[i]*a;
        for(int i=89;i>0;i--)
            if(tmp1[i]>9)
            {
                tmp1[i-1]=tmp1[i-1]+tmp1[i]/10;
                tmp1[i]=tmp1[i]%10;
            }
        for(int i=89;i>=0;i--)
        data[i]=tmp1[i]+'0';
        }
        
};
mynum jiec(int a)
{
    //cout<<"deal"<<a;
    mynum ans(a);
    while(a!=1)
        ans.multi(--a);
    //cout<<"return ";
    //ans.print();
    //cout<<endl;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    mynum ans(0);
    for(int i=1;i<=n;i++)
    ans.plus(jiec(i));
    ans.print();
//    mynum one(16),two(29);
//    one.plus(two);
//    one.multi(70001);
//    one.multi(70003);
//    one.multi(70007);
//    one.multi(70007);
//    one.print();
 }
