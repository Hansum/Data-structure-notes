#include <stdio.h>
#include <conio.h>
#define MAX 15

typedef struct {
	int harr[MAX];
	int last;
}Heap;

void init(Heap *H);
void insertHeap(Heap *H, int data);
int deleteMin(Heap *H);
void heapSort(Heap *H);
void display(Heap H);


int main() {
	Heap h;
	int ret;
	init(&h);
	
	insertHeap(&h, 12);
	insertHeap(&h, 11);
	insertHeap(&h, 13);
	insertHeap(&h, 5);
	insertHeap(&h, 6);
	insertHeap(&h,7);
	printf("RESULT:\n");
	display(h);
	printf("\n");
	ret=deleteMin(&h);
	display(h);
	printf("\n");
	ret=deleteMin(&h);
	display(h);
	printf("\n");
	ret=deleteMin(&h);
	display(h);
	printf("\n");
	ret=deleteMin(&h);
	display(h);
	printf("\n");
	ret=deleteMin(&h);
	display(h);
	printf("\n");
	ret=deleteMin(&h);
	display(h);
	return 0;
}

void init(Heap *H) {
	H->last = -1;
}
void insertHeap(Heap *H, int data) {
	int child, parent,temp;
	
	
	if(H->last <= MAX) {
		H->last++;
		child = H->last;
		H->harr[child] = data;
		parent = (child - 1) / 2;
		
		while (child !=0 && H->harr[parent] > H->harr[child]) {
			temp = H->harr[parent];
			H->harr[parent] = H->harr[child];
			H->harr[child] = temp;
			child = parent;
			parent = (child - 1) /2;
		}
		
	}
}
int deleteMin(Heap *H) {
	int parent, child, LC, RC,temp,retval;
	
	if(H->last != -1) {
		temp = H->harr[0];
		H->harr[0] = H->harr[H->last];
		H->last--;
		
		parent = 0;
		LC = (2 * parent) + 1;
		RC = (2 * parent) + 2;
		
		while (LC <= H->last || RC <= H->last) {
			
			if (H->harr[LC] <= H->harr[RC]) {
				child = LC;
			} else {
				child = RC;
			}
			retval = H->harr[parent];
			H->harr[parent] = H->harr[child];
			H->harr[child] = retval;
			parent = child;
			LC = (2 * parent) + 1;
			RC = (2 * parent) + 2;
		}
	} else {
		temp = -1;
		printf("Heap is empty");
	}
	
	return temp;
}
void heapSort(Heap *H) {
	
}

void display(Heap H) {
	int ndx;
	
	for (ndx = 0; ndx <= H.last; ndx++) {
		printf("%d ",H.harr[ndx]);
	}
}
