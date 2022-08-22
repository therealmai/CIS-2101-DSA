#include<stdio.h>
#define Max 10

typedef struct {
    char elem;
    int next;
}nodetype;
typedef struct {
   nodetype Nodes[Max];
   int Avail;
}VirtualHeap;
typedef int LIST;

void initVirtualHeap(VirtualHeap *VH);
void initVirtualHeap2(VirtualHeap *VH2);
int allocSpace(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void insertLast(VirtualHeap* VH, LIST* list, char elem);
void display(VirtualHeap * VH, LIST * list);


int main() {
  VirtualHeap VH, VH2;
  int retval1, retval2;
  initVirtualHeap(&VH);
  initVirtualHeap2(&VH2);
  LIST list = 0;
  retval1 = allocSpace(&VH);
  retval2 = allocSpace(&VH2);
  deallocSpace(&VH, retval1);
  deallocSpace(&VH2, retval2);
  insertLast(&VH, &list, 'A');
  insertLast(&VH, &list, 'B');
  display(&VH, &list);
  
  return 0;
}

void initVirtualHeap(VirtualHeap *VH){
  int x;
  for(x=0; x<Max; x++){
    VH->Nodes[x].next = x+1;
    }
  VH->Nodes[Max-1].next = -1;
  VH->Avail = 0;
}

void initVirtualHeap2(VirtualHeap *VH2){
int x;
for(x = Max-1; x>0; x--){
  VH2->Nodes[x].next = x-1;
}
VH2->Nodes[x].next = -1;
VH2->Avail = Max-1;
}


int allocSpace(VirtualHeap *VH){
int x = VH->Avail;
if(VH->Avail != -1){
  VH->Avail = VH->Nodes[x].next;
  }
  return x;
}

void deallocSpace(VirtualHeap *VH, int num){
  VH->Nodes[num].next = VH->Avail;
  VH->Avail = num;
}

void insertLast(VirtualHeap *VH, LIST* list, char elem){
LIST* trav, temp;
for(trav = list; *trav != -1; trav = &VH->Nodes[*trav].next){}
temp = allocSpace(VH);
if(temp != -1){
  VH->Nodes[temp].elem = elem;
  VH->Nodes[temp].next = -1;
  *trav = temp;
  }
}


void display(VirtualHeap * VH, LIST * list){
LIST* trav;
for(trav = list; *trav != -1; trav = &VH->Nodes[*trav].next){
  printf("%c", VH->Nodes[*trav].elem);
  }
}

