#include <stdio.h>

#define SIZE 10
typedef unsigned int SET;

void init(SET *A)
{
    *A = 0;
}

void insertElem(SET *A, int elem)
{
    unsigned int mask = 1;
    *A |= mask << elem;
}

void deleteElem(SET *A, int elem)
{
    unsigned int mask = 1;
    *A &= ~(mask << elem);
}

void populate(SET *A, int elem[], int count)
{
    int i;
    for(i = 0; i < count; i++){
        insertElem(A, elem[i]);
    }
}

void display(SET A)
{
    unsigned int mask = 1;
    int i;
    for(i = 0; i < SIZE; i++){
        if((A & mask<<i) != 0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

SET Union(SET A, SET B)
{
    return A | B;
}
SET Intersection(SET A, SET B)
{
    return A & B;
}
SET Difference(SET A, SET B)
{
    return A & ~B;
}

int isSubset(SET A, SET B)
{
    return ((A & ~B) != 0)? 0:1; 
}

void main()
{
    SET A, B;
    init(&A); init(&B);
    int elem1[] = {2, 4, 6, 7}, elem2[] = {1, 4, 5, 6, 7};
    populate(&A, elem1, 4); populate(&B, elem2, 5);
    display(Union(A, B));
    display(Intersection(A, B));
    display(Difference(A, B));
    printf("isSubset: %d\n", isSubset(A, B));
    deleteElem(&A, 2);
    printf("isSubset: %d\n", isSubset(A, B));
}