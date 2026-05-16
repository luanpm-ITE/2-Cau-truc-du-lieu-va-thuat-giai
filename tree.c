

#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode
{
    int key;
    struct tagNode *left,*right;
}TNode;
typedef TNode *TREE;
void createTree(TREE *t)
{
    *t=NULL;
}
TNode* createTNode(int x)
{
    TNode *p=(TNode*)malloc(sizeof(TNode));
    p->key=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int insertTNode(TREE *t,TNode *p)
{
    if(*t!=NULL)
    {
        if((*t)->key==p->key)
            return 0;
        else
        {
            if((*t)->key>p->key)
                return insertTNode(&(*t)->left,p);
            else return insertTNode(&(*t)->right,p);
        }
    }
    *t=p;
    return 1;
}
TNode* searchX(TREE t,int x)
{
    while(t!=NULL)
    {
        if(t->key==x)
            return t;
        else
        {
            if(t->key>x)
                return searchX(t->left,x);
            else return searchX(t->right,x);
        }
    }
    return NULL;
}
void LNR(TREE t)
{
    if(t!=NULL)
    {
        LNR(t->left);
        printf("%d ",t->key);
        LNR(t->right);
    }
}
void NLR(TREE t)
{
    if(t!=NULL)
    {
        printf("%d ",t->key);
        NLR(t->left);
        NLR(t->right);
    }
}
void demNut(TREE t,int *s)
{
    if(t!=NULL)
    {
        (*s)++;
        demNut(t->left,s);
        demNut(t->right,s);
    }
}
void demLa(TREE t,int *s)
{
    if(t!=NULL)
    {
        if(t->left==NULL&&t->right==NULL)
            (*s)++;
        demLa(t->left,s);
        demLa(t->right,s);
    }
}
int main()
{
    TREE t;TNode *p;
    int a[] = {27,19,7,9,22,20,21,42,32,39,34,47,44},n=13;
    createTree(&t);
    for(int i=0;i<n;++i)
    {
        p=createTNode(a[i]);
        insertTNode(&t,p);
    }
    printf("\nMy tree: ");
    LNR(t);
    int s=0;
    demNut(t,&s);
    printf("\nSo nut: %d",s);
    s=0;demLa(t,&s);
    printf("\nSo la: %d",s);
    if(searchX(t,0)!=NULL)
        printf("\nTim thay");
    else printf("\nTim khong thay");
    return 0;
}