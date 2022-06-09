#ifndef BST
#define BST

#include<stdio.h>

/*
    Author: Jesse Jimenez
    Date: 6/8/2022
    Purpose: Header file contains declarations of functions and Nodes that are used
    to implement a Binary Search Tree data structure.
*/

// Sruct holds key, data and pointers to other nodes
typedef struct Node
{
    int key;
    int data;
    struct Node* right;
    struct Node* left;

}
Node;

/* Function prototypes declarations */
static Node* create_Node(int data,int key);
void add_Node(Node** root,int data,int key);
static int remove_Node(struct Node** root,int key);
static void in_Order_Succersor(Node* root,int* key,int* tpdata);
int get_Size(Node* root);
void free_BST(struct Node** root);
void in_Order_Traversal(Node* root);


// Union contains pointers to functions
typedef union Obj
{

    void (*add)(Node** root, int data, int key);
    int (*remove_Node)(struct Node** root, int key);
    int (*getSize)(Node* root);
    void (*freeBST)(struct Node** root);
    void (*inOrderTrav)(Node* root);
} Obj;


/* Static node returning function is allocates a node in the heap and returns
    its pointer */
static Node* create_Node(int data,int key)
{
    Node* temp = (Node* )calloc(sizeof(Node),1);
    temp->data = data;
    temp->key = key;
    return temp;
}

/*Int returning function, recursive iterates list and returns number
    of nodes in BST*/
 int get_Size(Node* root)
{
    if(root == NULL){return 0;}
    int c = 0;
    // left child traverse
    if(root->left != NULL)
        {
            c += get_Size(root->left);
        }
    c++; // inc Root
    // right child traverse
    if(root->right != NULL)
        {
            c += get_Size(root->right);
        }
    // return int done traverse
        return c;
}


/* Recursive function binary inserts node in the BST*/
void add_Node(Node** root,int data,int key)
{
    // If root is empty create a node and reassign root
    if(*root == NULL)
        {
            *root = create_Node(data,key);
        }
    else if((*root)->key < key)
        {
            add_Node(&((*root)->right),data,key);
        }
    else if((*root)->key > key)
        {
            add_Node(&((*root)->left),data,key);
        }
}

/*static int function removes a node in the BST and returns its data */
static int remove_Node(struct Node** root,int key)
{
    // Return null
    if(*root == NULL){return NULL;}
    // If key found check cases and remove
    else if(key == (*root)->key)
        {
            Node* temp = *root;
            int getData = temp->data;

            // Check cases
            // If leaf just delete it
            if(temp->right == NULL && temp->left == NULL )
                {
                    free(temp);
                    *root = NULL;
                    return getData;
                } // One child present
            else if(temp->right == NULL ^ temp->left == NULL)
                {
                    // If right has child new root otherwise left new root
                    *root = (temp->right != NULL) ? temp->right: temp->left;
                    free(temp);
                    return getData;
                } // Two children are present get Inorder Successor and become new root
                else
                {
                    int tpdata = 0;
                    int tpkey = 0;
                    // Call inorder function and swap data
                    in_Order_Succersor(temp->right,&tpkey,&tpdata);
                    // have data but remove successor then swap
                    remove_Node(&temp,tpkey);
                    // Node removed swap
                    (*root)->data = tpdata;
                    (*root)->key = tpkey;
                    return getData;
                }


        }// root key bigger go left
    else if((*root)->key > key)
        {
            remove_Node(&((*root)->left),key);
        }
    else // root key is less go right
        {
             remove_Node(&((*root)->right),key);
        }
}

/*static function returns returns key and data of the node succesor of root*/
static void in_Order_Succersor(Node* root,int* key,int* tpdata)
{
    // Traverse left tree intil least node is found
    if(root->left != NULL)
        {
            in_Order_Succersor(root->left,key,tpdata);
        }
    else // left is null return
        {
            *key = root->key;
            *tpdata = root->data;
            return *root;
        }
}

/*void function iterates through BST and prints its data */
void in_Order_Traversal(Node* root)
{
    if(root ==NULL){return;}
    // traverse left child and print it
    if(root->left != NULL)
        {
            in_Order_Traversal(root->left);
        }
         printf("(data: %d, key: %d)\n",root->data,root->key);
        // Traverse to the right child print it
    if (root->right != NULL)
        {
          in_Order_Traversal(root->right);
        }
}

/*void recursive function frees all nodes in the BST*/
void free_BST(struct Node** root)
{
    if(*root == NULL){return; }
    // Post Order traverse and free roots
    // Traverse left
    if((*root)->left != NULL)
        {
            free_BST(&((*root)->left));
        }
    // Traverse right
    if((*root)->right != NULL)
        {
            free_BST(&((*root)->right));
        }
    // free root
        free(*root);
        *root = NULL;
}


#endif
