#include<stdio.h>
#include<math.h>
unsigned long long int single(unsigned long long int a)
{
       for(unsigned long long int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return 0;  
        }
    }
    return 1;
}
unsigned long long int minbreaker(unsigned long long int a)
{
    unsigned long long int pin;
    for(unsigned long long int pin=2;pin<=a;pin++)
    {
        if((a%pin==0)&&(single(pin)==1))
        return pin;
    }
}
int main()
{
    unsigned long long int a,b;
    scanf("%llu",&a);
    b=minbreaker(a);
    printf("%llu",a/b);	
}
