#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef int data;
typedef data SET[SIZE]; //index 0 holds the actual size of the array

void init(SET A)
{
    A[0] = 0;
}

void insertLast(SET A, data elem)
{
    A[++A[0]] = elem;
}

void deleteElem(SET A, data elem)
{
    int i;
    for(i = 1; i <= A[0] && A[i] != elem; i++){}
    for(--A[0]; i <= A[0]; i++){
        A[i] = A[i+1];
    }
}

void populate(SET A, data elem[], int count)
{
    int i;
    for(i = 0; i < count; i++){
        insertLast(A, elem[i]);
    }
}

void display(SET *A)
{
    int i;
    for(i = 1; i <= (*A)[0]; i++){
        printf("%d ", (*A)[i]);
    }
    printf("\n");
}

SET* SortedUnion(SET A, SET B)
{
    SET* C = (SET*)calloc(1, sizeof(SET));
    int ptr1 = 1, ptr2 = 1;
    while(ptr1 <= A[0] && ptr2 <= B[0]){
        if(A[ptr1] < B[ptr2]){
            (*C)[++(*C)[0]] = A[ptr1];
            ptr1++;
        }
        else if(A[ptr1] > B[ptr2]){
            (*C)[++(*C)[0]] = B[ptr2];
            ptr2++;
        }
        else {
            (*C)[++(*C)[0]] = A[ptr1];
            ptr1++;
            ptr2++;
        }
    }
    while(ptr1 <= A[0]){
        (*C)[++(*C)[0]] = A[ptr1];
        ptr1++;
    }
    while(ptr2 <= B[0]){
        (*C)[++(*C)[0]] = B[ptr2];
        ptr2++;
    }
    return C;
}

SET* SortedIntersection(SET A, SET B)
{
    SET* C = (SET*)calloc(1, sizeof(SET));
    int ptr1 = 1, ptr2 = 1;
    while(ptr1 <= A[0] && ptr2 <= B[0]){
        if(A[ptr1] < B[ptr2]){
            ptr1++;
        }
        else if(A[ptr1] > B[ptr2]){
            ptr2++;
        }
        else {
            (*C)[++(*C)[0]] = A[ptr1];
            ptr1++;
            ptr2++;
        }
    }
    return C;
}

SET* SortedDifference(SET A, SET B)
{
    SET* C = (SET*)calloc(1, sizeof(SET));
    int ptr1 = 1, ptr2 = 1;
    while(ptr1 <= A[0] && ptr2 <= B[0]){
        if(A[ptr1] < B[ptr2]){
            (*C)[++(*C)[0]] = A[ptr1];
            ptr1++;
        }
        else if(A[ptr1] > B[ptr2]){
            ptr2++;
        }
        else {
            ptr1++;
            ptr2++;
        }
    }
    while(ptr1 <= A[0]){
        (*C)[++(*C)[0]] = A[ptr1];
        ptr1++;
    }
    return C;
}

int isSubset(SET A, SET B)
{
    int ptr1 = 1, ptr2 = 1;
    while(ptr1 <= A[0] && ptr2 <= B[0]){
        if(A[ptr1] < B[ptr2]){
            break;
        }
        else if(A[ptr1] > B[ptr2]){
            ptr2++;
        }
        else {
            ptr1++;
            ptr2++;
        }
    }
    return (ptr1 <= A[0])? 0:1;
}

void main()
{
    SET A, B;
    init(A); init(B);
    int elem1[] = {2, 4, 6, 7}, elem2[] = {1, 4, 5, 6, 7};
    populate(A, elem1, 4); populate(B, elem2, 5);
    display(SortedUnion(A, B));
    display(SortedIntersection(A, B));
    display(SortedDifference(A, B));
    printf("isSubset: %d\n", isSubset(A, B));
    deleteElem(A, 2);
    printf("isSubset: %d\n", isSubset(A, B));
}