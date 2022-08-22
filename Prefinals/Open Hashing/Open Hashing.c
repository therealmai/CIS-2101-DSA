#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}*List;

typedef List Dictionary[10];

void initDict(Dictionary D);
void displayDict(Dictionary D);
int hash(int elem);
void insert(Dictionary D, int elem);
void populate(Dictionary D);
int isMember(Dictionary D, int elem);
void deleteMem(Dictionary D, int elem);

/*Challenge functions*/

void main(){
	Dictionary D;
	
	initDict(D);
	displayDict(D);
	
	populate(D);
	displayDict(D);
	
	printf("%d ",isMember(D,28));
	printf("%d ",isMember(D,0));
	printf("%d ",isMember(D,118));
	
	deleteMem(D,48);
	deleteMem(D,10); //not found
	printf("%d\n",isMember(D,48));
	
	/* Output: 1 1 0 0 */
}

void initDict(Dictionary D){
	int x;
	for(x=0;x<10;x++){
		D[x]=NULL;
	}	
}

void displayDict(Dictionary D){
	int x;
	List trav;
	for(x=0;x<10;x++){
		printf("Group %d: ",x);
		for(trav=D[x];trav!=NULL;trav=trav->link){
			printf("%d ",trav->data);
		}
		printf("\n");
	}
	printf("\n");		
}

int hash(int elem){
	return elem%10;
}
void insert(Dictionary D, int elem){ //insert sorted
	int key;
	List *trav,temp;
	key = hash(elem);
	for(trav=&D[key];*trav!=NULL&&(*trav)->data<elem;trav=&(*trav)->link){}
	if(*trav==NULL || (*trav)->data != elem){ //check if element already exists to avoid duplication
		temp = (List)calloc(1,sizeof(struct node));
		if(temp!=NULL){
			temp->data=elem;
			temp->link=*trav;
			*trav=temp;
		}
	}
}
void populate(Dictionary D){
	insert(D,0);
	insert(D,13);
	insert(D,20);
	insert(D,28);
	insert(D,30);
	insert(D,33);
	insert(D,45);
	insert(D,48);
	insert(D,108);
}

int isMember(Dictionary D, int elem){
	int key;
	List trav;
	key = hash(elem);
	for(trav=D[key];trav!=NULL && trav->data<elem; trav=trav->link){}
	return (trav!=NULL && trav->data==elem) ? 1 : 0;
}

void deleteMem(Dictionary D, int elem){
	int key;
	List *trav, temp;
	key = hash(elem);
	for(trav=&D[key];*trav!=NULL && (*trav)->data<elem; trav=&(*trav)->link){}
	if(*trav!=NULL && (*trav)->data==elem){
		temp=*trav;
		*trav=temp->link;
		free(temp);
	}	
}

