#include<stdio.h>
#define size 20
#define half size/2
#define empty -2
#define deleted -1

typedef char list;

typedef struct{
    list arr[size];
    int last;
}Dictionary;
 
void initDictionary(Dictionary* D);
void displayList(Dictionary D);
void insertDic(Dictionary* D, char elem);
int ismember(Dictionary D, char elem);
void deleteMember(Dictionary *D, char elem);
void main(){
    Dictionary D;
    initDictionary(&D);
    insertDic(&D, 'g'); //a
    insertDic(&D, 'm'); //b
    insertDic(&D, 'h'); //c   context video
    insertDic(&D, 'q'); //d
    insertDic(&D, 'w'); //e
    insertDic(&D, 'd'); //f
    insertDic(&D, 'n'); //g
    displayList(D);
    printf("\n");
    printf("%d ", ismember(D, 'h')); // c
    printf("%d ", ismember(D, 'z')); // j
    printf("%d ", ismember(D, 'p')); // k
    printf("\n\nDeletion");
    deleteMember(&D, 'h');
    deleteMember(&D, 'q');
    printf("\n");
    displayList(D);
    
}

void initDictionary(Dictionary* D){
    int x;
    for(x=0; x<half; x++){
        D->arr[x] = empty;
    }
    D->last = half-1;
}

void displayList(Dictionary D){
  int x;
  for(x=0; x<=D.last; x++){
    printf("%d: ", x);
    if(D.arr[x] == empty){
      printf("Empty\n");  
    }else if (D.arr[x] == deleted){
      printf("Deleted\n");  
    }else{
      printf("%c\n", D.arr[x]);  
    }
  }
}

int hash(char elem){
    return elem % 10;
}

void insertDic(Dictionary* D, char elem){
    int key;
    key = hash(elem);
    if(D->last < size && D->arr[key] == empty || D->arr[key] == deleted){
        D->arr[key] = elem; 
    }else{
        D->arr[D->last+1] = elem;
        D->last++;
    }
}

int ismember(Dictionary D, char elem){
	int key,retval;
	
	key = hash(elem); 
	if(D.arr[key] != elem){
		for(key = half; key < size && D.arr[key] != elem ; key++){}
		retval = (key <= D.last) ? 1 : 0;		
	}else{
		retval = 1;
	}
	return retval;
}

void deleteMember(Dictionary *D, char elem){
	int key;
    key = hash(elem);
	if(D->arr[key] != elem){
		for(key = half; key < size && D->arr[key] != elem ; key++){}
		if(key <= D->last){
			D->arr[key] = deleted;
		}else{
			printf("Element not found");
		}
	}else{
		D->arr[key] = deleted;
	}
}
