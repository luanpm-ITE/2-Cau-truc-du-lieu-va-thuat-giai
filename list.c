

#include <stdio.h>
#include <stdlib.h>
typedef struct tagNode
{
    int info;
    struct tagNode *next;
}Node;
typedef struct
{
    Node *head,*tail;
}List;
void createList(List*);
Node* createNode(int);
void addHead(List*,Node*);
void addTail(List*,Node*);
void loopList(List);
void sortList(List);
Node* searchX(List,int);
void insertSortedList(List*,Node*);
void deleteX(List*,int);
void destroyList(List);
int main()
{
    List l;Node *p;
    int a[]={1,2,4,8,16,32};
    createList(&l);
    for(int i=0;i<6;++i)
    {
        p=createNode(a[i]);
        addTail(&l,p);
    }
    printf("\nMy list: ");
    loopList(l);

    return 0;
}
void createList(List *l)
{
    l->head=NULL;
    l->tail=NULL;
}
Node* createNode(int x)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->info=x;
    p->next=NULL;
    return p;
}
void addHead(List *l,Node *p)
{
    if(l->head==NULL)
    {
        l->head=p;
        l->tail=p;
    }
    else
    {
        p->next=l->head;
        l->head=p;
    }
}
void addTail(List *l,Node *p)
{
    if(l->head==NULL)
    {
        l->head=p;
        l->tail=p;
    }
    else
    {
        l->tail->next=p;
        l->tail=p;
    }
}
void loopList(List l)
{
    Node *p=l.head;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
void sortList(List l)
{
    Node *i,*j;int temp;
    for(i=l.head;i!=l.tail;i=i->next)
        for(j=i->next;j!=NULL;j=j->next)
            if(i->info>j->info)
            {
                temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
}
Node* searchX(List l,int x)
{
    Node *p=l.head;
    while((p!=NULL)&&(p->info!=x))
        p=p->next;
    return p;
}
void insertSortedList(List *l,Node *new)
{
    Node *p=l->head,*q=NULL;
    while((p!=NULL)&&(p->info!=new->info))
    {
        q=p;
        p=p->next;
    }
    if(q==NULL)
    {
        if(l->head==NULL)
            l->tail=NULL;
        addHead(l,new);
    }
    else
    {
        if(l->tail==NULL)
            l->tail=new;
        q->next=new->next;
        q->next=new;
    }
}
void deleteX(List *l,int x)
{
    Node *p=l->head,*q=NULL;
    while((p!=NULL)&&(p->info!=x))
    {
        q=p;
        p=p->next;
    }
    if(p!=NULL)
    {
        if(q==NULL)
        {
            if(l->head==NULL)
                l->tail=NULL;
            p=l->head;
            p=p->next;
            free(p);
        }
        else
        {
            if(l->tail==NULL)
                l->tail=q;
            q->next=p->next;
            free(p);
        }
    }
}
void destroyList(List l)
{
    Node *p;
    while(l.head!=NULL)
    {
        p=l.head;
        p=p->next;
        free(p);
    }
    l.tail=NULL;
}