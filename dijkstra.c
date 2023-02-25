#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define INF 99999

int minWeight(int *v,int *w,int n)
{
	int i,min=INF,node;
	for(i=0;i<n;i++)
	{
		if(v[i]!=1 && w[i]<min)
		{
			min = w[i];
			node = i;
		}
	}
	return (node);
}

int visitAll(int *v,int n)
{
	int c=0,i;
	for(i=0;i<n;i++)
	{
		if(v[i]==1)
		{
			c++;
		}
	}
	if(c==n)
	{
		return (1);
	}
	return (0);
}

int main()
{
	int n,i,j,ch,k,sc=0,des=0;
	
	printf("Enter the total nodes: ");
	scanf("%d",&n);
	
	int *p = (int *)malloc(sizeof(int)*n);
	int *v = (int *)malloc(sizeof(int)*n);
	int *w = (int *)malloc(sizeof(int)*n);
	int **adj = (int **)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++)
	{
		adj[i]=(int *)malloc(sizeof(int)*n);
		adj[i][i]=INF;
	}
	printf("\nEnter 99999 or 0 if there is no direct connection between two vertices\n");
	for(i=0;i<n;i++)
	{
		p[i]=-1;
		v[i]=0;
		w[i]=INF;
		if(i<n-1)
			printf("For %d: -\n",(i+1));
		for(j=i+1;j<n;j++)
		{
			printf("Enter cost between %d to %d: ",(i+1),(j+1));
			scanf("%d",&adj[i][j]);
			if(adj[i][j]==0)
			{
				adj[i][j]=INF;
			}
			adj[j][i]=adj[i][j];
		}
		printf("\n");
	}


	while(sc<=0 || sc>n)
	{
		printf("Enter the SOURCE vertex between 1 to %d: ",n);
		scanf("%d",&sc);		
	}
	sc--;
	w[sc]=0;
	p[sc]=sc;
	while(des<=0 || des>n)
	{
		printf("Enter the DESTINATION vertex between 1 to %d: ",n);
		scanf("%d",&des);		
	}
	des--;

	int current=minWeight(v,w,n);
	do
	{
		v[current]=1;
		for(j=0;j<n;j++)
		{
			if((w[current]+adj[current][j]<w[j]) && j!=current && v[j]!=1)
			{
				p[j]=current;
				w[j]=w[current]+adj[current][j];
			}
		}
		current=minWeight(v,w,n);
	}while(current!=des && !visitAll(v,n));
	
	if(current==des)
	{
		i=0;
		w[i++]=des+1;
		while(p[des]!=sc)
		{
			w[i]=p[des]+1;
			i++;
			des=p[des];
		}
		w[i]=p[des]+1;
		printf("\nTotal cost: %d\n",w[des]+(i-1));
		while(i>0)
		{
			printf("%d->",w[i]);
			i--;
		}
		printf("%d",w[0]);
	}
	else
	{
		printf("\nNo path found!!\n");
	}
	return 0;
}
