#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define INF 99999
int n;

int minWeight(int *mst,int *w)
{
	int i=0,node;
	int min = INF;
	while(i<n)
	{
		if(w[i]<min && !mst[i])
		{
			min=w[i];
			node=i;
		}
		i++;
	}
	return (node);
}

int allInMst(int *mst)
{
	int i=0;
	while(i<n)
	{
		if(!mst[i])
			return (0);
		i++;
	}
	return (1);
	
}

void printMST(int *p,int *w)
{
	int i=0;
	int tc=0;
	printf("\nParent\tChild\tWeight\n\n");
	while(i<n)
	{
		if(p[i]!=i)
		{
			printf("%d\t%d\t%d\n",p[i]+1,i+1,w[i]);
			tc+=w[i];
		}
		i++;
	}
	printf("Total weight : %d",tc);
}

void primMST(int (*adj[n]),int *mst,int *w,int *p)
{
	int i=0;
	int current = minWeight(mst,w);
	mst[current]=1;
	while(i<n)
	{
		if(!mst[i] && adj[current][i] && adj[current][i]<w[i])
		{
			w[i]=adj[current][i];
			p[i]=current;
		}
		i++;
	}
	if(!allInMst(mst))
		primMST(adj,mst,w,p);
	else
		printMST(p,w);
}

int main()
{
	printf("Enter nodes : ");
	scanf("%d",&n);
	printf("Enter weight matrix (0 if there's no link):-\n");
	int i,j;
	int **adj = (int **)malloc(sizeof(int *)*n);
	int *mst = (int *)malloc(sizeof(int)*n);
	int *w = (int *)malloc(sizeof(int)*n);
	int *p = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		adj[i]=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		w[i]=INF;
		mst[i]=0;
		p[i]=-1;
		adj[i][i]=0;
		if(i<n-1)
			printf("For %d :\n",i+1);
		for(j=i+1;j<n;j++)
		{
			printf("%d - %d : ",i+1,j+1);
			scanf("%d",&adj[i][j]);
			adj[j][i]=adj[i][j];
		}
		printf("\n");
	}
	int root;
	printf("Enter root : ");
	scanf("%d",&root);
	root--;
	w[root]=0;
	p[root]=root;
	primMST(adj,mst,w,p);
	
	return (0);
}
