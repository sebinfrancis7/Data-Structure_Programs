//buckets with more than 2 slots for collision handling
#include<stdio.h>
#define N 11
void fillHashTable(int x[],int n,int h[][10],int count[])
{
	int i,hk;
	for(i=0;i<n;i++)
	{
		hk=x[i]%N;
		h[hk][count[hk]]=x[i];
		count[hk]++;
	}
}

int hashSearch(int h[][10],int count[],int ele)
{
	int i,hk;
	hk=ele%N;
	for(i=0;i<count[hk];i++)
	{
		if(ele==h[hk][i])
		return 1;
	}
	return 0;
}

int main()
{
	int x[50],n,h[N][10],count[N]={0},i,ele;
	printf("enter number of elements\n");
	scanf("%d",&n);
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	fillHashTable(x,n,h,count);
	
	printf("enter elements to search\n");
	scanf("%d",&ele);
	if(hashSearch(h,count,ele))
	printf("%d element found\n",ele);
	else
	printf("%d element not found\n",ele);
	return 0;
}
