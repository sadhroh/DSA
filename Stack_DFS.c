#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int n;
int allVisited(int *v)
{
	int i=0;
	while(i<n)
	{
		if(!v[i++])
			return (0);
	}
	return (1);
}
void Stack_DFS(int (*adj[n]),int *v,int *stack,int top)
{
	int i;
	if(top==-1)
		return;
	int current = stack[--top];
	if(!v[current])
	{
		v[current]=1;
		printf("%d\n",current+1);
	}
	for(i=0;i<n;i++)
	{
		if(!v[i] && adj[current][i])
		{
			stack[top++]=current;
			stack[top++]=i;
			break;
		}
	}
	if(!allVisited(v))
		Stack_DFS(adj,v,stack,top);

}

int main()
{
	printf("Enter nodes: ");
	scanf("%d",&n);
	int *s = (int *)malloc(sizeof(int)*n);
	int *v = (int *)malloc(sizeof(int)*n);
	int **adj = (int **)malloc(n*sizeof(int *));
	int i,j,root,top=0;
	for(i=0;i<n;i++)
		adj[i] = (int *)malloc(sizeof(int)*n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		adj[i][i]=0;
		v[i]=0;
		if(i<n-1)
			printf("For %d:\n",i+1);
		for(j=i+1;j<n;j++)
		{
			printf("%d - %d: ",i+1,j+1);
			scanf("%d",&adj[i][j]);
			adj[j][i]=adj[i][j];
		}
		printf("\n");
	}
	printf("Enter root : ");
	scanf("%d",&root);
	root--;
	s[top++]=root;
	Stack_DFS(adj,v,s,top);
	
	return (0);
}
