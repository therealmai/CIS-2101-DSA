#include <stdio.h>
#include <stdlib.h>
#include "../ADT/QueueLL.h"

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}*BinaryTree;

void init(BinaryTree *BT)
{
    *BT = NULL;
}

void insert(BinaryTree *BT, int data)
{
    if(*BT == NULL){
        *BT = (BinaryTree)malloc(sizeof(struct node));
        (*BT)->data = data;
        (*BT)->right = NULL;
        (*BT)->left = NULL;
    }
}

int height(BinaryTree BT)
{
    if(BT != NULL){
        int left = height(BT->left);
        int right = height(BT->right);
        return (left > right)? left+1: right+1;
    }
    else{
        return -1;
    }
}

int depth(BinaryTree BT, BinaryTree node)
{
    if(BT == NULL){
        return -1;
    }
    else if(BT == node){
        return 0;
    }
    else {
        int left = depth(BT->left, node);
        int right = depth(BT->right, node);
        if(left == right){
            return -1;
        }
        else{
            return (left > right)? left+1: right+1;
        }
    }
}

void preorder(BinaryTree BT)
{
    if(BT != NULL){
        printf("%d ", BT->data);
        preorder(BT->left);
        preorder(BT->right);
    }
}

void inorder(BinaryTree BT)
{
    if(BT != NULL){
        inorder(BT->left);
        printf("%d ", BT->data);
        inorder(BT->right);
    }
}

void postorder(BinaryTree BT)
{
    if(BT != NULL){
        postorder(BT->left);
        postorder(BT->right);
        printf("%d ", BT->data);
    }
}

void levelOrder(BinaryTree BT)
{
    Queue q;
    initQueue(&q);
    enqueue(&q, BT);
    int count = 0, ctr = 0;
    ctr += 2;
    while(!isEmpty(q)){
        if(!(--ctr)){
            printf("\n");
            ctr = count;
            count = 0;
        }
        if(front(q) != NULL){
            BinaryTree temp = front(q);
            printf("%d", temp->data);
            enqueue(&q, temp->left);
            enqueue(&q, temp->right);
            count += 2;
        }
        dequeue(&q);
    }
}

int isBST(BinaryTree BT)
{
    int left = 1;
    int right = 1;
    if(BT == NULL){
        return 0;
    }
    if(BT->left != NULL){
        if(BT->left->data < BT->data){
            left = 1 && isBST(BT->left);
        }
        else {
            left = 0;
        }
    }
    if(BT->right != NULL && left != 0){
        if(BT->right->data > BT->data){
            right = 1 && isBST(BT->right);
        }
        else {
            right = 0;
        }
    }
    return left && right;
}

int isBalanced(BinaryTree BT)
{
    int left = height(BT->left);
    int right = height(BT->right);
    int temp;
    if(left > right){
        temp = left - right;
    }
    else {
        temp = right - left;
    }
    return (temp < 2)? 1: 0;
}

void main()
{
    BinaryTree BT;
    init(&BT);
    insert(&BT, 0);
    insert(&BT->left, 1);
    insert(&BT->left->left, 2);
    insert(&BT->left->right, 3);
    insert(&BT->left->left->right, 4);
    /* Tree visual representation
            <-0
        <-1->
    2->      3
        4
    */
    // preorder(BT); printf("\n");
    // inorder(BT); printf("\n");
    // postorder(BT); printf("\n");
    // printf("%d", height(BT));
    // printf("%d", depth(BT, BT));
    // printf("%d", isBST(BT));
    // levelOrder(BT);
    printf("%d", isBalanced(BT));
}