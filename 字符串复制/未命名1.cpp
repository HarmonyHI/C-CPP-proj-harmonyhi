#include<stdio.h>
#define MAX_STR_LEN 201
char * str_cpy(char * t, char * s)
{
	char *bk;
	bk=s;
	while(*s!=0)
	{
	*t=*s;
	t++;
	s++;
	}
	t=0;
	return bk;
}
int main()
{
    char s[MAX_STR_LEN], str[MAX_STR_LEN], *p;
    while(gets(s) != NULL)
    {
        p = str_cpy(str, s);
        puts(p);
        puts(str);
    }
    return 0;
}
