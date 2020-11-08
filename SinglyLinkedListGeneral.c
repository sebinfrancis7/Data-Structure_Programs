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

void insertBeginning(LL *l,int ele)
{
	node *newrec;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
	
	newrec->next=l->start;
	l->start=newrec;	
}

void insertEnd(LL *l,int ele)
{	node *newrec,*p;
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
void insertAtPos(LL *l,int ele,int pos)
{	int i;
	node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));
	newrec->data=ele;
		if(pos>count(l)+1)
		{
        printf("invalid position entered\n");
        return;
	   }
	if(pos==1)
	{
		newrec->next=l->start;
		l->start=newrec;
		return;
	}
	p=l->start;
	for(i=0;i<pos-2;i++)
	p=p->next;
	
	newrec->next=p->next;
	p->next=newrec;
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
int deleteBeginning(LL *l)
{//p must refer to node to delete
	node *p;
	if(l->start==NULL)
	{
		return -1;
	}
	p=l->start;
    l->start=l->start->next;
   
	return p->data;
}

int deleteEnd(LL *l)
{
	node *p,*q;
	//p must refer to node to delete
	
	if(l->start==NULL)
	{
		return -1;
	}
	//if only one element
	if(l->start->next==NULL)
	{
		p=l->start;
		l->start=NULL;
	}
	else
	{//take q just before last
		q=l->start;
		while(q->next->next!=NULL)
		q=q->next;
		p=q->next;
		q->next=NULL;
	}
	return p->data;
}
int deletePos(LL *l,int pos)
{//p must refer the node to delete
	node *p,*q;
	int i;
 //if pos is  of first node
  if(pos==1)
  {
    p=l->start;
  l->start=l->start->next;
  p->next=NULL;
  return p->data;
}
	//q will refer to node just before the pos to delete
	q=l->start;
	for(i=0;i<pos-2;i++)
	q=q->next;
	p=q->next;
	q->next=p->next;
	p->next=NULL;
	return p->data;
}

void deleteElement(LL *l,int ele)
{	node *p,*q;
	if(l->start==NULL)
	{
		printf("Linked List is empty\n");
		return ;
	}
	if(l->start->data==ele)
	{
		p=l->start;
		l->start=l->start->next;
		p->next=NULL;
		return;
	}
	q=l->start;
	while(q->next!=NULL)
	{
		if(ele==q->next->data)
		break;
		else
		q=q->next;
	}
	p=q->next;
	if(p==NULL)
	{
		printf("%d is not found\n",ele);
	}
	else
	{q->next=p->next;
	p->next=NULL;
	}
}

int count(LL *l)
{
	node *p;
	int c=0;
	p=l->start;
	
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}

int search(LL *l,int ele)
{
	node *p;
	p=l->start;
	
	while(p!=NULL)
	{
		if(ele==p->data)
		return 1;
		else
		p=p->next;
	}
	return 0;
	
}

void sort(LL *l)
{int t;
	node *i,*j;
	
	for(i=l->start;i->next!=NULL;i=i->next)
	{
		for(j=l->start;j->next!=NULL;j=j->next)
		{
			if(j->data>j->next->data)
			{
				t=j->data;
				j->data=j->next->data;
				j->next->data=t;
			}
		}
	}
}

void reverse(LL *l)
{
	node *p,*q,*r;
	
	p=l->start;
	q=NULL;
	while(p!=NULL)
	{
		r=p->next;
		p->next=q;
		q=p;
		p=r;
	}
	l->start=q;
	
}




int main()
{
	LL l1;
	int ch,ele,pos;
    l1.start=NULL;
	while(1)
	{
		printf("\n1:InsertBeginning\t2:InsertEnd\t3:InsertPosition\t");
		printf("4:DeleteBeginning\t5:DeleteEnd\n6:DeletePosition\t");
		printf("7:DeleteElement\t8:Search\t9:count\t10:Sort\t11:Reverse\n");
		printf("12:Display\t13:Exit\n");
		
		printf("enter choice\n");
		scanf("%d",&ch);
		if(ch==13)
		break;
		switch(ch)
		{case 1:printf(" enter element to insert at Beginning\n");
		        scanf("%d",&ele);
		        insertBeginning(&l1,ele);
		        printf("\nupdated list\n ");
		        display(&l1);
		        break;
		case 2:printf(" enter element to insert at End\n");
		        scanf("%d",&ele);
		        insertEnd(&l1,ele);
		        printf("\nupdated list\n ");
		         display(&l1);
		        break;
		case 3:printf(" enter element to insert \n");
		        scanf("%d",&ele);
		        printf("enter position\n");
		        scanf("%d",&pos);
		        insertAtPos(&l1,ele,pos);
		         printf("\nupdated list\n ");
		         display(&l1);
		        break;
		case 4:ele=deleteBeginning(&l1);
		        if(ele==-1)
		        printf("Linked List is empty");
		        else
		        printf(" element deleted from beginning =%d\n",ele);
		         printf("\nupdated list\n ");
		         display(&l1);
				break;
		        
		case 5:ele=deleteEnd(&l1);
		        if(ele==-1)
		        printf("Linked List is empty");
		        else
		        printf(" element deleted from from End =%d\n",ele);
		         printf("\nupdated list\n ");
		         display(&l1);
				break;
		case 6: printf(" enter pos to delete the element\n");
		        scanf("%d",&pos);
		        ele=deletePos(&l1,pos);
		        if(ele==-1)
		        printf("Linked List is empty");
		        else
		        printf(" element deleted from %d position is  =%d\n",pos,ele);
		         printf("\nupdated list\n ");
		         display(&l1);
				break;
		case 7: printf(" enter element to delete\n ");
		        scanf("%d",&ele);
		        deleteElement(&l1,ele);
		         printf("\nupdated list\n ");
		         display(&l1);
				break;
		case 8: printf(" enter element to search\n");
		        scanf("%d",&ele);
		        if(search(&l1,ele))
		        printf(" %d is present in list\n",ele);
		        else
		        printf("%d is not present in list\n",ele);
		        break;
		case 9:printf(" total no of nodes = %d\n",count(&l1));break;
		case 10:sort(&l1);
		         printf("sorted list is\n");
		         display(&l1);
		         break;
		case 11:reverse(&l1);
		        printf("reversed array is\n");
		        display(&l1);
		        break;
		case 12:display(&l1);break;
		default:printf("invalid choice\n");
		}
	}	
	
	return 0;
}

