#include <stdio.h>

//typedef enum {false, true} bool;
#define MaxVertexNum 10   /* ��󶥵�����Ϊ10 */
typedef int Vertex;       /* �ö����±��ʾ����,Ϊ���� */

/* �ڽӵ�Ķ��� */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* �ڽӵ��±� */
    PtrToAdjVNode Next; /* ָ����һ���ڽӵ��ָ�� */
};

/* �����ͷ���Ķ��� */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* �߱�ͷָ�� */
} AdjList[MaxVertexNum];     /* AdjList���ڽӱ����� */

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* ������ */
    int Ne;     /* ����   */
    AdjList G;  /* �ڽӱ� */
};
typedef PtrToGNode LGraph; /* ���ڽӱ�ʽ�洢��ͼ���� */

bool Visited[MaxVertexNum]; /* ����ķ��ʱ�� */

LGraph CreateGraph(); /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}



/* ��Ĵ��뽫��Ƕ������ */
#include<malloc.h>
LGraph CreateGraph()
{
	
	GNode *ting;
	ting=(GNode*)malloc(sizeof(GNode));
	(*ting).G[0].FirstEdge=(AdjVNode*)malloc(sizeof(AdjVNode));
	AdjVNode *temp=(*ting).G[0].FirstEdge;
	(*temp).AdjV=0;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=2;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=3;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=4;
	(*temp).Next=NULL;
	
	(*ting).G[1].FirstEdge=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*ting).G[1].FirstEdge;
	(*temp).AdjV=1;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=3;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=5;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	(*temp).Next=NULL;
		
	(*ting).G[2].FirstEdge=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*ting).G[2].FirstEdge;
	(*temp).AdjV=2;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=0;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=3;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=5;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	(*temp).Next=NULL;
		
	(*ting).G[3].FirstEdge=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*ting).G[3].FirstEdge;
	(*temp).AdjV=3;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=0;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=1;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=2;
	(*temp).Next=NULL;
	
	(*ting).G[4].FirstEdge=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*ting).G[4].FirstEdge;
	(*temp).AdjV=4;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=0;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=5;
	(*temp).Next=NULL;
	
	(*ting).G[5].FirstEdge=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*ting).G[5].FirstEdge;
	(*temp).AdjV=5;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=1;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=2;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=4;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=6;
	(*temp).Next=NULL;
	
	(*ting).G[6].FirstEdge=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*ting).G[6].FirstEdge;
	(*temp).AdjV=6;
	(*temp).Next=(AdjVNode*)malloc(sizeof(AdjVNode));
	temp=(*temp).Next;
	(*temp).AdjV=5;
	(*temp).Next=NULL;
	for(int i=0;i<7;Visited[i]=false,i++);
	return ting;
} /* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */
typedef struct listdot
{
	int ting;
	struct listdot *next;
}Listdot;
typedef struct queue
{
	Listdot *head,*end;
}Queue;
void queuein(Queue *temp,int a)
{
	//printf("%d�������\n",a);
	if((*temp).end!=NULL)
	{	
		(*(*temp).end).next=(Listdot*)malloc(sizeof(Listdot));
		(*(*(*temp).end).next).next=NULL;
		(*(*(*temp).end).next).ting=a;
		(*temp).end=(*(*temp).end).next;
	}
	else
	{
		(*temp).head=(Listdot*)malloc(sizeof(Listdot));
		(*(*temp).head).next=NULL;
		(*(*temp).head).ting=a;
		(*temp).end=(*temp).head;
	}
}
int queueout(Queue *temp)
{
	
	int bkp=(*(*temp).head).ting;
	//printf("���е���%d\n",bkp);
	if((*(*temp).head).next==NULL)
	{
		(*temp).head=NULL;
		(*temp).end=NULL;
	}
	else
	(*temp).head=(*(*temp).head).next;	
	return bkp;
}
int Isqueueempty(Queue *temp)
{
	if((*temp).end==NULL&&(*temp).head==NULL)
	return 1;	
	return 0;
}
void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{//printf("--------������һ��\n"); 
	//printf("BFS%d\n�½�����\n",S);
	Queue picker;
	picker.end=NULL;
	picker.head=NULL;
	PtrToAdjVNode temp=(*Graph).G[S].FirstEdge;
	while(1)
	{	
		if((*temp).AdjV!=S&&Visited[(*temp).AdjV]==false)
		queuein((&picker),(*temp).AdjV);
		if(Visited[(*temp).AdjV]==false)
		{
			Visit((*temp).AdjV);
			//printf("����%d\n",(*temp).AdjV);
			Visited[(*temp).AdjV]=true;
		}
		if(1)
		{
		if((*temp).Next!=NULL)
		temp=(*temp).Next;

		else
		break;	
		
		}
		//getchar();
		
	}
	while(Isqueueempty(&picker)==0)
	{
		
	BFS(Graph,queueout((&picker)),Visit);	
	//printf("--------������һ��\n"); 
	}
	
}
