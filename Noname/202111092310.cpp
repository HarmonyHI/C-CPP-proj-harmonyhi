#include <stdio.h>

//typedef enum {false, true} bool;
#define MaxVertexNum 10   /* 最大顶点数设为10 */
typedef int Vertex;       /* 用顶点下标表示顶点,为整型 */

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

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



/* 你的代码将被嵌在这里 */
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
} /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */
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
	//printf("%d进入队列\n",a);
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
	//printf("队列弹出%d\n",bkp);
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
{//printf("--------进入下一层\n"); 
	//printf("BFS%d\n新建队列\n",S);
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
			//printf("访问%d\n",(*temp).AdjV);
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
	//printf("--------返回上一层\n"); 
	}
	
}
