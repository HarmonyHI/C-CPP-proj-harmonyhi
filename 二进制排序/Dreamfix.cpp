#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
int cifang2(int a)    
{
	int i,ting;
	for(i=0,ting=1;i<a;i++)
		ting=ting*2;
	return ting;
}
int deal(int a)    
{
    int p=0,maxdeal=11;       
    	while(a>0)
		{
			if(a-cifang2(maxdeal)>=0)
			{
				a=a-cifang2(maxdeal);
				p++;
			}
			maxdeal--;
		 } 
        return p;
}
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int i,a[10],b[10],ii,tik=0;      
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);    
    for(i=0;i<10;i++)
    	b[i]=deal(a[i]);   
    for(i=0;i<10;i++)      
        for(ii=0;ii<10;ii++)
        {
            if(b[ii]>b[ii+1])
        		{
            		swap(&a[ii],&a[ii+1]);
            		swap(&b[ii],&b[ii+1]);
        		}
       		 if(b[ii]==b[ii+1])
            	if(a[ii]>a[ii+1])
            		swap(&a[ii],&a[ii+1]);
        }
        for(i=0;i<10;i++)
            {
                if(tik!=0)
                    printf(" ");
                printf("%d",a[i]);
                tik++;
            }
	printf("\n"); 
	system("pause");
	return 0;
}
