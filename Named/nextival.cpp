#include <stdio.h>
void getNextval(char T[],int TLength) {
    int nextval[TLength];
    nextval[0] = -1;
    printf("next[0] = %d \n", nextval[0]);
    int i = 0, j = -1; //i��ʾ�±꣬��ʼ��Ϊ0��j��ʾnextval�����ֵ����ʼ��Ϊ-1
    while (i < TLength-1) {

        if (j == -1 || T[i] == T[j]) {
            i++;
            j++;
            if(T[i] != T[j]) { //��ͬ����λ�õ�nextval��ֵ���Ǹ�λ�õ�nextֵ
                nextval[i] = j;
                printf("nextval[%d] = %d \n", i, nextval[i]);
            } else{ //��ͬ����λ�õ�nextval��ֵ���Ǹ�λ��nextֵ��ӦԪ�ص�nextval��ֵ
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

