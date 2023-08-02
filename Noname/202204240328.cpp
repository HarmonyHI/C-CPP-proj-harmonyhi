#include<stdio.h>
#include<string.h>
char* add(char *a,char *b)
{
	int data1[strlen(a)+10],data2[strlen(b)+10],tmpans[strlen(a)>strlen(b)?(strlen(a)+10):(strlen(b)+10)];
	for(int i=0;i<(strlen(a)>strlen(b)?(strlen(a)+10):(strlen(b)+10));i++)
	{
		data1[i]=0;
		data2[i]=0;
	}
	for(int i=0;i<(strlen(a)>strlen(b)?(strlen(a)+10):(strlen(b)+10));i++)
	tmpans[i]=-1;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='0'&&a[i]<'a')
			data1[i]=a[i]-'0';
		else
			data1[i]=a[i]-'a'+10;
	}
	for(int i=0;i<strlen(b);i++)
	{
		if(b[i]>='0'&&b[i]<'a')
			data2[i]=b[i]-'0';
		else
			data2[i]=b[i]-'a'+10;
	}

	int tmpreverse[strlen(a)>strlen(b)?(strlen(a)+10):(strlen(b)+10)],ctr=0;
	for(int i=0;i<(strlen(a)>strlen(b)?(strlen(a)+10):(strlen(b)+10));i++)
	tmpreverse[i]=0;
	for(int i=strlen(a)-1;i>=0;i--)
	tmpreverse[ctr++]=data1[i];
	for(int i=0;i<ctr;i++)
	data1[i]=tmpreverse[i];
	ctr=0;
	for(int i=strlen(b)-1;i>=0;i--)
	tmpreverse[ctr++]=data2[i];
	for(int i=0;i<ctr;i++)
	data2[i]=tmpreverse[i];
	ctr=0;
	

	
	
	for(int i=0;i<(strlen(a)>strlen(b)?strlen(a):strlen(b));i++)
	{
		if(tmpans[i]==-1)
		tmpans[i]=data1[i]+data2[i];
		else
		tmpans[i]+=(data1[i]+data2[i]);
		if(tmpans[i]>35)
		{
		tmpans[i]=tmpans[i]%36;
		if(tmpans[i+1]==-1)
		tmpans[i+1]=0;
		tmpans[i+1]++;	
		}
	}
	

	int valuepos=0;
	for(int i=0;tmpans[i]!=-1;i++)
	valuepos++;
	for(int i=valuepos-1;i>=0;i--)
		tmpreverse[ctr++]=tmpans[i];
	for(int i=0;i<valuepos;i++)
		tmpans[i]=tmpreverse[i];
		
//	for(int i=0;tmpans[i]!=-1;i++)
//		printf("%d ",tmpans[i]);
//	
	for(int i=0;i<valuepos;i++)
	{
		if(tmpans[i]>=0&&tmpans[i]<=9)
		a[i]=tmpans[i]+'0';
		else
		a[i]=tmpans[i]-10+'a';
	}
	a[valuepos]=0;
	return a;
} 