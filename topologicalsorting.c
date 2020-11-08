#include<stdio.h>
int adj[10][10]={0},visited[10]={0},n;

void topologicalsort()
{
	int i,j,indeg[10]={0},nd,q[10],f=-1,r=-1;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(adj[j][i]==1)
			indeg[i]++;
		}
	}
	
	while(1)
	{
		for(i=0;i<n;i++)
		{
			if(indeg[i]==0 && visited[i]==0)
			{
				visited[i]=1;
				q[++r]=i;
			}
		}
		if(f==r)
		break;
		nd=q[++f];
		printf("%d ",nd+1);
		for(i=0;i<n;i++)
		{
			if(adj[nd][i]==1)
			indeg[i]--;
		}
	}
}

int main()
{
		int e,i,v1,v2;
	printf("enter nos of nodes\n");
	scanf("%d",&n);
	printf("enter nos of edges\n");
	scanf("%d",&e);
	printf("enter edge details\n");
	for(i=0;i<e;i++)
	{
		printf(" enter edge\n");
		scanf("%d %d",&v1,&v2);
		adj[v1-1][v2-1]=1;
	}
	topologicalsort();
	return 0;
}
