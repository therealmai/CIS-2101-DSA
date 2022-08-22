#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef int data;
typedef data SET[SIZE];

void init(SET A)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        A[i] = 0;
    }
    
}

void insertElem(SET A, data elem)
{
    A[elem] = 1;
}

void deleteElem(SET A, data elem)
{
    A[elem] = 0;
}

void display(SET *A)
{
    int i;
    for(i = 0; i < SIZE; i++){
        if((*A)[i] == 1){
            printf("%d ", i);    
        }
    }
    printf("\n");
}

SET* Union(SET A, SET B)
{
    SET* C = (SET*)calloc(1, sizeof(SET));
    if(C != NULL){
        int i;
        for(i = 0; i < SIZE; i++){
            (*C)[i] = A[i] | B[i];
        }
    }
    return C;
}

SET* Intersection(SET A, SET B)
{
    SET* C = (SET*)calloc(1, sizeof(SET));
    if(C != NULL){
        int i;
        for(i = 0; i < SIZE; i++){
            (*C)[i] = A[i] & B[i];
        }
    }
    return C;
}

SET* Difference(SET A, SET B)
{
    SET* C = (SET*)calloc(1, sizeof(SET));
    if(C != NULL){
        int i;
        for(i = 0; i < SIZE; i++){
            (*C)[i] = A[i] & ~B[i];
        }
    }
    return C;
}

int isSubset(SET A, SET B)
{
    int i;
    for(i = 0; i < SIZE; i++){
        if((A[i] & ~B[i]) != 0){
            break;
        }
    }
    return (i < SIZE)? 0:1;
}

void main()
{
    SET A, B;
    init(A);
    init(B);

    insertElem(A, 1);
    insertElem(A, 3);
    insertElem(A, 4);
    insertElem(A, 5);
    
    insertElem(B, 1);
    insertElem(B, 2);
    insertElem(B, 5);
    insertElem(B, 7);

    display(Union(A, B));
    display(Intersection(A, B));
    display(Difference(A, B));
    printf("isSubset: %d\n", isSubset(A, B));
    deleteElem(A, 3);
    deleteElem(A, 4);
    printf("isSubset: %d\n", isSubset(A, B));
}
