#include<stdio.h>
#include<malloc.h>
#include<conio.h>

int partition(int X[],int lb,int ub){
	int A = X[(lb + ub)/2];
	int *down = &X[ub];
	int *up = &X[lb];
	int t;

	while(up<=down){
		if(*down<=A){
			down--;
			if(*down<*(down-1)){
				t = *down;
				*down = *(down-1);
				*(down-1) = t;
			}
		}
		if(*up>A){
			up++;
			if(*up>*(up+1)){
				t = *up;
				*up = *(up+1);
				*(up+1) = t;
			}
		}
		if(up>down){
			t = *down;
			*down = *up;
			*up = t;
		}
		if(*down<*(down-1)){
			t = *down;
			*down = *(down-1);
			*(down-1) = t;
		}
		if(*up>*(up+1)){
			t = *up;
			*up = *(up+1);
			*(up+1) = t;
		}
	}
	for(t=lb;t<=ub;t++)
		printf("%d\t",X[t]);
	/*
	t = lb+(up - &X[lb]);
	printf("%d",t);
	*/
}

void quicksort(int X[],int lb,int ub){
	if(lb<ub){
		int j = partition(X,lb,ub);
		quicksort(X,lb,j-1);
		quicksort(X,j+1,ub);
	}
}

void main(){
	
	int N,i,*X;
	scanf("%d",&N);
	X = (int*)malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++){
		scanf("%d",&X[i]);
	}
	
	partition(X,1,N-1);
}
