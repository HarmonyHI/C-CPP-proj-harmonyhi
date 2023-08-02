#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
void setting(char *name,int &ranker)
{
	char space=32;
    ranker=0;
    for(int i=0;;i++)
        if(name[i]==space)
    	ranker++;
       else
     return;
    	

}
int finder(char *s,char (*box)[20],int namen)
{
for(int i=0;i<namen;i++)
{
	//cout<<"find "<<s<<" and "<<box[i]<<endl;
	if(!strcmp(s,box[i]))
	return i;
	}
return -1;
}
bool Isuncle(int *box,int a,int b)
{
	int t;
if(a>b)
{
	t=a;
	a=b;
	b=t;
	}
	for(int i=a;i<b;i++)
	{
		if(box[i]>box[i+1])
		return true;
		}
	return false;
}
bool picker(int a,int b,bool Isuncle,char *relation)
{
if(!strcmp(relation,"child"))
{
	if(a==(b+2)&&!Isuncle)
	return true;
	//else
	//printf("%d %d %d",a,b,Isuncle);
	}
else if(!strcmp(relation,"parent"))
{
	if(a==(b-2)&&!Isuncle)
	return true;
	}
else if(!strcmp(relation,"sibling"))
{
	if(a==b)
	return true;
	}
else if(!strcmp(relation,"descendant"))
{
	if(a>=(b-2)&&!Isuncle)
	return true;
	}
else if(!strcmp(relation,"ancestor"))
{
	if(a<=(b-2)&&!Isuncle)
	return true;
	}
else;
return false;
}
void removespace(char *s)
{
	char *tmp;
	int length=strlen(s);
	tmp=new char[100];
	int i=0,ii=0;
	for(;i<length;i++)
	{
		if(s[i]!=32)
		break;
		}
	for(;i<length;i++,ii++)
		tmp[ii]=s[i];
		tmp[ii]=0;
	strcpy(s,tmp);
	}
int main()
{
    int namen,stnsn,ranker[100];
    char name[100][20],dealtmp[20];
    scanf("%d%d",&namen,&stnsn);
    getchar();
    for(int i=0;i<namen;i++)
    {	
        cin.getline(dealtmp,1000);
        setting(dealtmp,ranker[i]);//setting实现读取空格数判断等级并存入第二数组
        //cout<<"data is "<<ranker[i]<<endl;
        removespace(dealtmp);
        strcpy(name[i],dealtmp);
    }
    for(int i=0;i<stnsn;i++)
    {
    	if(i!=0)
    	cout<<endl;
        char admin[20],guest[20],relation[20],useless[20];
        int adminpos,guestpos;
        scanf("%s%s%s%s%s%s",admin,useless,useless,relation,useless,guest);
        adminpos=finder(admin,name,namen);
        guestpos=finder(guest,name,namen);
		if(adminpos==-1||guestpos==-1)
		cout<<"False";
        else if(picker(ranker[adminpos],ranker[guestpos],Isuncle(ranker,adminpos,guestpos),relation))
            cout<<"True";
        else
        {
        	//cout<<"info "<<ranker[adminpos]<<" "<<ranker[guestpos]<<" "<<(int)Isuncle(ranker,adminpos,guestpos)<<" "<<relation<<endl;
        	cout<<"False";
        	}
            
            //finder返回输入名字在数组中的位置
            //Isuncle判断两个位置之间ranker是否是递减，如果不满足关系就是叔而不是父母等
            //picker根据ranker的等级关系和Isuncle返回的亲生关系来判断是否与relation对应
    }
}

