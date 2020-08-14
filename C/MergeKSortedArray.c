////http://www.geeksforgeeks.org/merge-k-sorted-arrays/

#include<stdio.h>
#include<math.h>
#include<limits.h>

#define N 4

typedef struct Heap {
	int element;
	int row;
	int column;
} Heap;

void Swap(Heap* array, int i, int j) {
	Heap temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void Heapify(Heap* minHeap, int position, int k) {
	int minIndex = position;
	int childIndex1 = 2*minIndex + 1;
	int childIndex2 = childIndex1 + 1;
	int smallest = minIndex;
	
	//Recursive Solution
	/*if(childIndex1 < k && minHeap[childIndex1].element < minHeap[minIndex].element)
		smallest = childIndex1;
	if(childIndex2 < k && minHeap[childIndex2].element < minHeap[smallest].element)
		smallest = childIndex2;
	if(smallest != minIndex) {
		Swap(minHeap, smallest, minIndex);
		Heapify(minHeap, smallest, k);
	}*/

	while(minIndex < k) {
		if(childIndex1 < k && minHeap[minIndex].element > minHeap[childIndex1].element)
			smallest = childIndex1;
		if(childIndex2 < k && minHeap[smallest].element > minHeap[childIndex2].element)
			smallest = childIndex2;
		if(smallest != minIndex) {
			Swap(minHeap, minIndex, smallest);
			minIndex = smallest;
			childIndex1 = 2*minIndex + 1;
       			childIndex2 = childIndex1 + 1;
		}
		else
			break;
	}
}

void Insert(Heap* minHeap, int data, int position, int row, int column) {
	minHeap[position].element = data;
	minHeap[position].row = row;
	minHeap[position].column = column;
}

void MergeKArrays(int arr[][N], int k) {
	int newArray[k*N];
	Heap minHeap[k];
	int count = 0, i = 0, j;
	while(count < k) {
		Insert(minHeap, arr[count][0], count, count, 0);
		count++;
	}

	for(i = (k - 1)/2; i >= 0; i--)
		Heapify(minHeap, i, k);
	
	for(i = 0; i < N*k; i++) {
		newArray[i] = minHeap[0].element;
		if(minHeap[0].column + 1 < N) {
			Insert(minHeap, arr[minHeap[0].row][minHeap[0].column + 1], 0, minHeap[0].row, minHeap[0].column + 1);
		}
		else {
			Insert(minHeap, INT_MAX, 0, 0, 0);			
		}

		Heapify(minHeap, 0, k);
	}
	
	for(i = 0; i < N*k; i++)
                printf("%d ", newArray[i]);
        printf("\n");
}

void main() {
	// Change n at the top to change number of elements in an array
    	int arr[][N] =  {{2, 6, 12, 34},
    	                 {8, 9, 20, 1000},
        	         {23, 34, 90, 2000},
			 {1, 28, 52, 150}};
    	int k = sizeof(arr)/sizeof(arr[0]);
	int i, j;
        for(i = 0; i < k; i++) {
		for(j = 0; j < N; j++)
                	printf("%d ", arr[i][j]);
		printf("\n");
	}

 	MergeKArrays(arr, k);
}
