#include<stdio.h>//not for devcpp
#include<stdlib.h>
typedef struct node
{
	int c,e;
	struct node *next;
}node;

typedef struct
{node *start;
}LL;

void insertEnd(LL *l,int cc,int ee)
{
	node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));
	newrec->c=cc;
	newrec->e=ee;
	newrec->next=NULL;
	
	if(l->start==NULL)
	l->start=newrec;
	
	else
	{
		p=l->start;
		while(p->next!=NULL)
		p=p->next;
		
		p->next=newrec;
		
	}
}
void read(LL *l)
{
	int i,n,cc,ee;
	printf("enter no of terms\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter coefficient and exp\n");
		scanf("%d %d",&cc,&ee);
		insertEnd(l,cc,ee);
	}
}
void display(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("NO Polynomial\n");
		return;
	}
	p=l->start;
	while(p!=NULL)
	{
		printf("%dX^%d ",p->c,p->e);
		p=p->next;
	}
	printf("\n");
}
void ADDPOLY(LL *l1,LL *l2,LL *l3)
{
node *p,*q;
p=l1->start;
q=l2->start;
while(p!=NULL&&q!=NULL)
{
	if(p->e>q->e)
	{
		insertEnd(l3,p->c,p->e);
		p=p->next;
	}
	else if(q->e>p->e)
	{
	insertEnd(l3,q->c,q->e);
	q=q->next;
	}
	else
	{
	insertEnd(l3,p->c+q->c,p->e);
	p=p->next;
	q=q->next;
	}
}
while(p!=NULL)
{
	insertEnd(l3,p->c,p->e);
	p=p->next;
}
while(q!=NULL)
{
	insertEnd(l3,q->c,q->e);
	q=q->next;
}
}
int main()
{
	LL l1,l2,l3;
	
    l1.start=NULL;
    l2.start=NULL;
    l3.start=NULL;
    read(&l1);
    read(&l2);
    ADDPOLY(&l1,&l2,&l3);
    printf("first polynomial\n");
	display(&l1);
	 printf("second polynomial\n");
	display(&l2);
	 printf("resultant polynomial\n");
	display(&l3);
	return 0; }
