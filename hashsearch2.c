//using chaining technique
#include<stdio.h>
#define N 11
typedef struct node
{
	int data;
	struct node *next;
}node;
typedef struct
{
	node *start;
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


int search(LL *l,int ele)
{
	node *p=l->start;
while(p!=NULL)
{
	if(ele==p->data)
	return 1;
	else
	p=p->next;
}
return 0;
}
void fillHashTable(int x[],int n,LL h[])
{
	int i,hk;
	for(i=0;i<n;i++)
	{
		hk=x[i]%N;
	insertEnd(&h[hk],x[i]);
	}
}

int hashSearch(LL h[],int ele)
{
	int i,hk;
	hk=ele%N;
	if(search(&h[hk],ele))
	return 1;
	else
	return 0;
}

int main()
{
	LL h[N];
	int x[50],i,n,ele;
	for(i=0;i<N;i++)
	h[i].start=NULL;
	
	printf("enter number of elements\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	fillHashTable(x,n,h);
	
	printf("enter elements to search\n");
	scanf("%d",&ele);
	if(hashSearch(h,ele))
	printf("%d element found\n",ele);
	else
	printf("%d element not found\n",ele);
	return 0;
}
