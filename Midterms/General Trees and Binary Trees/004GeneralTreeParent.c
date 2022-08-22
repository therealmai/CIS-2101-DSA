#include <stdio.h>

#define SIZE 10
typedef int Tree[SIZE];

void init(Tree T)
{
    int i;
    for(i = 0; i < SIZE; i++){
        T[i] = -2;
    }
}

void insertChild(Tree T, int child, int parent)
{
    T[child] = parent;
}

int root(Tree T)
{
    int i, ret = -1;
    for(i = 0; i < SIZE; i++){
        if(T[i] == -1){
            ret = i;
            break;
        }
    }
    return ret;
}

int parent(Tree T, int child)
{
    return T[child];
}

int leftChild(Tree T, int parent)
{
    int i, ret = -1;
    for(i = 0; i < SIZE; i++){
        if(T[i] == parent){
            ret = i;
            break;
        }
    }
    return ret;
}

int rightSibling(Tree T, int sibling)
{
    int i, ret = -1;
    for(i = sibling+1; i < SIZE; i++){
        if(T[i] == T[sibling]){
            ret = i;
            break;
        }
    }
    return ret;
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

int depth(Tree T, int node)
{
    int ret = -1;
    while(node != -1){
        node = T[node];
        ret++;
    }
    return ret;
}

void main()
{
    Tree T;
    init(T);
    insertChild(T, 5, -1);
    insertChild(T, 0, 5);
    insertChild(T, 2, 5);
    insertChild(T, 6, 5);
    insertChild(T, 8, 2);
    insertChild(T, 1, 6);
    insertChild(T, 3, 6);
    insertChild(T, 4, 1);
    insertChild(T, 7, 1);
    /* Tree visual representation
        <-5->
    0->      <-2    <-6
            8->    1->  <-3
                4->  <-7
    */
   preorder(T, root(T)); printf("\n");
   //inorder(T, root(T)); printf("\n");
   //postorder(T, root(T)); printf("\n");
   //printf("%d", depth(T, 4));
}