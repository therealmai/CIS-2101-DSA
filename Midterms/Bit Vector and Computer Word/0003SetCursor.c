#include <stdio.h>
#include "../ADT/Cursor.h"

typedef struct {
    VirtualHeap* VH;
    int list;
}SET;

void init(SET *A, VirtualHeap *VH)
{
    A->VH = VH;
    A->list = -1;
}

void insertLast(SET *A, int data)
{
    int *temp;
    for(temp  = &A->list; *temp != -1; temp = &A->VH->node[*temp].next){}
    *temp = allocSpace(A->VH);
    A->VH->node[*temp].elem = data;
}

 void deleteElem(SET *A, int data)
{
    int *temp;
    for(temp = &A->list; *temp != -1 && A->VH->node[*temp].elem != data; temp = &A->VH->node[*temp].next){}
    if(A->VH->node[*temp].elem == data){
        int next = A->VH->node[*temp].next;
        deallocSpace(A->VH, *temp);
        *temp = next;
    }
}

void populate(SET *A, int data[], int count)
{
    int i;
    for(i = 0; i < count; i++){
        insertLast(A, data[i]);
    }
}

void display(SET A)
{
    while(A.list != -1){
        printf("%d ", A.VH->node[A.list].elem);
        A.list = A.VH->node[A.list].next;
    }
    printf("\n");
}

SET SortedUnion(SET A, SET B)
{
    SET C = {A.VH, -1};
    while (A.list != -1 && B.list != -1)
    {
        if(A.VH->node[A.list].elem < B.VH->node[B.list].elem){
            insertLast(&C, A.VH->node[A.list].elem);
            A.list = A.VH->node[A.list].next;
        }
        else if(A.VH->node[A.list].elem > B.VH->node[B.list].elem){
            insertLast(&C, B.VH->node[B.list].elem);
            B.list = B.VH->node[B.list].next;
        }
        else {
            insertLast(&C, A.VH->node[A.list].elem);
            A.list = A.VH->node[A.list].next;
            B.list = B.VH->node[B.list].next;
        }
    }
    while(A.list != -1){
        insertLast(&C, A.VH->node[A.list].elem);
        A.list = A.VH->node[A.list].next;
    }
    while(B.list != -1){
        insertLast(&C, B.VH->node[B.list].elem);
        B.list = B.VH->node[B.list].next;
    }
    return C;
}

void main()
{
    SET A, B;
    VirtualHeap VH;
    initVirtualHeap(&VH);
    init(&A, &VH); init(&B, &VH);
    int elem1[] = {2, 4, 6, 7}, elem2[] = {1, 4, 5, 6, 7};
    populate(&A, elem1, 4); populate(&B, elem2, 5);
    deleteElem(&A, 4);
    display(A);
    display(B);
    display(SortedUnion(A, B));
    // display(SortedIntersection(A, B));
    // display(SortedDifference(A, B));
    // printf("isSubset: %d\n", isSubset(A, B));
    // deleteElem(&A, 2);
    // printf("isSubset: %d\n", isSubset(A, B));
}
