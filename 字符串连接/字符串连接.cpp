#include<stdio.h>
#define MAX_STR_LEN 255
char * str_cat(char * t, char * s)
{
	char *bk;
	bk=t;
	while(*t!=0)
	t++;
	while(*s!=0)
	{
		*t=*s;
		t++;
		s++;
	}
	*t=0;
	return bk;
}
int main()
{
    char s[MAX_STR_LEN], str[MAX_STR_LEN], *p;
    while(gets(s) != NULL && gets(str) != NULL)
    {
        p = str_cat(str, s);
        puts(p);
        puts(str);
    }
    return 0;
}
