#include<stdio.h>
#define size 20
#define half size/2
#define empty -2
#define deleted -1


typedef struct cell{
    char elem;
    int link;
}cell;

typedef struct{
    cell list[size];
    int last;
}Dictionary;

void initDic(Dictionary *D);
void displayDic(Dictionary D);
void insert(Dictionary* D, char elem);
int ismember(Dictionary D, char elem);
void deleteMember(Dictionary *D, char elem);
void main(){
    Dictionary D;
    initDic(&D);
    insert(&D, 'g'); //a
    insert(&D, 'm'); //b
    insert(&D, 'h'); //c
    insert(&D, 'q'); //d
    insert(&D, 'w'); //e
    insert(&D, 'd'); //f
    insert(&D, 'S'); //g
    displayDic(D);
    printf("\n");
    printf("%d ",ismember(D, 'h'));
    printf("%d ",ismember(D, 'I'));
    printf("%d ",ismember(D, 'F'));
    printf("\n\nDeletion");
    deleteMember(&D, 'g');
    deleteMember(&D, 'q');
    printf("\n");
    displayDic(D);
}

void initDic(Dictionary *D){
    int x;
    for(x=0; x<half; x++){
        D->list[x].elem = empty; 
    }
    D->last = half-1;
}

void displayDic(Dictionary D){
    int x,trav;
    printf("Last: %d\n\n", D.last);
    for(x=0; x<=D.last; x++){
        printf("%d: ", x);
        if(D.list[x].elem == empty){
            printf("Empty\n");
        }else if(D.list[x].elem == deleted){
            printf("Deleted\n");
        }else{
        	for(trav = x; trav != -1; trav = D.list[trav].link){	
            	printf("-->%c ", D.list[trav].elem);
       		 }
       		 printf("\n");
        }
    }
}

int hash(char elem){
    return elem % 10;
}

void insert(Dictionary* D, char elem){
    int key;
    key = hash(elem);
    if(D->last < size && D->list[key].elem == deleted || D->list[key].elem == empty){
        D->list[key].elem = elem;
        D->list[key].link = -1;
    }else{
        D->list[D->last+1].elem = elem;
        D->last++;
        if(D->list[key].link != -1){
        	D->list[D->last].link = D->list[key].link;	
		}else{
			D->list[D->last].link = -1;	
		}
       D->list[key].link = D->last;
    }
}

int ismember(Dictionary D, char elem){
	int key;
	for(key= hash(elem); D.list[key].link != -1 && D.list[key].elem != elem; key = D.list[key].link){}
	return (D.list[key].elem == elem) ? 1 : 0;
}

void deleteMember(Dictionary *D, char elem){
	int key;
	key = hash(elem);
	if(D->list[key].elem != elem){
		for(D->list[key].elem; D->list[key].link != -1 && D->list[key].elem != elem; key = D->list[key].link){}
		if(D->list[key].elem == elem){
			D->list[key].elem = deleted;
		}else{
			printf("Element Not Found");
		}
	}else{
		D->list[key].elem = deleted;
	}	
}


