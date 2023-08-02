#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//函数状态码定义
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;

//顺序表的存储结构定义
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef char* ElemType;  //假设线性表中的元素均为整型
typedef struct{
    ElemType* elem;   //存储空间基地址
    int length;       //表中元素的个数
    int listsize;     //表容量大小
}SqList;    //顺序表类型定义
Status ListInsert_Sq(SqList &L, int pos, ElemType e);
Status ListDelete_Sq(SqList &L, int pos, ElemType &e);
int ListLocate_Sq(SqList L, ElemType e);
void ListPrint_Sq(SqList L);

//结构初始化与销毁操作
Status InitList_Sq(SqList &L)
{
  //初始化L为一个空的有序顺序表
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}


int main() {
    SqList L;

    if(InitList_Sq(L)!= OK) {
        printf("InitList_Sq: 初始化失败！！！\n");
        return -1;
    }

   // for(int i = 1; i <= 10; ++ i)
   //     ListInsert_Sq(L, i, "Hello\n");

    int operationNumber;  //操作次数
    scanf("%d", &operationNumber);

    while(operationNumber != 0) {
        int operationType;  //操作种类
        scanf("%d", & operationType);

        if(operationType == 1) {  //增加操作
            int pos;
            char elem[20];
            scanf("%d%s", &pos, elem);
            ListInsert_Sq(L, pos, elem);
        } else if(operationType == 2) {  //删除操作
             int pos; ElemType elem;
             scanf("%d", &pos);
             ListDelete_Sq(L, pos, elem);
             printf("%d\n", elem);
        } else if(operationType == 3) {  //查找定位操作
            ElemType elem;
            scanf("%d", &elem);
            int pos = ListLocate_Sq(L, elem);
            if(pos >= 1 && pos <= L.length)
                printf("%d\n", pos);
            else
                printf("NOT FIND!\n");
        } else if(operationType == 4) {  //输出操作
            ListPrint_Sq(L);
        }
       operationNumber--;
    }
    return 0;
}
void swap(ElemType &a,ElemType &b)
{
	ElemType temp;
	temp=a;
	a=b;
	b=temp;
}
Status ListInsert_Sq(SqList &L, int pos, ElemType &e)
{
	for(int i=0;i<L.length;i++)
		(L.elem[i])=(char *)malloc(20);
	*(L.elem+L.length+1)=e;
	for(int i=(L.length-pos+1);i>=1;i--)
		swap(*(L.elem+i+pos-1),*(L.elem+i+pos));
	L.length++;
	return 0;
}
Status ListDelete_Sq(SqList &L, int pos, ElemType &e)
{
	e=*(L.elem+pos);
	for(int i=1;i<=(L.length-pos+1);i++)
		swap(*(L.elem+i+pos-1),*(L.elem+i+pos));
	L.length--;
	return 0;
}
int ListLocate_Sq(SqList L, ElemType e)
{
	for(int i=1;i<=L.length;i++)
	if (*(L.elem+i)==e)
	return i;
	return 0;
}
void ListPrint_Sq(SqList L)
{
	for(int i=1;i<=L.length;i++)
	{
		if(i!=1)
		printf(" ");
		printf("%s",L.elem+i);
	}
	printf("\n");
	
}
