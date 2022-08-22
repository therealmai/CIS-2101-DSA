#include <stdio.h>
#include <stdlib.h>
#include "../ADT/QueueLL.h"

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}*BinaryTree;

void init(BinaryTree *BST)
{
    *BST = NULL;
}

void insert(BinaryTree *BST, int data)
{
    if(*BST == NULL){
        *BST = (BinaryTree)malloc(sizeof(struct node));
        (*BST)->data = data;
        (*BST)->right = NULL;
        (*BST)->left = NULL;
    }
    else if(data < (*BST)->data){
        insert(&(*BST)->left, data);
    }
    else if(data > (*BST)->data){
        insert(&(*BST)->right, data);
    }
    else{
        printf("failed to insert node\n");
    }
}

void insertNonRecur(BinaryTree *BST, int data)
{
    int i;
    while(*BST != NULL){
        BST = (data < (*BST)->data)? &(*BST)->left: &(*BST)->right;
    }
    *BST = (BinaryTree)malloc(sizeof(struct node));
    (*BST)->data = data;
    (*BST)->right = NULL;
    (*BST)->left = NULL;
}

void populate(BinaryTree *BST, int data[], int count)
{
    int i;
    for(i = 0; i < count; i++)
    {
        insertNonRecur(BST, data[i]);
    }
}

int isMember(BinaryTree BT, int data)
{
    while(BT != NULL && BT->data != data){
        if(data < BT->data){
            BT = BT->left;
        }
        else{
            BT = BT->right;
        }
    }
    return (BT != NULL)? 1:0;
}

int deleteMin(BinaryTree *BT)
{
    while((*BT)->left != NULL){
        BT = &(*BT)->left;
    }
    int ret = (*BT)->data;
    *BT = ((*BT)->right != NULL)? (*BT)->right: NULL;
    return ret;
}

void deleteElem(BinaryTree *BT, int data)
{
    while(*BT != NULL && (*BT)->data != data){
        if(data < (*BT)->data){
            BT = &(*BT)->left;
        }
        else{
            BT = &(*BT)->right;
        }
    }
    if(*BT != NULL){
        if((*BT)->left != NULL && (*BT)->right != NULL){
            (*BT)->data = deleteMin(&(*BT)->right);
        }
        else if((*BT)->left != NULL){
            void *temp = *BT;
            *BT = (*BT)->left;
            free(temp);
        }
        else if((*BT)->right != NULL){
            void *temp = *BT;
            *BT = (*BT)->right;
            free(temp);
        }
        else{
            free(*BT);
            *BT = NULL;
        }
    }
}

int height(BinaryTree BST)
{
    if(BST != NULL){
        int left = height(BST->left);
        int right = height(BST->right);
        return (left > right)? left+1: right+1;
    }
    else{
        return -1;
    }
}

int depth(BinaryTree BST, BinaryTree node)
{
    if(BST == NULL){
        return -1;
    }
    else if(BST == node){
        return 0;
    }
    else {
        int left = depth(BST->left, node);
        int right = depth(BST->right, node);
        if(left == right){
            return -1;
        }
        else{
            return (left > right)? left+1: right+1;
        }
    }
}

int depthBST(BinaryTree BST, BinaryTree node)
{
    int ctr = 0;
    while(BST != node && BST != NULL){
        BST = (node->data < BST->data)? BST->left: BST->right;
        ctr++;
    }
    return (BST != NULL)? ctr: -1;
}

void preorder(BinaryTree BST)
{
    if(BST != NULL){
        printf("%d ", BST->data);
        preorder(BST->left);
        preorder(BST->right);
    }
}

void inorder(BinaryTree BST)
{
    if(BST != NULL){
        inorder(BST->left);
        printf("%d ", BST->data);
        inorder(BST->right);
    }
}

void postorder(BinaryTree BST)
{
    if(BST != NULL){
        postorder(BST->left);
        postorder(BST->right);
        printf("%d ", BST->data);
    }
}

