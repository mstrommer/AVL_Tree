//
//  bintree.c
//  AVL_Tree
//
//  Created by Michael Strommer on 02.07.21.
//

#include "bintree.h"

binTree *t_init(){
    binTree *tmp = (binTree *)malloc(sizeof(binTree));
    tmp->root = NULL;
    tmp->size = 0;
    return tmp;
}

node *insertNode(node *start, int key, const char *data){
    node *newNode;
    if (start == NULL) {
        newNode = (node *) malloc(sizeof(node));
        if (newNode != NULL) {
            newNode->data = (char*) malloc(strlen(data)+1);
            strcpy(newNode->data, data);
            newNode->key = key;
            newNode->right = newNode->left = NULL;
        }
        return newNode;
    }
    if (key < start->key) {
        newNode = insertNode(start->left, key, data);
        if (start->left == NULL)
            start->left = newNode;
    } else {
        newNode = insertNode(start->right, key, data);
        if (start->right == NULL)
            start->right = newNode;
    }
    return newNode;
}

node *insert(binTree *t, int key, const char *data){
    node *newNode;
    newNode = insertNode(t->root, key, data);
    if (t->root == NULL) t->root = newNode;
    if (newNode != NULL) t->size++;
    return newNode;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int treeDepth(node *start){
    if (start == NULL) {
        return 0;
    }
    else {
        return 1 +  max(treeDepth(start->left),
                        treeDepth(start->right));
    }
}

