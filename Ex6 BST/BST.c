#include "BST.h"

/*
Args:
* root: The root pointer of the BST
   arr: The pointer to a integer array
   len: The length of the data, which needs to be stored in BST

Description:
* Create an BST with arr whose length is len
*/
void CreateBST(BST_P *root, int *arr, int len)
{
    BST_P p,q,parent=(*root);
    int i;
    (*root)=(BST_P)malloc(sizeof(BST_T));
    (*root)->data=arr[0];
    (*root)->lchild=(*root)->rchild=NULL;
    for(i=1;i<len;i++){
        p=(BST_P)malloc(sizeof(BST_T));
        p->data=arr[i];
        p->lchild=p->rchild=NULL;
        q=(*root);
        while(q){
            parent=q;
            if(p->data<q->data)
                q=q->lchild;
            else
                q=q->rchild;
        }
        if(parent->data>p->data)
            parent->lchild=p;
        else
            parent->rchild=p;
    }

}



/*
Args:
* root: The root pointer of the BST

Description:
* Destroy root BST, free all the memory of root BST
*/
void DestoryBST(BST_P *root)
{
    if((*root)==NULL)
        return ;
    if((*root)->lchild != NULL) {
        DestoryBST(&((*root)->lchild));
        (*root)->lchild=NULL;
    }
    if((*root)->rchild != NULL) {
        DestoryBST(&((*root)->rchild));
        (*root)->rchild=NULL;
    }
    if((*root)!=NULL){
        free(*root);
        (*root)=NULL;
        return ;
    }

}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to insert into BST

Description:
* Insert data into the root BST,return true.
* ATTENTION: If data already exist in BST, DO NOTIHNG and return false.
*/
bool InsertBSTNode(BST_P* root, DataType data)
{
    BST_P parent = (*root), p, head = (*root);
    if (!SearchBST(root, data))
    {
        p = (BST_P)malloc(sizeof(BST_T));
        p->data = data;
        p->lchild = p->rchild = NULL;
        while (head) {
            parent = head;
            if (data < parent->data)
                head = head->lchild;
            else
                head = head->rchild;
        }
        if (data < parent->data)
            parent->lchild = p;
        else parent->rchild = p;
        return true;
    }
    else
        return false;

}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to delete from BST

Description:
* Delete data from the root BST, and free the memory
* ATTENTION: If data doesn't exist in BST, DO NOTIHNG and return false.
*/
bool DeleteBSTNode(BST_P *root, DataType data)
{
    BST_P p=SearchBST(root,data),q,s,f=(*root),head=(*root);//p为所要查找要删除的结点
    if(p==NULL)
        return false;

   if (p->lchild==NULL && p->rchild==NULL) {
       while (head->data!=data) {
           f = head;
           if (data < f->data)
               head = head->lchild;
           else
               head = head->rchild;
       }//寻找p的双亲
       if(f->lchild==head)
           f->lchild=NULL;
       else f->rchild=NULL;
       free(p);
       return true;
   }

    if (p->rchild==NULL){
        q=p->lchild;
        p->data=q->data;
        p->lchild=NULL;
        free(q);
    } else if(p->lchild==NULL) {
        q = p->rchild;
        p->data = q->data;
        p->rchild=NULL;
        free(q);
    }
    else{
        q=p;s=p->lchild;
        while(s->rchild)
        {q=s;s=s->rchild;}
        p->data=s->data;
        if(q!=p)
            q->rchild=s->lchild;
        else q->lchild=s->lchild;
        free(s);

    }
    return true;





}

/*
Args:
* root: The root pointer of the BST
  data: The data you want to search

Description:
* Search data within the root BST, and return its BST pointer
* ATTENTION: If data doesn't exist in BST, return NULL.
*/
BST_P SearchBST(BST_P *root, DataType data)
{
    if(!(*root) || (*root)->data==data)
        return(*(root));
    else
        if((*root)->data>data)
            return(SearchBST(&(*root)->lchild,data));
        else
            return(SearchBST(&(*root)->rchild,data));

}



/*
Args:
* root: The root pointer of the BST

Description:
* visualize the MidOrderTraverse of root BST
*/
void MidOrderTraverse(BST_P root)
{
    if (root!=NULL)
    {
        MidOrderTraverse(root->lchild);
        printf("%d, ", root->data);
        MidOrderTraverse(root->rchild);
    }
}