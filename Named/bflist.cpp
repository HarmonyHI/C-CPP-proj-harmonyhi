#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

//����״̬�붨��
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int  Status;

//˳���Ĵ洢�ṹ����
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10
typedef char* ElemType;  //�������Ա��е�Ԫ�ؾ�Ϊ����
typedef struct{
    ElemType* elem;   //�洢�ռ����ַ
    int length;       //����Ԫ�صĸ���
    int listsize;     //��������С
}SqList;    //˳������Ͷ���
Status ListInsert_Sq(SqList &L, int pos, ElemType e);
Status ListDelete_Sq(SqList &L, int pos, ElemType &e);
int ListLocate_Sq(SqList L, ElemType e);
void ListPrint_Sq(SqList L);

//�ṹ��ʼ�������ٲ���
Status InitList_Sq(SqList &L)
{
  //��ʼ��LΪһ���յ�����˳���
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)exit(OVERFLOW);
    L.listsize=LIST_INIT_SIZE;
    L.length=0;
    return OK;
}


int main() {
    SqList L;

    if(InitList_Sq(L)!= OK) {
        printf("InitList_Sq: ��ʼ��ʧ�ܣ�����\n");
        return -1;
    }

   // for(int i = 1; i <= 10; ++ i)
   //     ListInsert_Sq(L, i, "Hello\n");

    int operationNumber;  //��������
    scanf("%d", &operationNumber);

    while(operationNumber != 0) {
        int operationType;  //��������
        scanf("%d", & operationType);

        if(operationType == 1) {  //���Ӳ���
            int pos;
            char elem[20];
            scanf("%d%s", &pos, elem);
            ListInsert_Sq(L, pos, elem);
        } else if(operationType == 2) {  //ɾ������
             int pos; ElemType elem;
             scanf("%d", &pos);
             ListDelete_Sq(L, pos, elem);
             printf("%d\n", elem);
        } else if(operationType == 3) {  //���Ҷ�λ����
            ElemType elem;
            scanf("%d", &elem);
            int pos = ListLocate_Sq(L, elem);
            if(pos >= 1 && pos <= L.length)
                printf("%d\n", pos);
            else
                printf("NOT FIND!\n");
        } else if(operationType == 4) {  //�������
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
