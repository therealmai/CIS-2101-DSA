#include <stdio.h>
#include <stdlib.h>

typedef int data;
typedef struct node{
    data elem;
    struct node* link;
}*SET;

void init(SET *A)
{
    *A = NULL;
}

void insertLast(SET *A, data elem)
{
    for(; *A !=NULL; A = &(*A)->link){}
    *A = (SET)malloc(sizeof(struct node));
    (*A)->elem = elem;
    (*A)->link = NULL;
}

void deleteElem(SET *A, data elem)
{
    while(*A != NULL){
        if((*A)->elem == elem){
            SET temp = (*A)->link;
            free(*A);
            *A = temp;
            break;
        }
        A = &(*A)->link;
    }
}

void populate(SET *A, data elem[], int count)
{
    int i;
    for(i = 0; i < count; i++){
        insertLast(A, elem[i]);
    }
}

void display(SET A)
{
    while(A != NULL){
        printf("%d ", A->elem);
        A = A->link;
    }
    printf("\n");
}

SET SortedUnion(SET A, SET B)
{
    SET C = NULL;
    SET *ret = &C;
    while(A != NULL && B != NULL){
        if(A->elem < B->elem){
            insertLast(&C, A->elem);
            A = A->link;
        }
        else if(A->elem > B->elem){
            insertLast(&C, B->elem);
            B = B->link;
        }
        else {
            insertLast(&C, A->elem);
            A = A->link;
            B = B->link;
        }
    }
    while(A != NULL){
        insertLast(&C, A->elem);
            A = A->link;
    }
    while(B != NULL){
        insertLast(&C, B->elem);
        B = B->link;
    }
    return *ret;
}

SET SortedIntersection(SET A, SET B)
{
    SET C = NULL;
    SET *ret = &C;
    while(A != NULL && B != NULL){
        if(A->elem < B->elem){
            A = A->link;
        }
        else if(A->elem > B->elem){
            B = B->link;
        }
        else {
            insertLast(&C, A->elem);
            A = A->link;
            B = B->link;
        }
    }
    return *ret;
}

SET SortedDifference(SET A, SET B)
{
    SET C = NULL;
    SET *ret = &C;
    while(A != NULL && B != NULL){
        if(A->elem < B->elem){
            insertLast(&C, A->elem);
            A = A->link;
        }
        else if(A->elem > B->elem){
            B = B->link;
        }
        else {
            A = A->link;
            B = B->link;
        }
    }
    while(A != NULL){
        insertLast(&C, A->elem);
        A = A->link;
    }
    return *ret;
}

int isSubset(SET A, SET B)
{
    while(A != NULL && B != NULL){
        if(A->elem < B->elem){
            break;
        }
        else if(A->elem > B->elem){
            B = B->link;
        }
        else {
            A = A->link;
            B = B->link;
        }
    }
    return (A != NULL)? 0:1;
}

void main()
{
    SET A, B;
    init(&A); init(&B);
    int elem1[] = {2, 4, 6, 7}, elem2[] = {1, 4, 5, 6, 7};
    populate(&A, elem1, 4); populate(&B, elem2, 5);
    display(A);
    display(B);
    display(SortedUnion(A, B));
    display(SortedIntersection(A, B));
    display(SortedDifference(A, B));
    printf("isSubset: %d\n", isSubset(A, B));
    deleteElem(&A, 2);
    printf("isSubset: %d\n", isSubset(A, B));
}
