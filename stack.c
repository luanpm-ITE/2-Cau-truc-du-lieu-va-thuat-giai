

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
}Stack;
void createStack(Stack *s)
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
void push(Stack *s,Node *p)
{
    if(s->head==NULL)
    {
        s->head=p;
        s->tail=p;
    }
    else
    {
        p->next=s->head;
        s->head=p;
    }
}
int pop(Stack *s,int *x)
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
    } return 0;
}
void loopStack(Stack s)
{
    Node *p=s.head;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}
void interchangSort(Stack s)
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
Node* searchX(Stack s,int x)
{
    Node *p=s.head;
    while(p!=NULL&&p->info!=x)
        p=p->next;
    return p;
}
void insertSorted(Stack *s,Node *new)
{
    Node *p=s->head,*q=NULL;
    while((p!=NULL)&&(p->info>new->info))
    {
        q=p;p=p->next;
    }
    if(q==NULL)
    {
        if(s->head==NULL)
            s->tail=NULL;
        push(s,new);
    }
    else
    {
        if(s->tail==NULL)
            s->tail=new;
        new->next=p;
        q->next=new;
    }
}
void deleteX(Stack *s,int x)
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
int main()
{
    Stack s;Node *p;
    int a[]={5,3,4,2,16,32};
    createStack(&s);
    for(int i=0;i<6;++i)
    {
        p=createNode(a[i]);
        push(&s,p);
    }
    printf("\nMy stack: ");
    loopStack(s);
    int x=17;
    Node *q=createNode(x);
    insertSorted(&s,q);
    printf("\nStack sau khi them so %d vao la: ",x);
    loopStack(s);
    deleteX(&s,x);
    printf("\nStack sau khi xoa so %d la: ",x);
    loopStack(s);
    printf("\nStack sau khi sort la: ");
    interchangSort(s);
    loopStack(s);
    // pop(&s,&x);
    // printf("\nStack sau khi pop so %d la: ",x);
    // loopStack(s);
    // pop(&s,&x);
    // printf("\nStack sau khi pop so %d la: ",x);
    // loopStack(s);
    return 0;
}