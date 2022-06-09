#include "BST.h"
#include<stdio.h>

/*
    Author: Jesse Jimenez
    Date: 6/8/2022
    Purpose: main.c file calls functions from
    BST.h file to implement and test BST data
    structure.
*/

int main()
{
    struct Node* root = NULL;
    add_Node(&root, 69, 10);
    add_Node(&root,7,25);
    add_Node(&root,10,28);
    add_Node(&root,7,27);
    in_Order_Traversal(root);
    remove_Node(&root,25);
    in_Order_Traversal(root);
    return 0;
}


