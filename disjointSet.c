#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct NODE{
	int data;
	int rank;
	struct NODE *parent;
};

struct NODE makeset(int i)
{
	struct NODE *temp=(struct NODE *)malloc(sizeof(struct NODE));
	temp->data=i+1;
	temp->rank=0;
	temp->parent=temp;
	return(*temp);
}

void unionset(int i,int j,struct NODE **nodes)
{
	struct NODE *temp;
	struct NODE *pj;
	struct NODE *pi;
	temp=*nodes;
	pj=&(temp[j-1]);
	temp=*nodes;
	pi=&(temp[i-1]);
	
	while(pi->parent!=pi)
		pi=pi->parent;
	while(pj->parent!=pj)
		pj=pj->parent;
		
	if(pi==pj)
	{
		printf("They are already joined\n");
		return;
	}
	else
	{
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
}

struct NODE* findset(int i,struct NODE **nodes)
{
	struct NODE *temp,*r;
	temp=*nodes;
	r=&(temp[i-1]);
	temp=r;

	while(temp->parent!=temp)
		temp=temp->parent;
	
	if(r->parent!=temp)
	{
		r->parent=temp;
	}
	return(temp);
}

int main()
{
	int n;
	printf("Enter the number of nodes : ");
	scanf("%d",&n);

	struct NODE *nodes=(struct NODE *)malloc(n*sizeof(struct NODE));
	int i=0;
	printf("MAKESET OPERATION!!\n");
	while(i<n)
	{
		nodes[i]=makeset(i);
		i++;
	}
	printf("MAKE SET DONE!!\n");
	printf("UNION OPERATION\n");
	int ch;
	while(ch!=-1)
	{
		int n1=0,n2=0;
		while(n1<=0 || n1>n)
		{
			printf("Enter node1 : ");
			scanf("%d",&n1);
		}
		while(n2<=0 || n2>n)
		{
			printf("Enter node2 : ");
			scanf("%d",&n2);
		}

		unionset(n1,n2,&nodes);
		printf("Exit(-1) ? : ");
		scanf("%d",&ch);
	}
	printf("FIND SET OPERATION\n");
	struct NODE *t;
	while(1)
	{
		printf("Enter node : ");
		scanf("%d",&n);
		if(n==-1)
			break;
		t=findset(n,&nodes);
		printf("Data->%d\tRank->%d\tParent->%d\n",t->data,t->rank,t->parent->data);
	}
	
	
	return 0;
}
