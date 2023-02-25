#include<stdio.h>
#include<malloc.h>

int IsIdentity(int *ptr,int rows){
	int i,j,identityFlag;
	identityFlag = 1;
	for(i=0;i<rows;i++){
		for(j=0;j<rows;j++){
			if((i==j && *ptr!=1) || (i!=j && *ptr!=0)){
				identityFlag = 0;
				break;
			}
			ptr++;
		}
	}
	return identityFlag;
}

void main(int argc,char *argv[]){
	
	int N,*ptr,i;
	scanf("%d",&N);
	ptr = (int*)malloc(sizeof(int)*N*N);
	for(i=0;i<N*N;i++){
		scanf("%d",&ptr[i]);
	}
	if(IsIdentity(ptr,N)==1){
		printf("input matrix is identity matrix");
	}
	else{
		printf("input matrix is not an identity matrix");
	}
	free(ptr);
	ptr = NULL;
}
