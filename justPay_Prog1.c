#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define INF 9999

int N,M,T,C;

int minWeight(int *v,int *w,int n)
{
	int min=INF;
	int node,i;
	for(i=0;i<n;i++)
	{
		if(!v[i] && w[i]<min)
		{
			node=i;
			min=w[i];
		}
	}
	return (node); 
}

int visitAll(int *v,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!v[i])
			return 0;
	}
	return 1;
}

int adjustTime(int totalCost,int unitTime,int unitCost)
{
	int flag=0;
	int i=0;
	int counter=0;
	while(i<totalCost)
	{
		if(i%unitTime==0)
		{
			if(flag)
				flag=0;
			else
				flag=1;
		}
		if(counter%unitCost==0)
		{
			if(flag)
				counter++;
		}
		else
		{
			counter++;
		}
		i++;
	}
	int adjustedTime=totalCost+(totalCost-counter);
	return adjustedTime;
}

void printPath(int *w,int j)
{
	int i;
	while(j>0)
	{
		printf("%d->",w[j]+1);
		j--;
	}
	printf("%d",w[j]+1);
}

void minDistance(int (*dis[N]),int *v,int *p,int *w)
{
	int i,j;
	int current=minWeight(v,w,N);
	//printf("%d\n",current);
	while(!visitAll(v,N) && current!=N-1)
	{
		v[current]=1;
		for(i=0;i<N;i++)
		{
			if(w[current]+dis[current][i]<w[i] && !v[i] && i!=current)
			{
				p[i]=current;
				w[i]=w[current]+dis[current][i];
			}
		}
		current=minWeight(v,w,N);
	}
	int totalCost=w[N-1];
	int total=adjustTime(totalCost,T,C);
	printf("%d\n",total);
	i=N-1;
	j=0;
	while(p[i]!=i)
	{
		w[j]=i;
		i=p[i];
		j++;
	}
	w[j]=0;
	printPath(w,j);
}

int main()
{
	scanf("%d %d %d %d",&N,&M,&T,&C);
	int i,j;
	//printf("%d %d %d %d",N,M,T,C);
	int *v=(int *)malloc(sizeof(int)*N);
	int *p=(int *)malloc(sizeof(int)*N);
	int *w=(int *)malloc(sizeof(int)*N);
	int **dis=(int **)malloc(sizeof(int *)*N);
	for(i=0;i<N;i++)
		dis[i]=(int *)malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++)
	{
		v[i]=0;
		p[i]-1;
		w[i]=INF;
		for(j=0;j<N;j++)
		{
			dis[i][j]=INF;
		}
	}
	
	for(i=0;i<M;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		dis[x][y]=C;
		dis[y][x]=C;
	}
	w[0]=0;
	p[0]=0;

	minDistance(dis,v,p,w);
	
	return 0;
}
