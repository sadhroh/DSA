#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void merge(int *arr,int i,int m,int j)
{
	int *leftArr = (int*)malloc(sizeof(int)*(m-i+1));
	int *rightArr = (int*)malloc(sizeof(int)*(j-m));
	int index=0;
	int leftInd=i,rightInd=m;
	while(index<(m-i+1))
	{
		leftArr[index]=arr[leftInd];
		leftInd++;
		index++;
	}
	index=0;
	while(index<(j-m))
	{
		rightArr[index]=arr[rightInd+1];
		rightInd++;
		index++;
	}
	index=i;
	leftInd=0,rightInd=0;
	while(leftInd<(m-i+1) && rightInd<(j-m))
	{
		if(leftArr[leftInd]<=rightArr[rightInd])
		{
			arr[index]=leftArr[leftInd];
			leftInd++;
		}
		else
		{
			arr[index]=rightArr[rightInd];
			rightInd++;
		}
		index++;
	}
	while(leftInd<(m-i+1))
	{
		arr[index]=leftArr[leftInd];
		leftInd++;
		index++;
	}
	while(rightInd<(j-m))
	{
		arr[index]=rightArr[rightInd];
		rightInd++;
		index++;
	}
}

void partition(int *arr,int i,int j)
{
	if(i<j)
	{
		int mid = (i + j) / 2;
		partition(arr,i,mid);
		partition(arr,mid+1,j);
		merge(arr,i,mid,j);
		//printf("%d-%d-%d\n",i,mid,j);
	}
	//printf("%d. %d\n",i,arr[i]);
}

int main()
{
	int n;
	printf("Enter total elements : ");
	scanf("%d",&n);
	int *arr = (int *)malloc(n*sizeof(int));
	int i;
	printf("Enter elements : - \n");
	for(i=0;i<n;i++)
	{
		printf("%d. ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nElements in ascending order : -\n");
	partition(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
