#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<bits/stdc++.h>
using namespace std;

// ����һ���������������s�Ƿ���t���Ӵ�
bool is_substring(char *s, char *t) {
	string sm=new string(s);
	string bg=new string(t);
	int idx=bg.find(sm);
	if(idx==string::npos){
		return true;
	}
	return false;
}

// ����һ����������������FB-string
void generate_fb_string(char *fb_string, int n) {
  // ��ʼ��Ϊ�մ�
  fb_string[0] = '\0';

  // ����1��n֮������������
  for (int i = 1; i <= n; i++) {
    // ���i�ܱ�3����������ĩβ׷��F
    if (i % 3 == 0) {
      strcat(fb_string, "F");
    }
    // ���i�ܱ�5����������ĩβ׷��B
    if (i % 5 == 0) {
      strcat(fb_string, "B");
    }
    // ע�����i��ͬʱ��3��5�����������׷��F��׷��B
  }
}

// ���������
int main() {
  
   int t; 
   scanf("%d", &t); 
   while(t--) { 
     int k; 
     char s[11]; 
     scanf("%d", &k); 
     scanf("%s", s); 

     char fb_string[10001]; 
     generate_fb_string(fb_string,10000); 

     if(is_substring(s,fb_string)) { 
       printf("YES\n"); 
     } else { 
       printf("NO\n"); 
     } 

   } 

   return(0);
}
