#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int isPrime(int x)
{
	
	int i,flag=0,j;
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			flag = 1;
		}
	}
	if(flag==0 && x>1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int countPrime(int l,int r)
{
	int flag,count=0;
	int i;
	int *arr = (int *)malloc((r-l+1)*sizeof(int));
	while(l<=r)
	{
		if(isPrime(l))
		{
			for(i=2;i<l;i++)
			{
				if(isPrime(i))
				{
					int d = l-i-1;
					if((d==(i+1)) && isPrime(d))
					{
						arr[count++]=l;
					}
					else
					{
						printf("%d = %d + %d + 1\n",l,i,d);
					}
				}
			}
		}
		l++;
	}
	return (count);
}

int main()
{
	int l,r;
	printf("Enter value of 'l': ");
	scanf("%d",&l);
	printf("Enter value of 'r': ");
	scanf("%d",&r);
	int c = countPrime(l,r);
	printf("There are %d such numbers in the range.",c);
}
