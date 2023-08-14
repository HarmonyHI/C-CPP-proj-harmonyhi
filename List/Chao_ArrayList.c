#include<stdio.h>
#include<stdlib.h>
#define DATATPE int
#define MAXSIZE 100
typedef enum status{
	OKAY,
	FAIL
}status;
typedef struct ArrayList{
	DATATPE *data;
	int length;
}ArrayList;
void InitArrayList(ArrayList* arraylist){
	arraylist->data = (DATATPE*)malloc(sizeof(DATATPE)*MAXSIZE);
	arraylist->length = 0;
}
void DestoryArrayList(ArrayList* arraylist){
	free(arraylist->data);
}
status ArrayListInsert(ArrayList* arraylist, DATATPE data){
	if(arraylist->length>=MAXSIZE){
		return FAIL;
	}
	arraylist->data[arraylist->length] = data;
	arraylist->length++;
	return OKAY;
}
status ArrayListDelete(ArrayList* arraylist, int position){
	if(position<0||position>=(arraylist->length)){
		return FAIL;
	}
	for(int i=position;i<arraylist->length-1;i++){
		arraylist->data[i] = arraylist->data[i+1];
	}
	arraylist->length--;
	return OKAY;
}
status ArrayListEdit(ArrayList* arraylist, int position, DATATPE data){
	if(position<0||position>=(arraylist->length)){
		return FAIL;
	}
	arraylist->data[position] = data;
	return OKAY;
}
DATATPE ArrayListGetData(ArrayList* arraylist, int position){
	if(position<0||position>=(arraylist->length)){
		return 0;
	}
	return arraylist->data[position];
}
int ArrayListGetPosition(ArrayList* arraylist, DATATPE data){
	for(int i=0;i<arraylist->length;i++){
		if(arraylist->data[i]==data){
			return i;
		}
	}
	return -1;
}
void ShowArrayList(ArrayList* arraylist){
	for(int i=0;i<arraylist->length;i++){
		printf("%d ", arraylist->data[i]);
	}
	printf("\n");
}
int main(){
	ArrayList myArrList;
	InitArrayList(&myArrList);
	while(1){
		int op;
		scanf("%d",&op);
		if(op==1){
			DATATPE mydata;
			scanf("%d", &mydata);
			if(ArrayListInsert(&myArrList,mydata) == OKAY){
				printf("OKAY\n");
			}
			else{
				printf("FAIL\n");
			}
		}
		else if(op==2){
			int position;
			scanf("%d", &position);
			if(ArrayListDelete(&myArrList,position) == OKAY){
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
			if(ArrayListEdit(&myArrList,position,mydata) == OKAY){
				printf("OKAY\n");
			}
			else{
				printf("FAIL\n");
			}
		}
		else if(op==4){
			int position;
			scanf("%d", &position);
			printf("%d\n", ArrayListGetData(&myArrList,position));
		}
		else if(op==5){
			DATATPE mydata;
			scanf("%d", &mydata);
			printf("%d\n", ArrayListGetPosition(&myArrList,mydata));
		}
		else if(op==6){
			ShowArrayList(&myArrList);
		}
		else if(op==7){
			DestoryArrayList(&myArrList);
			InitArrayList(&myArrList);
			printf("OKAY\n");
		}
		else{
			printf("INVALID OP\n");
		}
	}

	return 0;
} 
