#include <stdio.h>

#define SIZE 10
typedef struct {
    int left;
    int right;
}node;
typedef node BinaryTree[SIZE];

void init(BinaryTree BT)
{
    int i;
    for(i = 0; i < SIZE; i++){
        BT[i].left = -1;
        BT[i].right = -1;
    }
}

void insertRoot(BinaryTree BT, int *root, int data)
{
    if(*root = -1){
        *root = data;
    }
    else {
        BT[data].left = *root;
    }
}

void insert(int *node, int data)
{
    if(*node = -1){
        *node = data;
    }
}

void preorder(BinaryTree BT, int data)
{
    if(data != -1){
        printf("%d ", data);
        preorder(BT, BT[data].left);
        preorder(BT, BT[data].right);
    }
}

void inorder(BinaryTree BT, int data)
{
    if(data != -1){
        inorder(BT, BT[data].left);
        printf("%d ", data);
        inorder(BT, BT[data].right);
    }
}

void postorder(BinaryTree BT, int data)
{
    if(data != -1){
        postorder(BT, BT[data].left);
        postorder(BT, BT[data].right);
        printf("%d ", data);
    }
}

void main()
{
    BinaryTree BT;
    int root = -1;
    init(BT);
    insertRoot(BT, &root, 0);
    insert(&BT[0].left, 1);
    insert(&BT[1].left, 2);
    insert(&BT[1].right, 3);
    insert(&BT[2].right, 4);
    /* Tree visual representation
            <-0
        <-1->
    2->      3
        4
    */
    preorder(BT, root); printf("\n");
    inorder(BT, root); printf("\n");
    postorder(BT, root); printf("\n");
}