#define STDYEAR 2017
#define STDMON 1
#define STDDAY 1
#define WEEK 7 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int frtdys;
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
long long int daydistance(int year,int mon,int day)
{
    int yearbk=year,dis=0;
    if((year>STDYEAR)||( year==STDYEAR)&&( mon>STDMON)||( year==STDYEAR)&&( mon==STDMON)&&( day>=STDDAY))
    {
        while(year>STDYEAR)
        {
            if(wherun(year-1)==1)
                dis=dis+366;
            else
                dis=dis+365;
            year--;
        }
        while(mon>STDMON)
        {
            dis=dis+monshu(yearbk,mon-1);
            mon--;
        }
        while(day>STDDAY)
        {
            dis++;
            day--;
        }
    }
    else
    {
        while(year<STDYEAR-1)
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
    if (day==1)
    {
        int dwk,fu=0;
        dwk=daydistance(year,mon,day);
        if(dwk<0)
        {
            fu=1;
        }
        dwk=abs(dwk);
        while (dwk>=WEEK)
            dwk=dwk-WEEK;
        if(fu==1)
        {
            if(dwk==0)
            {
                frtdys=0;
                return 0;
            }
            else
            {
                frtdys=WEEK-dwk;
                return frtdys;
            }

        }
        else
        {
            frtdys=dwk;
            return dwk;
        }
    }
    else
    {
        int mdd=day-1,fixout=frtdys+mdd;
        while(fixout>=WEEK)
            fixout=fixout-WEEK;
        return fixout;
    }
}
int main()
{
    int year,mon,i=1,iin,frtweeker;
    while(1)
    {
        if((scanf("%d%d",&year,&mon))==EOF)
            break;
        frtweeker=dayweeker(year,mon,1);
        printf("Sun Mon Tue Wen Thu Fri Sat\n");
        if(mon>12)
            mon=1;
        for(iin=1; iin<=frtweeker; iin++)
            printf("    ");
        for(i=1; i<=monshu(year,mon); i++)
        {
            if(i!=1)
                frtweeker=dayweeker(year,mon,i);
            printf("%3d",i);
            if((frtweeker!=6)&&(i!=monshu(year,mon)))
                printf(" ");
            if((frtweeker==6)&&(i!=monshu(year,mon)))
                printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
