#include<stdio.h>//not for devcpp
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

typedef struct
{node *start;
}LL;

void insertEnd(LL *l,int ele)
{
	node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
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
void display(LL *l)
{
	node *p;
	if(l->start==NULL)
	{
		printf("Linked List is empty\n");
		return;
	}
	p=l->start;
	
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void splitAt(LL *l1,LL *l2,int ele)
{
	node *p;
	
	if(ele==l1->start->data)
	{//if ele is the start element
		l2->start=l1->start;
		l1->start=NULL;
		return;
	}
	//search for the ele node
	p=l1->start;
	while(p->next!=NULL)
	{
		if(ele==p->next->data)
		break;
		else 
		p=p->next;		
	}
	//here if ele not found then l2->start is at null
	l2->start=p->next;
	p->next=NULL;
}
int main()
{
	LL l1,l2;
	int n1,ele,i;
    l1.start=NULL;
    l2.start=NULL;
    printf(" enter nos elements in first linked list\n ");
    scanf("%d",&n1);
    printf(" enter elements in first linked list\n");
    for(i=0;i<n1;i++)
    {
    	printf(" enter %d element \n",(i+1));
    	scanf("%d",&ele);
    	insertEnd(&l1,ele);
	}	 
	printf(" first linked list\n");
	display(&l1);
	printf(" enter value from where to split\n");
	scanf("%d",&ele);
	splitAt(&l1,&l2,ele);
	printf(" after spliting\n");
	printf(" first list\n");
		display(&l1);
		printf(" second list\n");
		display(&l2);
	
	return 0;
}
