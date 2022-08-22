#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef struct node{
    int child;
    struct node* link;
}*Child;
typedef struct{
    Child nodes[SIZE];
    int root;
}Tree;

void init(Tree *T)
{
    int i;
    for(i = 0; i < SIZE; i++){
        T->nodes[i] = NULL;
    }
    T->root = -1;
}

void insertRoot(Tree *T, int node)
{
    if(T->root != -1){
        T->nodes[node] = (Child)malloc(sizeof(struct node));
        T->nodes[node]->child = T->root;
        T->nodes[node]->link = NULL;
    }
    T->root = node;
}

void insertChild(Tree *T, int child, int parent)
{
    Child *temp = &T->nodes[parent];
    while(*temp != NULL){
        temp = &(*temp)->link;
    }
    *temp = (Child)malloc(sizeof(struct node));
    (*temp)->child = child;
    (*temp)->link = NULL;
}

int root(Tree T)
{
    return T.root;
}

int parent(Tree T, int child)
{
    Child temp;
    int i;
    for(i = 0; i < SIZE; i++){
        for(temp = T.nodes[i]; temp != NULL; temp = temp->link){
            if(temp->child == child){
                return i;
            }
        }
    }
    return -1;
}

int leftChild(Tree T, int parent)
{
    return (T.nodes[parent] != NULL)? T.nodes[parent]->child:-1;
}

int rightSibling(Tree T, int sibling)
{
    Child temp;
    int i;
    for(i = 0; i < SIZE; i++){
        for(temp = T.nodes[i]; temp != NULL && temp->link != NULL; temp = temp->link){
            if(temp->child == sibling){
                return temp->link->child;
            }
        }
    }
    return -1;
}

void preorder(Tree T, int node)
{
    if(node != -1){
        printf("%d ", node);
        preorder(T, leftChild(T, node));
        preorder(T, rightSibling(T, node));
    }
}

void inorder(Tree T, int node)
{
    if(node != -1){
        int temp = leftChild(T, node);
        inorder(T, temp);
        printf("%d ", node);
        while(temp != -1){
            temp = rightSibling(T, temp);
            inorder(T, temp);
        }
    }
}

void postorder(Tree T, int node)
{
    if(node != -1){
        postorder(T, leftChild(T, node));
        printf("%d ", node);
        postorder(T, rightSibling(T, node));
    }
}

int height(Tree T, int node)
{
    if(node != -1){
        node = leftChild(T, node);
        int val = 0;
        while(node != -1){
            int temp = height(T, node);
            if(val <= temp){
                val = temp;
                val++;;
            }
            node = rightSibling(T, node);
        }
        return val;
    }
    else {
        return 0;
    }
}

void main()
{
    Tree T;
    init(&T);
    insertRoot(&T, 5);
    insertChild(&T, 0, 5);
    insertChild(&T, 2, 5);
    insertChild(&T, 6, 5);
    insertChild(&T, 8, 2);
    insertChild(&T, 1, 6);
    insertChild(&T, 3, 6);
    insertChild(&T, 4, 1);
    insertChild(&T, 7, 1);
    /* Tree visual representation
            <-5->
    0->      <-2    <-6
            8->    1->  <-3
                4->  <-7
    */
   //preorder(T, root(T)); printf("\n");
   //inorder(T, root(T)); printf("\n");
   //postorder(T, root(T)); printf("\n");
   printf("%d", height(T, 6));
}