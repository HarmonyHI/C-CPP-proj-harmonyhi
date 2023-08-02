#include <stdio.h>
void getNextval(char T[],int TLength) {
    int nextval[TLength];
    nextval[0] = -1;
    printf("next[0] = %d \n", nextval[0]);
    int i = 0, j = -1; //i表示下标，初始化为0；j表示nextval数组的值，初始化为-1
    while (i < TLength-1) {

        if (j == -1 || T[i] == T[j]) {
            i++;
            j++;
            if(T[i] != T[j]) { //不同，该位置的nextval的值就是该位置的next值
                nextval[i] = j;
                printf("nextval[%d] = %d \n", i, nextval[i]);
            } else{ //相同，该位置的nextval的值就是该位置next值对应元素的nextval的值
                nextval[i] = nextval[j];
                printf("nextvl[%d] = %d \n", i, nextval[i]);
            }
        }else{
            j = nextval[j] ;
        }
    }
}


int main(){
    char T[] = {'a','b','c','a','b','a','a'};
    int TLength = 7;
    getNextval(T,7);
    return 0;
}

