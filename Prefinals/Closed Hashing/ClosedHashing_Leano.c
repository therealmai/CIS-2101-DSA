#include<stdio.h>
#include<stdlib.h>
#define size 10
#define deleted -1
#define empty -2

typedef char elem;
typedef elem Dictionary[size];

void initDictionary(Dictionary D);
void insert(Dictionary D, char elem);
void populateDic(Dictionary D);
void displayDic(Dictionary D);
int isMember(Dictionary D, char elem);
void deleteDic(Dictionary D, char elem);

int main() {
  Dictionary D;
  initDictionary(D);
  populateDic(D);
  displayDic(D);
  printf("\n");
  insert(D, 'k');
  displayDic(D);
  
  printf("%d ",isMember(D, 'c'));
  printf("%d ",isMember(D, 'g'));
  deleteDic(D, 'c');
  
  printf("\n\nDeletion\n");
  displayDic(D);
  printf("%d ",isMember(D, 'c'));
  return 0;
}

void initDictionary(Dictionary D){
  int x;
  for(x=0; x<size; x++){
    D[x] = empty;  
  }
}

void displayDic(Dictionary D){
  int x;
  for(x=0;x<size;x++){
    printf("Index %d: ", x);
    if(D[x] == empty){
      printf("Empty\n");  
    }else if(D[x] == deleted){
      printf("Deleted\n");  
    }else{
      printf("%c\n", D[x]);  
    }
  }
}

int hash(char elem){
  return elem % 10;  
}

void populateDic(Dictionary D){
	insert(D,'a');
	insert(D,'b');
	insert(D,'c');
	insert(D,'d');
	insert(D,'e');
	insert(D,'f');
	insert(D, 'g');
	insert(D, 'h');
	insert(D, 'i');
	insert(D, 'j');
}

void insert(Dictionary D, char elem){
  int group,x=0;
  for(group = hash(elem); D[group] != deleted && D[group] != empty && x<size ; group = (group + 1) % size, x++){}
  if(x < size){
    D[group] = elem;  
  }else{
    printf("Dictionary is Full\n");  
  }
}

void deleteDic(Dictionary D, char elem){
	int group, x=0;
	for(group = hash(elem); D[group] != deleted && D[group] != empty && D[group] != elem ; group = (group + 1) % size, x++){}
	if(x < size){
		D[group] = deleted;
	}else{
		printf("Element not found");
	}		
}

int isMember(Dictionary D, char elem){
	int x=0, data;
	for(data = hash(elem);x<size && D[data] != empty; data= (data +1) % size, x++){}
		return (D[data] != elem) ? 0 : 1; 	
}
