#include<conio.h>
#include<malloc.h>
#include<stdio.h>
#include<windows.h>

struct tree{
	struct tree *left;
	int data;
	struct tree *right;
};

void insert(struct tree **root,int data)
{
	struct tree *temp;
	if((*root)==NULL)
	{
		(*root)=(struct tree*)malloc(sizeof(struct tree));
		(*root)->left=NULL;
		(*root)->data=data;
		(*root)->right=NULL;
	}
	else if(data!=(*root)->data)
	{
		if(data>(*root)->data)
			insert(&((*root)->right),data);
		else
			insert(&((*root)->left),data);
	}
	else
	{
		printf("Duplicate entry\nData not accepted\n");
	}
}

void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

void deltree(struct tree *root)
{
	if(root!=NULL)
	{
		deltree(root->left);
		deltree(root->right);
	}
	free(root);
}

int search(struct tree **root,struct tree **parent,struct tree **x,int data)
{
	struct tree *t;
	t=*root;
	int flag=0;
	*parent = NULL;
	while(t!=NULL)
	{
		if(t->data==data)
		{
			*x=t;
			flag=1;
			break;
		}
		*parent = t;
		if(data>t->data)
			t=t->right;
		else
			t=t->left;
	}
	return (flag);
}

void delnode(struct tree **root,int data)
{
	if((*root)==NULL)
	{
		printf("No tree present\n");
		return;
	}
	struct tree *parent,*x,*xnext;
	parent=x=NULL;
	if(search(root,&parent,&x,data))
	{
		if(x->left!=NULL && x->right!=NULL)
		{
			parent=x;
			xnext=x->right;
			while(xnext->left!=NULL)
			{
				parent=xnext;
				xnext=xnext->left;
			}
			x->data=xnext->data;
			x=xnext;
		}
		if(x->left==NULL && x->right==NULL)
		{
			if(parent->right==x)
				parent->right=NULL;
			else
				parent->left=NULL;
			
			free(x);
			return;
		}
		if(x->left!=NULL && x->right==NULL)
		{
			if(parent->left==x)
				parent->left=x->left;
			else
				parent->right=x->left;
			
			free(x);
			return;
		}
		if(x->left==NULL && x->right!=NULL)
		{
			if(parent->left==x)
				parent->left=x->right;
			else
				parent->right=x->right;
			
			free(x);
			return;
		}
	}
	else
	{
		printf("%d does not exist\n",data);
		return;
	}
}

void menu()
{
	printf("\n----------OPTIONS----------\n");
	printf("1. GROUP DATA INSERT\n");
	printf("2. SINGLE DATA INSERT\n");
	printf("3. TRAVERSE INORDER\n");
	printf("4. SEARCH DATA\n");
	printf("5. DELETE DATA\n");
	printf("6. RESET ALL\n");
	printf("7. EXIT\n");
	printf("**********\nEnter Choice : ");
}

void ginsert(struct tree **root)
{
	int i;
	printf("Enter nodes :-\nEnter -1 to stop\n");
	while(1)
	{
		scanf("%d",&i);
		if(i==-1)	
			break;
		else
			insert(&(*root),i);
	}
}
int main()
{
	int n,i,ch;
	struct tree *root;
	root=NULL;

	do
	{
		menu();
		scanf("%d",&ch);
		printf("**********\n");
		switch(ch)
		{
			case 1:{
				printf("Group Data\n");
				ginsert(&root);
				break;
			}
			case 2:{
				printf("Single Data\nEnter data : ");
				scanf("%d",&n);
				insert(&root,n);
				break;
			}
			case 3:{
				printf("Traverse Inorder\n");
				inorder(root);
				break;
			}
			case 4:{
				printf("Search Data\nEnter data : ");
				scanf("%d",&n);
				struct tree *par,*abt;
				par=abt=NULL;
				if(search(&root,&par,&abt,n))
				{
					printf("Data present\n");
					//printf("Parent : %d",par->data);
				}
				else
				{
					printf("No Such Data Found\n");
				}
				break;
			}
			case 5:{
				printf("Delete Data\nEnter data : ");
				scanf("%d",&n);
				delnode(&root,n);
				break;
			}
			case 6:{
				printf("Reset All\nConfirm (1/0) : ");
				scanf("%d",&n);
				if(n)
				{
					deltree(root);
					root=NULL;
				}
				system("cls");
				break;
			}
			case 7:{
				printf("Exit\n");
				deltree(root);
				break;
			}
			default:{
				printf("!!!!!!!!!!!\nIncorrect Option\n!!!!!!!!!!\n");
				break;
			}
		}
	}while(ch!=7);
	system("cls");
	return 0;
}
