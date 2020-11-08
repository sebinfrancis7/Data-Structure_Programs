#include<stdio.h>
void insertionsort(int a[],int n)
{
	int i,j,x;
	for(i=1;i<n;i++)
	{
		x=a[i];
		j=i;
		while(j>0 && a[j-1]>x)
		{
			a[j]=a[j-1];
			j=j-1;
			
		}
		a[j]=x;
		
	}
}
int main()
{
	int a[20],n,i;
	printf(" enter nos of elements in array\n");
	scanf("%d",&n);
	
	printf("enter elements in array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf(" original order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	printf("\n");
	
	insertionsort(a,n);
	
	printf(" sorted order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
