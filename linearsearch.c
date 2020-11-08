#include<stdio.h>
int linearsearch(int a[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(x==a[i])
		return 1;
	}
	return 0;
}

int main()
{
	int a[20],n,i,x;
	printf(" enter nos of elements in array\n");
	scanf("%d",&n);
	
	printf("enter elements in array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf(" enter element to search\n");
	scanf("%d",&x);
	
	
	printf("elements in array\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	printf("\n");
	if(linearsearch(a,n,x))
	printf(" %d element is present in array\n",x);
	else
	printf(" %d element is not present in array\n",x);
	return 0;
}