void levelOrder(BinaryTree BST)
{
    int count = 0, ctr = 0;
    Queue q;
    initQueue(&q);
    enqueue(&q, BST);
    ctr = 2;
    while(!isEmpty(q)){
        if(!(--ctr)){
            printf("\n");
            ctr = count;
            count = 0;
        }
        if(front(q) != NULL){
            BinaryTree temp = front(q);
            printf("%d ", temp->data);
            enqueue(&q, temp->left);
            enqueue(&q, temp->right);
            count += 2;
        }
        dequeue(&q);
    }
}

int isBST(BinaryTree BST)
{
    int left = 1;
    int right = 1;
    if(BST == NULL){
        return 0;
    }
    if(BST->left != NULL){
        if(BST->left->data < BST->data){
            left = 1 && isBST(BST->left);
        }
        else {
            left = 0;
        }
    }
    if(BST->right != NULL && left != 0){
        if(BST->right->data > BST->data){
            right = 1 && isBST(BST->right);
        }
        else {
            right = 0;
        }
    }
    return left && right;
}

int isBalanced(BinaryTree BST)
{
    int left = height(BST->left);
    int right = height(BST->right);
    int temp;
    if(left > right){
        temp = left - right;
    }
    else {
        temp = right - left;
    }
    return (temp < 2)? 1: 0;
}

int isAVL(BinaryTree BST)
{
    if(BST != NULL){
        int leftB = isAVL(BST->left);
        int rightB = isAVL(BST->right);
        if(leftB && rightB){
            int leftH = height(BST->left);
            int rightH = height(BST->right);
            return ((leftH-rightH+1) <= 2)? 1: 0;
        }
        else {
            return 0;
        }
    }
    else{
        return 1;
    }
}

BinaryTree rightRotation(BinaryTree BST)
{
    BinaryTree leftTree = BST->left;
    BinaryTree rightSub = leftTree->right;

    leftTree->right = BST;
    BST->left = rightSub;

    return leftTree;
}

BinaryTree leftRotation(BinaryTree BST)
{
    BinaryTree rightTree = BST->right;
    BinaryTree leftSub = rightTree->left;

    rightTree->left = BST;
    BST->right = leftSub;

    return rightTree;
}

void AVLTreeBalance(BinaryTree *BST)
{
    if(*BST != NULL){
        AVLTreeBalance(&(*BST)->left);
        AVLTreeBalance(&(*BST)->right);
        
        int leftH = height((*BST)->left);
        int rightH = height((*BST)->right);
        if((leftH-rightH) > 1){
            if((*BST)->left->left == NULL){
                (*BST)->left = leftRotation((*BST)->left);
            }
            *BST = rightRotation(*BST);
        }
        else if((leftH-rightH) < -1){
            if((*BST)->right->right == NULL){
                (*BST)->right = rightRotation((*BST)->right);
            }
            *BST = leftRotation(*BST);
        }
    }
}

void main()
{
    BinaryTree BST;
    init(&BST);
    int data[] = {10, 4, 2, 3, 11, 12, 13}; // {10 , 5, 14, 12, 7, 18, 15};
    populate(&BST, data, 7);
    /* Tree visual representation
        <-10->
    5->        <-14->
        7   12      <-18
                15
    */
    // preorder(BST); printf("\n");
    // inorder(BST); printf("\n");
    // postorder(BST); printf("\n");

    // deleteElem(&BST, 15);
    // inorder(BST); printf("\n");
    // deleteElem(&BST, 5);
    // inorder(BST); printf("\n");
    // deleteElem(&BST, 10);
    // inorder(BST); printf("\n");
    // printf("%d", isBST(BST));
    // levelOrder(BST);
    // printf("%d", isBalanced(BST));
    // printf("%d", depthBST(BST, BST));
    printf("%d\n", isAVL(BST));
    AVLTreeBalance(&BST);
    preorder(BST); printf("\n");
    printf("%d\n", isAVL(BST));
}