#include<stdio.h>
#define MAX 10
typedef struct
{
	int a[MAX];
	int front,rear;
}queue;
void enqueueright(queue *q,int ele)//from rear end
{
	if(q->rear==MAX-1)
	{
	printf("queue overflow\n");
	return;
    }
    q->rear++;
    q->a[q->rear]=ele;
    
}
void enqueueleft(queue *q,int ele)//from front end
{
	if(q->front==-1)
	{
	printf("queue overflow\n");
	return;
    }
    q->a[q->front]=ele;
    q->front--;
    
}

int isempty(queue *q) 
{
	if(q->rear==q->front)
	return 1;
	else
	return 0;
}

int dequeueright(queue *q)//from rear end
{
	int x;
	if(isempty(q))
	return -1;
	x=q->a[q->rear];
	q->rear--;
	return x;
}
int dequeueleft(queue *q)//from front end(normal)
{
	int x;
	if(isempty(q))
	return -1;
	q->front++;
	x=q->a[q->front];
		return x;
	}
void display(queue *q)
{int i;
	if(isempty(q))
	{
	printf("queue underflow\n");
	return;
    }
    else
    {
    	for(i=q->front+1;i<=q->rear;i++)
    	printf(" %d\t",q->a[i]);
    	printf("\n");
    	
	}
}
int main()
{
	int ch,ele;
	queue q;
	q.front=MAX/2;
	q.rear=MAX/2;
	while(1)
	{
printf("1:ENQUERIGHT\n2:ENQUELEFT\n3:DEQUEUERIGHT\n4:DEQUEUELEFT\n5:DISPLAY\n6:EXIT\n");
		printf(" enter choice\n");
		scanf("%d",&ch);
		if(ch==6)
		break;
		switch(ch)
		{
			case 1:printf("enter element to enque\n");
			       scanf("%d",&ele);
			       enqueueright(&q,ele);
			       break;
		    case 2:printf("enter element to enque\n");
			       scanf("%d",&ele);
			       enqueueleft(&q,ele);
			       break;
			case 3: ele=dequeueright(&q);
			         if(ele==-1)
					 printf("queue underflow\n");
					 else
					 printf("element dequeued =%d\n",ele);
					 break;
			case 4: ele=dequeueleft(&q);
			         if(ele==-1)
					 printf("queue underflow\n");
					 else
					 printf("element dequeued =%d\n",ele);
					 break;
			
			case 5: display(&q);break;
			default:printf("invalid choice\n");      
		}
	}
return 0;
}
