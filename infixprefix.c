#include<stdio.h>
#include<string.h>
#define MAX 50
typedef struct
{
	char a[MAX];
	int top;
	
}stack;

void push(stack *s,char ele)
{
	s->top++;
	s->a[s->top]=ele;
}
char pop(stack *s)
{
	char x;
	x=s->a[s->top];
	s->top--;
	return x;
}
int isempty(stack *s)
{
	if(s->top==-1)
	return 1;
	else
	return 0;
}
char stacktop(stack *s)
{
	return s->a[s->top];
}
int isoperand(char x)
{
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z'))
	return 1;
	else
	return 0;
}
int icp(char x)
{
	switch(x)
	{
		case ')':return 3;
		case '+':
		case'-':return 1;
		case '*':
		case '%':
	    case '/':return 2;
	    
	}
	return -1;
}
int isp(char x)
{
	switch(x)
	{
		case ')':return 0;
		case '+':
		case'-':return 1;
		case '*':
		case '%':
	    case '/':return 2;
	    
	}
	return -1;
}
void convert(char infix[],char pre[])
{
	stack s;
	s.top=-1;
	int i,k=0;
	char x,ele;
	
	for(i=strlen(infix);i>=0;i--)
	{
		x=infix[i];
		
		if(x==')')
		push(&s,x);
		
		else if(x=='(')
		{
			while(1)
			{
			 ele=pop(&s);
				if(ele==')')
				break;
				pre[k++]=ele;
			}
			}
		
		else if(isoperand(x))
		pre[k++]=x;
		
		else if(isempty(&s))
		push(&s,x);
		else if(icp(x)>isp(stacktop(&s)))
		push(&s,x);
		else
		{
			while((isempty(&s)==0)&&(icp(x)<isp(stacktop(&s))))
			{
				ele=pop(&s);
			pre[k++]=ele;
			}
			push(&s,x);
		}
		
	}//for
	while(isempty(&s)==0)
	{
		ele=pop(&s);
		pre[k++]=ele;
	}
	pre[k]='\0';
		strrev(pre);
	}
	int main()
	{
		char infix[50];
		char prefix[50];
		printf("\n enter infix expression\n");
		gets(infix);
		convert(infix,prefix);
		printf("prefix expression = %s\n",prefix);
		return 0;
	}
	



