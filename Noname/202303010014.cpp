#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<bits/stdc++.h>
using namespace std;

// 定义一个函数，用来检查s是否是t的子串
bool is_substring(char *s, char *t) {
	string sm=new string(s);
	string bg=new string(t);
	int idx=bg.find(sm);
	if(idx==string::npos){
		return true;
	}
	return false;
}

// 定义一个函数，用来生成FB-string
void generate_fb_string(char *fb_string, int n) {
  // 初始化为空串
  fb_string[0] = '\0';

  // 遍历1到n之间所有正整数
  for (int i = 1; i <= n; i++) {
    // 如果i能被3整除，则在末尾追加F
    if (i % 3 == 0) {
      strcat(fb_string, "F");
    }
    // 如果i能被5整除，则在末尾追加B
    if (i % 5 == 0) {
      strcat(fb_string, "B");
    }
    // 注意如果i能同时被3和5整除，则会先追加F再追加B
  }
}

// 主函数入口
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
