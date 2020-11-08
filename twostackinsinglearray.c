#include<stdio.h>
#define MAX 10
typedef struct
{
	int a[MAX];
	int top1,top2;
}stack;

void push1(stack *s,int ele)
{
	if(s->top1+1==s->top2)
	{
	printf("stack 1 overflow\n");
	return;
    }
    s->top1++;
    s->a[s->top1]=ele;
}
void push2(stack *s,int ele)
{
	if(s->top2-1==s->top1)
	{
	printf("stack 2 overflow\n");
	return;
    }
    s->top2--;
    s->a[s->top2]=ele;
}
int isempty1(stack *s)
{
	if(s->top1==-1)
	return 1;
	else
	return 0;
}
int isempty2(stack *s)
{
	if(s->top2==MAX)
	return 1;
	else
	return 0;
}
int stacktop1(stack *s)
{
	if(isempty1(s))
	return -1;
	return s->a[s->top1];
}
int stacktop2(stack *s)
{
	if(isempty2(s))
	return -1;
	return s->a[s->top2];
}
int pop1(stack *s)
{
	int x;
	if(isempty1(s))
	return -1;
	x=s->a[s->top1];
	s->top1--;
	return x;
	
}
int pop2(stack *s)
{
	int x;
	if(isempty2(s))
	return -1;
	x=s->a[s->top2];
	s->top2++;
	return x;
	
}
void display1(stack *s)
{int i;
	if(isempty1(s))
	
	{
	printf("stack 1 underflow\n");
	return;
    }
    else
    {
    	for(i=s->top1;i>=0;i--)
    	printf(" %d\t",s->a[i]);
    	printf("\n");
    	
	}
}
void display2(stack *s)
{int i;
	if(isempty2(s))
	
	{
	printf("stack 2 underflow\n");
	return;
    }
    else
    {
    	for(i=s->top2;i<MAX;i++)
    	printf(" %d\t",s->a[i]);
    	printf("\n");
    	
	}
}
int main()
{
	int ch,ele;
	char sch;
	stack s;
	s.top1=-1;
	s.top2=MAX;
	
	while(1)
	{
	printf("F/f:first stack\n");
	printf("S/s:second stack\n");
	printf("E/e:exit\n");
	fflush(stdin);
	printf(" enter stack choice\n");
	scanf("%c",&sch);	
	if(sch=='E'||sch=='e')
	break;
	
	if(sch=='F'||sch=='f')	{
	
	while(1)
	{
		printf("1:push\n2:pop\n3:stacktop\n4:display\n5:exit\n");
		printf(" enter choice\n");
		scanf("%d",&ch);
		if(ch==5)
		break;
		switch(ch)
		{
			case 1:printf("enter element to push in stack 1\n");
			       scanf("%d",&ele);
			       push1(&s,ele);
			       break;
			case 2: ele=pop1(&s);
			         if(ele==-1)
					 printf("stack 1 underflow\n");
					 else
					 printf("element popped from stack 1 =%d\n",ele);
					 break;
			case 3:ele=stacktop1(&s);
			       if(ele==-1)
					 printf("stack 1 underflow\n");
					 else
					 printf("stack 1 top element  =%d\n",ele);
					 break;
			case 4: display1(&s);break;
			default:printf("invalid choice\n");      
		}
	}
}
else if(sch=='S'||sch=='s')
	{
	
	while(1)
	{
		printf("1:push\n2:pop\n3:stacktop\n4:display\n5:exit\n");
		printf(" enter choice\n");
		scanf("%d",&ch);
		if(ch==5)
		break;
		switch(ch)
		{
			case 1:printf("enter element to push in stack 2\n");
			       scanf("%d",&ele);
			       push2(&s,ele);
			       break;
			case 2: ele=pop2(&s);
			         if(ele==-1)
					 printf("stack 2 underflow\n");
					 else
					 printf("element popped from stack 2 =%d\n",ele);
					 break;
			case 3:ele=stacktop2(&s);
			       if(ele==-1)
					 printf("stack 2 underflow\n");
					 else
					 printf("stack 2 top element =%d\n",ele);
					 break;
			case 4: display2(&s);break;
			default:printf("invalid choice\n");      
		}
	}
}
else
printf("invalid stack choice\n");
}
return 0;
}
