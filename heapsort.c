#include<stdio.h>
void HeapUp(int h[],int r,int b)
{
	int p,t;
if(b>r)
{
	p=(b-1)/2;
	if(h[p]<h[b])
	{
		t=h[p];
		h[p]=h[b];
		h[b]=t;
		HeapUp(h,r,p);
	}
}
}

void HeapDown(int h[],int r,int b)
{
	int lc,rc,mc,t;
	lc=2*r+1;
	rc=2*r+2;
	
	if(lc<=b)//left hai kya
	{
		if(lc==b)//right nahi hai
		mc=lc;
		else if(h[lc]>h[rc])
		mc=lc;
		else
		mc=rc;
		
		if(h[r]<h[mc])
		{
			t=h[r];
			h[r]=h[mc];
			h[mc]=t;
			HeapDown(h,mc,b);
			
		}
	}
}

int HeapSort(int h[],int n)
{
	int i,t;
	for(i=0;i<n-1;i++)
	HeapUp(h,0,i+1);
	
	for(i=n-1;i>0;i--)
	
	{
		t=h[0];
		h[0]=h[i];
		h[i]=t;
		HeapDown(h,0,i-1);
	}
	
}
int main()
{
		int a[20],n,i,j,k,t;
	printf(" enter nos of elements in array\n");
	scanf("%d",&n);
	
	printf("enter elements in array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
    printf(" original order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	printf("\n");
	
  HeapSort(a,n);
   	printf(" sorted order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
