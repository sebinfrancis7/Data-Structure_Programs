#include<stdio.h>
void HeapUp(int h[],int i)
{
	int v=h[i];
	while((i>1)&&(h[i/2]<v))
	{
		h[i]=h[i/2];
		i=i/2;
	}
	h[i]=v;
}

void HeapDown(int h[],int i,int n)
{
	int v,j;
	v=h[i];
	j=i*2;
	
	while(j<=n)
	{
		if((j<n) && (h[j]<h[j+1]))
		j++;
			
			if(h[j]<h[j/2])
            break;
			
			h[j/2]=h[j];
			j=j*2;		
	}
	h[j/2]=v;
}

int main()
{
		int a[20],n,i,j,k,t;
	printf(" enter nos of elements in array\n");
	scanf("%d",&n);
	
	printf("enter elements in array\n");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	
    printf(" original order of elements\n");
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	
	printf("\n");
	
    for(i=1;i<=n;i++)
	{
	HeapUp(a,i);//heapify
    }
    
    //delete root and heapify again
    j=n;
    
    for(i=1;i<=j;i++)
    {
    	t=a[1];
    	a[1]=a[n];
    	a[n]=t;
    	n=n-1;
    	HeapDown(a,1,n);
    	
	}
    
    n=j;
   	printf(" sorted order of elements\n");
	for(i=1;i<=n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
