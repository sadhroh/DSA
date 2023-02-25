#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

char *ch = NULL;

void minmax(unsigned int val, unsigned int *pmin, unsigned int *pmax){
	int ind,t,countOnes;
	ind = countOnes = 0;
	ch = (char*)malloc(sizeof(char)*2);
	while(val>0){
		t = val % 2;
		val = val / 2;
		if(ind!=0){
			ch = (char*)realloc(ch,strlen(ch)+1);
		}
		if(t==1){
			countOnes++;
		}
		ch[ind] = t + '0';
		ind++;
	}
	ch[ind] = '\0';
	ind--;
	countOnes--;
	t = strlen(ch)-countOnes-1;
	while(countOnes>=0){
		*pmin = *pmin + (int)pow(2,countOnes);
		countOnes--;
	}
	while(t<strlen(ch)){
		*pmax = *pmax + (int)pow(2,t);
		t++;
	}
}

void main(int argc,char *argv[]){
	unsigned int val,pmin,pmax;
	int t,ind;
	pmin = pmax = t = 0;
	scanf("%d",&val);
	minmax(val,&pmin,&pmax);
	ind = strlen(ch)-1;
	printf("Input value    : ");
	while(ind>=0){
		printf("%c",ch[ind]);
		if(ind%4==0){
			printf(" ");
		}
		ind--;
	}
	ind = strlen(ch)-1;
	printf("\nSmallest value : %d  ( ",pmin);
	while(pmin>0){
		t++;
		pmin = pmin / 2;
		printf("1");
		if(ind%4==0){
			printf(" ");
		}
		ind--;
	}
	ind = strlen(ch)-1;
	printf(")\nLargest value  : %d  ( ",pmax);
	while(t>0){
		printf("1");
		if(ind%4==0){
			printf(" ");
		}
		ind--;
		t--;
	}
	while(ind>=0){
		printf("0");
		if(ind%4==0){
			printf(" ");
		}
		ind--;
	}
	printf(")");
	free(ch);
	ch = NULL;
}
