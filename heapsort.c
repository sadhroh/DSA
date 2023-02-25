#include<malloc.h>
#include<stdio.h>

void maxheapify(int *heap,int i,int size) {
	int l,r,largest;
	l=(2*i)+1;
	r=(2*i)+2;
	if(l<=size && heap[l]>heap[i]) {
		largest=l;
	} else {
		largest=i;
	}
	if(r<=size && heap[r]>heap[largest]) {
		largest=r;
	}
	if(largest!=i) {
		int temp = heap[largest];
		heap[largest] = heap[i];
		heap[i] = temp;
		maxheapify(heap,largest,size);
	}
}

void buildheap(int *heap,int size) {
	int i = size/2;
	while(i>=0) {
		maxheapify(heap,i,size);
		i--;
	}
}

int extractmax(int *heap,int size) {
	int max=heap[0];
	heap[0]=heap[size];
	maxheapify(heap,0,size-1);
	return (max);
}

void heapsort(int *heap,int size) {
	while(size>=0) {
		heap[size]=extractmax(heap,size);
		size--;
	}
}

int main() {

	int n;
	printf("Enter total numbers: ");
	scanf("%d",&n);

	int *heap = (int*)malloc(sizeof(int)*n);
	int i;
	printf("Enter numbers:-\n");
	for(i=0; i<n; i++) {
		printf("%d. ",i+1);
		scanf("%d",&heap[i]);
	}
	buildheap(heap,n-1);
	heapsort(heap,n-1);
	printf("\n\nAfter sorting:-\n");
	for(i=0; i<n; i++) {
		printf("%d\n",heap[i]);
	}
	return 0;
}
