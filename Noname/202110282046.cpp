#include<stdio.h>
int main()
{
    char s[40];
    scanf("%s",s);
    int boy,girl,sona,sonb,money,num,find,iu=0;
    while(scanf("%d,%d,%d/%d,%d,%d",&boy,&girl,&sona,&sonb,&money,&num)!=EOF)
    {
    	
		if(iu!=0)
    	printf("\n");
    	int t;
    	if(find==0&&(iu!=0));
    	else
    	printf("COCKS,HENS,CHICKS\n");
		find=0;
		for(int i=num;i>=0;i--)
		for(int ii=num;ii>=0;ii--)
		for(int iii=num;iii>=0;iii--)
    		if(i*girl+ii*(double)(sona)/sonb+iii*boy==money&&i+ii+iii==num)
    		{
    			find=1;
    			printf("%d,%d,%d\n",iii,i,ii);
    			iu++;
			}
    		if(find==0)
    		{
    		printf("Cannot buy!\n");
    		iu++;	
			}
    		
	}
    
}
