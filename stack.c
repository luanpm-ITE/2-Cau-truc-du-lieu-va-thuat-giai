

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
    int x;
    pop(&s,&x);
    printf("\nStack sau khi pop so %d la: ",x);
    loopStack(s);
    pop(&s,&x);
    printf("\nStack sau khi pop so %d la: ",x);
    loopStack(s);
    return 0;
}