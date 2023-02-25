#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define INF 99999

int n;

int main()
{
	int i,j,k,ch;
	n=0;
	while(n<2)
	{
		printf("Enter total vertices > 1 : ");
		scanf("%d",&n);
	}
	int **cost = (int **)malloc(n*sizeof(int *));
	int **path = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		cost[i]=(int *)malloc(n*sizeof(int));
		path[i]=(int *)malloc(n*sizeof(int));
	}
	printf("Enter cost 0 if no path exists\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				printf("%d - %d : ",i+1,j+1);
				scanf("%d",&ch);
				if(ch!=0)
				{
					cost[i][j]=ch;
					path[i][j]=i;
				}
				else
				{
					cost[i][j]=INF;
					path[i][j]=INF;
				}
			}
			else
			{
				cost[i][j]=0;
			}
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				if(cost[j][k]>cost[j][i]+cost[i][k])
				{
					cost[j][k]=cost[j][i]+cost[i][k];
					path[j][k]=path[i][k];
				}
			}
		}
	}
	printf("Path matrix:-\n |\t");
	for(i=0;i<n;i++)
		printf("%d\t",i+1);
	printf("\n");
	for(i=0;i<n;i++)	
	{
		for(j=0;j<8;j++)
		{
			printf("-");
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d|\t",i+1);
		for(j=0;j<n;j++)
		{
			if(path[i][j]<INF)
				printf("%d\t",path[i][j]+1);
			else
				printf("NA\t");
		}
		printf("\n");
	}
	int sc,des,tc=0;
	printf("\nEnter source : ");
	scanf("%d",&sc);
	sc--;
	printf("Enter destination : ");
	scanf("%d",&des);
	des--;
	i=des;
	do
	{
		printf("%d<-",i+1);
		i=path[sc][i];
		tc+=cost[sc][i];
	}while(sc!=i);
	printf("%d",sc+1);
	printf("\nTotal cost : %d",tc);
	return 0;
}
