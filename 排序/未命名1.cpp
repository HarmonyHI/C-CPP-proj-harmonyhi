#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
    char word[1000][100]={{0},{0}},bkp[100],end[3];
    int num=0,i,iwei,iout,bschange[10000][20]={{0},{0}},ruler[10000][20]={{0},{1}};
    printf("����ֹͣ����ؼ��ʣ�������\n");
	scanf("%s",end);
	while(1)
	 {
	 	printf("��ǰ�����%d������\n����%sֹͣ���뿪ʼ����\n",num+1,end);
	 	scanf("%s",word[num]);
		if(strcmp(word[num],end)==0)
	 	break;
	 	for(i=0;i<20;i++)
	 	{
	 		if((word[num][i]>='A')&&(word[num][i]<='Z'))
	 		{
			 bschange[num][i]++;
			 word[num][i]=word[num][i]+('a'-'A');
			 }
		 }
	 	
		num++;
	 }
	for(iwei=19;iwei>=0;iwei--)
	for(iout=0;iout<num;iout++)
	for(i=0;i<num;i++)
	if ((word[i][iwei])>(word[i+1][iwei]))
	 {
	 	strcpy(bkp,word[i]);
	 	strcpy(word[i],word[i+1]);
	 	strcpy(word[i+1],bkp);
	 }
	
	 
	 printf("\n\n\n����ĸ��������\n"); 
	 
	 for(i=0;i<=num;i++)
	 {
	 if((strcmp(word[i],end)==0))
	 continue;
	 if((strcmp(word[i],word[i+1])!=0))
	 printf("%s\n",word[i]);
	 }
	 system("pause"); 
}

