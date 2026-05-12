

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
}Queue;
void createQueue(Queue *s)
{
    s->head=NULL;
    s->tail=NULL;
}
Node* createNode(int x)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->info=x;
    p->next=NULL;
    return p;
}
void push(Queue *s,Node *p)
{
    if(s->head==NULL)
    {
        s->head=p;
        s->tail=p;
    }
    else
    {
        s->tail->next=p;
        s->tail=p;
    }
}
int pop(Queue *s,int *x)
{
    Node *p;
    if(s->head!=NULL)
    {
        if(s->head==NULL)
            s->tail=NULL;
        p=s->head;
        s->head=s->head->next;
        *x=p->info;
        free(p);
        return 1;
    }
    return 0;
}
void loopQueue(Queue s)
{
    Node *p=s.head;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
void sortQueue(Queue s)
{
    Node *i,*j;int temp;
    for(i=s.head;i!=s.tail;i=i->next)
        for(j=i->next;j!=NULL;j=j->next)
            if(i->info>j->info)
            {
                temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
}
Node* searchX(Queue s,int x)
{
    Node *p=s.head;
    while(p!=NULL&&p->info!=x)
        p=p->next;
    return p;
}
void deleteX(Queue *s,int x)
{
    Node *p=s->head,*q=NULL;
    while((p!=NULL)&&(p->info!=x))
    {
        q=p;p=p->next;
    }
    if(p!=NULL)
    {
        if(q==NULL)
        {
            if(s->head==NULL)
                s->tail=NULL;
            p->next=s->head;
            free(p);
        }
        else
        {
            if(s->tail==NULL)
                s->tail=q;
            q->next=p->next;
            free(p);
        }
    }
}
int countX(Queue s,int x)
{
    Node *p=s.head;
    int count=0;
    while(p!=NULL)
    {
        if(p->info==x)
        ++count;
        p=p->next;
    }
    return count;   
}
int main()
{
    Queue s;Node *p;
    int a[]={5,3,3,2,16,32};
    createQueue(&s);
    for(int i=0;i<6;++i)
    {
        p=createNode(a[i]);
        push(&s,p);
    }
    printf("\nMy queue: ");
    loopQueue(s);
    printf("\nQueue sau khi sort: ");
    sortQueue(s);
    loopQueue(s);
    int x=2;
    int kq=countX(s,x);
    if(kq)
        printf("\nSo %d xuat hien %d lan trong queue",x,kq);
    else printf("\nSo %d khong co trong queue",x);
    // pop(&s,&x);
    // printf("\nQueue sau khi pop %d ra la: ",x);
    // loopQueue(s);
    return 0;
}