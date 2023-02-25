#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int n;

void dfs(int root,int *v,int (*adj[n]))
{
	int i,j;
	printf("%d\n",root+1);
	v[root]=1;

	for(i=0;i<n;i++)
	{
		if(v[i]!=1 && adj[root][i])
		{
			dfs(i,v,adj);
		}
	}
}

int main()
{
	int i,j;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	int *v = (int *)malloc(n*sizeof(int));
	int **adj = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
		adj[i] = (int *)malloc(sizeof(int)*n);
	printf("Enter adjacency matrix: -\nEnter 0 if there is no direct link between any pair & 1 if present\n");
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
	printf("Enter the root node: ");
	scanf("%d",&root);
	dfs(root-1,v,adj);
	return 0;
}
