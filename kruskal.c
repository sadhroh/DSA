#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define INF 99999

int n;

struct EDGE{
	int u;
	int v;
	int cost;
};

struct NODE{
	int data;
	int rank;
	struct NODE *parent;
};

struct NODE makeset(int i)
{
	struct NODE *temp=(struct NODE *)malloc(sizeof(struct NODE));
	temp->data=i;
	temp->rank=0;
	temp->parent=temp;
	return(*temp);
}

void unionset(int i,int j,struct NODE **node)
{
	struct NODE *temp,*pi,*pj;
	temp=*node;
	pi=&(temp[i]);
	temp=*node;
	pj=&(temp[j]);
	
	while(pi->parent!=pi)
		pi=pi->parent;
	while(pj->parent!=pj)
		pj=pj->parent;
	
	if(pi->rank==pj->rank)
	{
		pj->parent=pi;
		pi->rank+=1;
	}
	else
	{
		if(pi->rank>pj->rank)
		{
			pj->parent=pi;
		}
		else
		{
			pi->parent=pj;
		}
	}
}

int findset(int i,struct NODE **node)
{
	struct NODE *temp,*r;
	temp=*node;
	r=&(temp[i]);
	temp=r;
	while(temp->parent!=temp)
		temp=temp->parent;
	if(r!=temp)
	{
		r->parent=temp;
	}
	return (temp->data);
}

void sortEdges(struct EDGE **edge,int count)
{
	int i,j;
	struct EDGE *temp,*r;
	for(i=0;i<count;i++)
	{
		temp=*edge;
		r=*edge;
		for(j=i+1;j<count;j++)
		{
			if(r[i].cost>temp[j].cost)
			{
				int t;
				t=temp[j].u;
				temp[j].u=r[i].u;
				r[i].u=t;
				
				t=temp[j].v;
				temp[j].v=r[i].v;
				r[i].v=t;
				
				t=temp[j].cost;
				temp[j].cost=r[i].cost;
				r[i].cost=t;
			}
		}
	}
}

void kruskalMST(struct EDGE *edge,int count,struct NODE **node)
{
	sortEdges(&edge,count);
	int i,tc=0;
	struct NODE *temp;
	printf("\nEdge\tCost\n");
	for(i=0;i<count;i++)
	{
		temp=*node;
		if(findset(edge[i].u,&temp)!=findset(edge[i].v,&temp))
		{
			unionset(edge[i].u,edge[i].v,&temp);
			printf("%d<-%d\t%d\n",edge[i].u+1,edge[i].v+1,edge[i].cost);
			tc+=edge[i].cost;
		}
	}
	printf("Total cost = %d",tc);
}

int main()
{
	printf("Enter vertices : ");
	scanf("%d",&n);
	int i,j,count=0;
	
	//makeset operation
	struct NODE *node = (struct NODE *)malloc(n*sizeof(struct NODE));
	i=0;
	while(i<n)
	{
		node[i]=makeset(i);
		i++;
	}
	//makeset ends
	
	int **cost = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		cost[i] = (int *)malloc(n*sizeof(int));
		
	printf("Enter 0 if there's no direct connection\n");
	for(i=0;i<n;i++)
	{
		cost[i][i]=0;
		if(i<n-1)
			printf("For %d :-\n",i+1);
		for(j=i+1;j<n;j++)
		{
			printf("%d - %d : ",i+1,j+1);
			scanf("%d",&cost[i][j]);
			cost[j][i]=cost[i][j];
			if(cost[i][j]!=0)
				count++;
		}
		printf("\n");
	}
	
	struct EDGE *edge = (struct EDGE *)malloc(count*sizeof(struct EDGE));
	
	count=0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(cost[i][j]!=0)
			{
				edge[count].u=i;
				edge[count].v=j;
				edge[count].cost=cost[i][j];
				count++;
			}
		}
	}
	free(cost);
	kruskalMST(edge,count,&node);
	return 0;
}
