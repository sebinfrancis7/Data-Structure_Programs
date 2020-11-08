#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
typedef struct node
{
	char data;
	struct node *left,*right;
}node;
typedef struct Tree
{
	node *root;
}Tree;

typedef struct stack
{
	node *a[MAX];
	int top;
}stack;

void push(stack *s,node *ele)
{
	s->a[++s->top]=ele;
}

node *pop(stack *s)
{
	s->top--;
	return s->a[s->top+1];
}
int isoperand(char ch)
{
	return (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z');
	
}

void display(stack *s)
{
	int i;
	for (i=s->top;i>=0; i--)
	  printf("%c ",s->a[i]->data);
	printf("\n");
}

void construct(Tree *t,char post[])
{
	stack s;
	int i,l;
	
	l=strlen(post);
	s.top=-1;
	
	for(i=0;i<l;i++)
	{
		node *p;
		display(&s);
		p=(node*)malloc(sizeof(node));
		p->data=post[i];
		p->left=p->right=NULL;
		//printf("%c ",post[i]);
		if(isoperand(post[i]))
		push(&s,p);
		else
		{
			p->right=pop(&s);
			p->left=pop(&s);
			push(&s,p);
		}
	}
	t->root=pop(&s);
	printf("Root = %c\n",t->root->data);

}


void inorder(node *x)
{
	if(x!=NULL)
	{
//		printf("Inside inorder\n");
		inorder(x->left);
		printf(" %c ",x->data);
		inorder(x->right);
	}
}
void preorder(node *x)
{
	if(x!=NULL)
	{
		printf(" %c ",x->data);
		preorder(x->left);
		preorder(x->right);
	}
}
void postorder(node *x)
{
	if(x!=NULL)
	{
	    postorder(x->left);
		postorder(x->right);
		printf(" %c ",x->data);
	}
}
int main()
{
	Tree t;
	char postfix[MAX];
	t.root=NULL;
	
	printf("enter the postfix expression\n");
	gets(postfix);
	puts(postfix);
	construct(&t,postfix);
	printf("Root = %c  ",t.root->data);
	printf("details\n");
	printf("inorder traversal\n");
	inorder(t.root);
	printf("preorder traversal\n");
	preorder(t.root);
	printf("postorder traversal\n");
	postorder(t.root);
	return 0;
}


