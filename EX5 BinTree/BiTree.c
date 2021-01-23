#include "BiTree.h"

/*
Args:
* s:the string of preorder traversal sequence.

for example:
if you want to obtain an element of s,you can write the code:
DataType data = *((*s));
if you want to obtain the second element of s,you can write the code:
(*s)++;
DataType data = *((*s));

Return:
* Pointer of the bitree node.
Description:
* Create a bitree from preorder traversal sequence.
*/
BinaryTree CreateBinaryTreeFromPreOrderSequence(DataType **s)
{
    BinaryTree root;
    if( *((*s)) == '*') {
        (*s)++;
        return NULL;
    }
    else{
        root=(BinaryTree)malloc(sizeof(BinaryNode));
        root->left=root->right=NULL;
        root->data=(*((*s)++));
        root->left=CreateBinaryTreeFromPreOrderSequence(s);
        root->right=CreateBinaryTreeFromPreOrderSequence(s);
    }
    return root;
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of preorder traversal sequence you returned.
Return:
* None.
Description:
* return preorder traversal sequence of the bitree.
*/
void PreOrderTraversal(BinaryTree t, DataType **s)
{
    if(t==NULL) {
        (*((*s)++)) = '*';
        return;
    }
    (*((*s)++))=t->data;
    PreOrderTraversal(t->left,s);
    PreOrderTraversal(t->right,s);

}

/*
Args:
* t:the pointer of the bitree.
* s:the string of ineorder traversal sequence you returned.
Return:
* None.
Description:
* return inorder traversal sequence of the bitree.
*/
void InOrderTraversal(BinaryTree t, DataType **s)
{
    if(t==NULL)
    {
        (*((*s)++)) = '*';
        return;
    }
    InOrderTraversal(t->left,s);
    (*((*s)++))=t->data;
    InOrderTraversal(t->right,s);

}

/*
Args:
* t:the pointer of the bitree.
* s:the string of postorder traversal sequence you returned.
Return:
* None.
Description:
* return postorder traversal sequence of the bitree.
*/
void PostOrderTraversal(BinaryTree t, DataType **s)
{
    if(t==NULL)
    {
        (*((*s)++)) = '*';
        return;
    }
    PostOrderTraversal(t->left,s);
    PostOrderTraversal(t->right,s);
    (*((*s)++))=t->data;
}

/*
Args:
* head: pointer of the bitree.
Returns:
* None
Description:
* Destroy the bitree.
* Release all allocated memory.
*/
BinaryTree DestroyTree(BinaryTree *T)
{
    if((*T)==NULL)
        return (*T);
    if((*T)->left != NULL) {
        DestroyTree(&((*T)->left));
        (*T)->left=NULL;
    }
    if((*T)->right != NULL) {
        DestroyTree(&((*T)->right));
        (*T)->right=NULL;
    }
    if((*T)!=NULL){
        free(*T);
        (*T)=NULL;
        return(*T);
    }


}