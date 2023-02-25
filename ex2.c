#include<stdio.h>
#include<malloc.h>

int searchElement(int *freq,int num,int freqInd){
	while(freqInd>-1){
		if(freq[freqInd]==num)
			break;
		freqInd--;
	}
	return freqInd;
}

void main(){
	int *freq = NULL;
	int *arr = (int*)malloc(sizeof(int)*10);
	int i,ind,freqInd;
	freqInd = -1;
	for(i=0;i<10;i++){
		scanf("%d",&arr[i]);
		ind = searchElement(freq,arr[i],freqInd);
		if(ind==-1){
			freqInd++;
			if(freq==NULL){
				freq = (int*)malloc(sizeof(int)*1);
			}
			else{
				freq = (int*)realloc(freq,freqInd+1);
			}
			freq[freqInd] = arr[i];
		}
	}
	printf("Non-repeating elements: ");
	for(i=0;i<10;i++){
		int count = 0;
		for(ind=0;ind<10;ind++)
		{
			if(arr[i]==arr[ind])
				count++;
		}
		if(count==1)
			printf("%d\t",arr[i]);
	}
	printf("\nUnique Elements: ");
	for(i=0;i<=freqInd;i++){
		printf("%d\t",freq[i]);
	}
	free(freq);
	free(arr);
	freq = NULL;
	arr = NULL;
}
