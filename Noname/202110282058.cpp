#include<stdio.h>
int dayweeker(int year,int mon,int day)
{
    if (day==1)
    {
        int dwk,fu=0;

        if(dwk<0)
        {
            fu=1;
        }
   
    
        if(fu==1)
        {
            if(dwk==0)
            {
                
                return 0;
            }
            else
            {

            }
  
        }
        else
        {
        
        }
    }
    else
    {
  
   
    }
}
int main()
{
    int a, b, c, d, m, n;
    scanf("COCK,HEN,CHICK,MONEY,CHICKS");
    while(scanf("%d,%d,%d/%d,%d,%d", &a, &b, &c, &d, &m, &n) != EOF)
    {
        int ok=0;
            for(int i = 0; i <= n; i++)
            {
                int x = i;
                int z = d * (m - b * n - a * x + b * x) / (c - b * d);
                int y = n - x - z;
                if(x >= 0&& y >= 0&& z>= 0&& a * d * x + b * d * y + c * z == d * m)
                {
                    if(!ok)
                        printf("COCKS,HENS,CHICKS\n");
                    ok = 1;
                    printf("%d,%d,%d\n", x, y, z);
                }
            }
        if(!ok)
            printf("Cannot buy!\n");
        printf("\n");
    }
}
