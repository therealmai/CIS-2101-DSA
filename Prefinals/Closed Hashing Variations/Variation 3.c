#include<stdio.h>
#define size 20
#define half size/2
#define empty -2
#define deleted -1

typedef int LIST;
typedef struct celltype{
    char elem;
    int link;
}celltype;

typedef struct{
    celltype arr[size];
    int avail;
}Dictionary;

void initDictionary(Dictionary* D);
void displayDic(Dictionary D);
int hash(char elem);
void populateDic(Dictionary* D);
void deleteDic(Dictionary *D, char elem);
int isMember(Dictionary D, char elem);
void main(){
    LIST list = 0;
    Dictionary D;
    initDictionary(&D);
    populateDic(&D);
    deleteDic(&D, 'g');
    deleteDic(&D, 'q');
    displayDic(D);
    printf("\n");
    printf("%d ", isMember(D,'q'));
    printf("%d ", isMember(D,'m'));
}

void initDictionary(Dictionary* D){
    int x;
    for(x=0;x<half; x++){
        D->arr[x].elem = empty;
    }
    for(x=half;x<size-1; x++){
        D->arr[x].link= x+1;
    }
    D->avail = half;
    D->arr[x].link = -1;
}

int hash(char elem){
    return elem % 10;
}
void insertDic(Dictionary *D, char elem){
    int key, *trav, newAvail = D->avail;
    key = hash(elem);
    if(D->arr[key].elem != empty && D->arr[key].elem != deleted){
        for(trav = &D->arr[key].link; *trav != -1; trav = &D->arr[*trav].link){}
        D->arr[newAvail].elem = elem;
        D->avail = D->arr[newAvail].link;
        D->arr[newAvail].link = *trav;
        *trav = newAvail;
    }else{
        if(D->arr[key].elem == empty){
            D->arr[key].link = -1;
        }
        D->arr[key].elem = elem;
    }
}

void displayDic(Dictionary D){
    int x,trav;
    printf("%d\n", D.avail);
    for(x=0; x<half; x++){
    	
        printf("%d: ", x);
        if(D.arr[x].elem != deleted && D.arr[x].elem != empty){
            for(trav = x; trav != -1; trav = D.arr[trav].link){
                printf("--> %c", D.arr[trav].elem);
            }
            printf("\n");
        }else{
            if(D.arr[x].elem == empty){
                printf("Empty\n");
            }else{
                printf("Deleted\n");
            }
        }    
    }    
}

void populateDic(Dictionary* D){
    insertDic(D,'g'); // a
    insertDic(D,'m'); // b
    insertDic(D,'h'); // c
    insertDic(D,'q'); // d
    insertDic(D,'w'); // e
    insertDic(D,'d'); // f
    
}

void deleteDic(Dictionary *D, char elem){
     int key, *trav, temp;
     key = hash(elem);
     if(D->arr[key].elem == elem){
     	D->arr[key].elem = deleted;
	 }else{
	 	 for(trav = &D->arr[key].link; *trav != -1 && D->arr[*trav].elem != elem; trav = &D->arr[*trav].link){}
         if(*trav != -1){
         	temp = *trav;
	        *trav = D->arr[temp].link;
	        D->arr[temp].elem = deleted;
	        D->arr[temp].link = D->avail;
	        D->avail = temp;
         }else{
         	printf("Element not found");
		 }
	 }     
}

int isMember(Dictionary D, char elem){
	int trav,key;
	key = hash(elem);
	for(trav = key; trav != -1 && D.arr[trav].elem != elem; trav = D.arr[trav].link){}
	return (trav != -1 && D.arr[trav].elem  == elem) ? 1 : 0;
}


