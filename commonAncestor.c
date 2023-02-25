#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

void addnode(struct node **btree,int data)
{
	struct node *temp;
	if((*btree)==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		(*btree)=temp;
	}
	else
	{
		if((*btree)->data<data)
			addnode(&(*btree)->right,data);
		else
			addnode(&(*btree)->left,data);
	}
}

int findAnces(struct node *btree,int n1,int n2)
{
	if(btree==NULL)
		return (0);
	if(btree->data==n1 || btree->data==n2)
		return (btree->data);
	int left = findAnces(btree->left,n1,n2);
	int right = findAnces(btree->right,n1,n2);
	if(left!=0  && right!=0)
		return (btree->data);
	if(left==0 && right ==0)
		return (0);
	if(left!=0)
		return (left);
	else
		return (right);
}

/*void printTree(struct node *btree)
{
	if(btree==NULL)
		return;
	printTree(btree->left);
	printf("%d\n",btree->data);
	printTree(btree->right);
}*/

void main()
{
	struct node *btree;
	btree=NULL;
	int ch,n1,n2;
	printf("Enter -1 to exit\n");
	
	do
	{
		printf("Node data : ");
		scanf("%d",&ch);
		if(ch!=-1)
			addnode(&btree,ch);
		else
			break;
		
	}while(1);
	
	printf("Ancestors :-\n");
	printf("Enter node : ");
	scanf("%d",&n1);
	printf("Enter node : ");
	scanf("%d",&n2);
	int anc=findAnces(btree,n1,n2);
	if(anc!=0)
		printf("The common ancestor of the nodes is %d\n",anc);
	else
		printf("No common ancestor present\n");
	//printTree(btree);
}
