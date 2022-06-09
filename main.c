#include "BST.h"
#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define CLEAR   while((getchar()) != '\n');

/*
    Author: Jesse Jimenez
    Date: 6/8/2022
    Purpose: main.c file calls functions from
    BST.h file to implement and test BST data
    structure.
*/


int main()
{
    int sen = TRUE;
    int ch = 0;
    int res = 0;
    struct Node* root = NULL;   // root
    Obj o; // union holding pointers to functions

    do
    {
        int data = 0;
        int key = 0;
        ch = input_Line();
        switch(ch)
        {
        case(1): // Add node
                printf("Enter key to the node: ");
                scanf("%d",&key);
                CLEAR
                printf("Enter integer data to node: ");
                scanf("%d",&data);
                o.add = add_Node;
                o.add(&root,data,key);
            break;
        case(2): // remove node
                printf("Enter key to remove from BST: ");
                scanf("%d",&key);
                o.remove_Node = remove_Node;
                res = o.remove_Node(&root,key);
                printf("\nNode: %d removed: ",res);
            break;
        case(3): // Traverse tree
                o.inOrderTrav = in_Order_Traversal;
                o.inOrderTrav(root);
            break;
        case(4): // tree size
                o.getSize = get_Size;
                res = o.getSize(root);
                printf("BST size: %d\n",res);
            break;
        case(5): // free nodes
                if(root != NULL)
                {
                o.freeBST = free_BST;
                o.freeBST(&root);
                printf("List freed");
                }
                else{printf("List is empty"); }
            break;
        case(6): // terminate
                sen = FALSE;
                o.freeBST = free_BST;
                o.freeBST(&root);
            break;
        default:
            break;
        }
        CLEAR
    }
    while(sen != FALSE);
    return 0;
}


int input_Line()
{
    int sen = TRUE;
    char s[1];
    int c =0;
    int x =0;
    do
        {

            printf("Enter a selection 1-5: \n1.Add node\n2.Remove node\n3.Print BST\n4.BST size\n5.Free nodes\n6.Terminate\n");
            scanf("%1s",s);
            c = *s;
            if(c > '0' && c < '7')
                {
                    // get int
                    c = c - '0';
                    sen = FALSE;
                }
            else
                {
                    printf("Wrong format please enter a valid format\n");
                    CLEAR // clear buffer
                }
        }
    while(sen == TRUE);
    return c;
}

