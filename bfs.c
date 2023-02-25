#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int n;

int qContains(int i,int *q,int top,int bottom)
{
	while(bottom<=top)
	{
		if(q[bottom++]==i)
			return 1;
	}
	return 0;
}

int allVisited(int *v)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(v[i]!=1)
			return 0;
	}
	return 1;
}

void bfs(int root,int *v,int (*adj[n]),int top,int bottom,int *q)
{
	if(top==bottom)
		top=bottom=0;
	int i,j;
	printf("%d\n",root+1);
	v[root]=1;
	for(i=0;i<n;i++)
	{
		if(v[i]!=1 && adj[root][i] && !qContains(i,q,top,bottom))
		{
			q[top++]=i;
		}
	}
	if(!allVisited(v))
		bfs(q[bottom++],v,adj,top,bottom,q);
}

int main()
{
	int i,j;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	int *v = (int *)malloc(n*sizeof(int));
	int *q = (int *)malloc(n*sizeof(int));
	int **adj = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		adj[i] = (int *)malloc(sizeof(int)*n);
	printf("Enter adjacency matrix: -\nEnter 0 if there is no direct link between any pair.\n");
	for(i=0;i<n;i++)
	{
		v[i]=0;
		if(i<n-1)
			printf("For vertex %d:\n",i+1);
		adj[i][i]=0;
		for(j=i+1;j<n;j++)
		{
			printf("%d & %d: ",i+1,j+1);
			scanf("%d",&adj[i][j]);
			adj[j][i]=adj[i][j];
		}
		printf("\n");
	}
	int root;
	int top=0;
	int bottom=0;
	printf("Enter the root node: ");
	scanf("%d",&root);
	bfs(root-1,v,adj,top,bottom,q);
	return 0;
}
