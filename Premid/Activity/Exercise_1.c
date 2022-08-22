#include<stdio.h>
#include<stdlib.h>
#define size 6

typedef struct node {
    int data;
    struct node *link;
}*LinkList;

void initList(LinkList *head);
void insertLast(LinkList *head, int num);
void populateList(LinkList *head, int arr[]);
void displayList(LinkList head);
LinkList getEven (LinkList *list);

int main() {
  LinkList head,retval;
  int arr[size] = {4,10,3,6,7,1};
  printf("Task 1\n");
  initList(&head);
  displayList(head);
  printf("Task 2\n");
  populateList(&head, arr);
  displayList(head);
  printf("Task 3\n");
  retval = getEven(&head);
  printf("Original List: ");
  displayList(head);
  printf("Even Numbers: ");
  displayList(retval);
  
  return 0;
}

void initList(LinkList *head){
  *head = NULL;  
}

void insertLast(LinkList *head,int num){
  LinkList temp, *trav;
  
  for(trav = head; (*trav) != NULL; trav = &(*trav)->link){}
  temp = (LinkList)malloc(sizeof(struct node));
  if(temp != NULL){
    temp->data = num;
    temp->link = NULL;
    *trav = temp;    
  }
}

void populateList(LinkList *head, int arr[]){
  int x;
  
  for(x=0; x<size; x++){
    insertLast(head, arr[x]);  
  }
}

void displayList(LinkList head){
  LinkList trav;
  
  if(head != NULL){
      for(trav = head; trav != NULL; trav = trav->link){
        printf("%d ", trav->data);
      }
  }else{
    printf("List is Empty");
  }
  printf("\n");

}

LinkList getEven (LinkList *list){
    LinkList *trav;
    LinkList newList = NULL;
    LinkList *newTemp = &newList;
    for(trav = list; *trav != NULL;){
        if((*trav)->data % 2 == 0){
            *newTemp = *trav;
            newTemp=&(*newTemp)->link;
            *trav=(*trav)->link;
         }
         else{
               trav = &(*trav)->link;
        }
    }
    *newTemp=NULL;
    return newList;
}
