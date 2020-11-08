#include<stdio.h>
int binarysearch(int a[],int low,int high,int x)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		
		if(x==a[mid])
		return 1;
		if(x<a[mid])
		return binarysearch(a,low,mid-1,x);
		else
		return binarysearch(a,mid+1,high,x);
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
	if(binarysearch(a,0,n-1,x))
	printf(" %d element is present in array\n",x);
	else
	printf(" %d element is not present in array\n",x);
	
	
	return 0;
}
