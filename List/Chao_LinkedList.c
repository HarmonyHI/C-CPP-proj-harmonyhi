#include<stdio.h>
#include<stdlib.h>
#define DATATPE int
#define null 0
typedef enum status{
	OKAY=0,
	FAIL=-1
}status;
typedef struct ListNode{
	DATATPE data;
	struct ListNode* next;
	struct ListNode* upon;
}ListNode; 
typedef struct LinkedList{
	ListNode* head;
	ListNode* nail;
	int length;
}LinkedList;
void InitListNode(ListNode* node, DATATPE data){
	node->next = null;
	node->upon = null;
	node->data = data;
}
void InitLinkedList(LinkedList* linkedlist){
	linkedlist->head = (ListNode*)malloc(sizeof(ListNode));
	InitListNode(linkedlist->head, 0);
	linkedlist->nail = linkedlist->head;
	linkedlist->length = 0;
}
void DestoryLinkedList(LinkedList* linkedlist){
	ListNode* curNode = linkedlist->head;
	while(curNode->next != null){
		ListNode* bkp = curNode->next;
		free(curNode);
		curNode = bkp;
	}
}
status LinkedListInsert(LinkedList* linkedlist, int position, DATATPE data){
	if(position == -1){
		ListNode* curNode = linkedlist->nail;
		curNode->next = (ListNode*)malloc(sizeof(ListNode));
		InitListNode(curNode->next, data);
		ListNode* bkp = curNode;
		curNode = curNode->next;
		curNode->upon = bkp;
		linkedlist->nail = curNode;
	}
	else if(position <= (linkedlist->length)){
		ListNode* curNode = linkedlist->head;
		if(position<0||position>(linkedlist->length)){
			return FAIL;
		}
		int i=0;
		for(int i=0;i<position;i++){
			curNode = curNode->next;
		}
		ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
		InitListNode(newNode, data);
		newNode->next = curNode->next;
		newNode->upon = curNode;
		newNode->upon->next = newNode;
		if(newNode->next == NULL){
			linkedlist->nail = newNode;
		}
		else{
			newNode->next->upon = newNode;
		}
	}
	else{
		return FAIL;
	}
	linkedlist->length++;
	return OKAY;
	
}
status LinkedListDelete(LinkedList* linkedlist, int position){
	ListNode* curNode = linkedlist->head->next;
	if(curNode==null||position<0||position>=(linkedlist->length)){
		return FAIL;
	}
	for(int i=0;i<position;i++){
		curNode = curNode->next;
	}
	curNode->upon->next = curNode->next;
	if(curNode->next == null){
		linkedlist->nail = curNode->upon;
	}
	else{
		curNode->next->upon = curNode->upon;
	}
	free(curNode);
	linkedlist->length--;
	return OKAY;
}
status LinkedListEdit(LinkedList* linkedlist, int position, DATATPE data){
	ListNode* curNode = linkedlist->head->next;
	if(curNode==null||position<0||position>=(linkedlist->length)){
		return FAIL;
	}
	for(int i=0;i<position;i++){
		curNode = curNode->next;
	}
	curNode->data = data;
	return OKAY;
}
DATATPE LinkedListGetData(LinkedList* linkedlist, int position){
	ListNode* curNode = linkedlist->head->next;
	if(curNode==null||position<0||position>=(linkedlist->length)){
		return FAIL;
	}
	for(int i=0;i<position;i++){
		curNode = curNode->next;
	}
	return curNode->data;
}
int LinkedListGetPosition(LinkedList* linkedlist, DATATPE data){
	ListNode* curNode = linkedlist->head->next;
	int i=0;
	while(curNode!=NULL){
		if(curNode->data==data){
			return i;
		}
		i++;
		curNode = curNode->next;
	}
	return -1;
}
void ShowLinkedList(LinkedList* linkedlist){
	ListNode* curNode = linkedlist->head;
	while(curNode->next!=null){
		curNode = curNode->next;
		printf("%d ", curNode->data);
	}
	printf("\n");
}
int main(){
	LinkedList myLinkedList;
	InitLinkedList(&myLinkedList);
	while(1){
		int op;
		scanf("%d",&op);
		if(op==1){
			DATATPE mydata;
			int position;
			scanf("%d%d", &position, &mydata);
			if(LinkedListInsert(&myLinkedList,position,mydata) == OKAY){
				printf("OKAY\n");
			}
			else{
				printf("FAIL\n");
			}
		}
		else if(op==2){
			int position;
			scanf("%d", &position);
			if(LinkedListDelete(&myLinkedList,position) == OKAY){
				printf("OKAY\n");
			}
			else{
				printf("FAIL\n");
			}
		}
		else if(op==3){
			DATATPE mydata;
			int position;
			scanf("%d%d", &position, &mydata);
			if(LinkedListEdit(&myLinkedList,position,mydata) == OKAY){
				printf("OKAY\n");
			}
			else{
				printf("FAIL\n");
			}
		}
		else if(op==4){
			int position;
			scanf("%d", &position);
			printf("%d\n", LinkedListGetData(&myLinkedList,position));
		}
		else if(op==5){
			DATATPE mydata;
			scanf("%d", &mydata);
			printf("%d\n", LinkedListGetPosition(&myLinkedList,mydata));
		}
		else if(op==6){
			ShowLinkedList(&myLinkedList);
		}
		else if(op==7){
			DestoryLinkedList(&myLinkedList);
			InitLinkedList(&myLinkedList);
			printf("OKAY\n");
		}
		else{
			printf("INVALID OP\n");
		}
	}

	return 0;
} 
