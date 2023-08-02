#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int wherun(int year)
{
    if(((year%4==0)&&(year%100!=0))||(year%400==0))
        return 1;
    return 0;
}
int monshu(int year,int mon)
{
    if((mon==1)||(mon==3)||(mon==5)||(mon==7)||(mon==8)||(mon==10)||(mon==12))
        return 31;
    else if(mon==2)
    {
        if(wherun(year)==1)
            return 29;
        return 28;
    }
    else
        return 30;
}
int daydistance(int year,int mon,int day)
{
    int yearbk=year,dis=0;
    if((year>2017)||( year==2017)&&( mon>1)||( year==2017)&&( mon==1)&&( day>=1))
    {
    	   while(year>2017)
    {
        if(wherun(year-1)==1)
            dis=dis+366;
        else
            dis=dis+365;
        year--;
    }
    	   while(mon>1)
    {
        dis=dis+monshu(yearbk,mon-1);
        mon--;
    }
    while(day>1)
    {
        dis++;
        day--;
    }
    	}
 else
 {
 	   while(year<2016)
    {
   if(wherun(year+1)==1)
            dis=dis-366;
        else
            dis=dis-365;
        year++;
    }
 	    	 while( mon<12)
    	 {
    	 	dis= dis- monshu(yearbk,mon);
    	 	 mon++;
    	 	 }
    	 	 while(day<=31)
    	 	 {
    	 	 	dis--;
    	 	 	day++;
    	 	 	}
 	}
    return dis;
}


int dayweeker(int year,int mon,int day)
{
    int dwk,fu=0;
        dwk=daydistance(year,mon,day);
        if(dwk<0)
    {
        fu=1;
    }
    dwk=abs(dwk);
    while (dwk>=7)
        dwk=dwk-7;
    if(fu==1)
    {
    if(dwk==0)
    return 0;
    else
    return 7-dwk;
    	}
    else
        return dwk;
}
int main()
{
    int year,mon,i=1,iin;
    while(1)
    {
        if((scanf("%d%d",&year,&mon))==EOF)
            break;
        	while(mon>12)
        	mon=1;
        	 printf("Sun Mon Tue Wen Thu Fri Sat\n");



       
            for(iin=1; iin<=(dayweeker(year,mon,1)); iin++)
                printf("    ",dayweeker(year,mon,1));
        
       
   
        for(i=1; i<=monshu(year,mon); i++)
        {
            printf("%3d",i);
                if((dayweeker(year,mon,i)!=6)&&(i!=monshu(year,mon))) 
                    printf(" ");
                if((dayweeker(year,mon,i)==6)&&(i!=monshu(year,mon)))
                    printf("\n");
        }
        printf("\n\n");


    
    }
       
    return 0;
}
