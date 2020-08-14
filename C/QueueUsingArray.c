#include<stdio.h>
#include<malloc.h>

#define N 5
static int count = 0;
static int head = 0;
static int tail = 0;
static int size = N;

void ResizeArray(int* array) {
	size *= 2;
	array = realloc(array, 2*(sizeof(array)));
}

void Enqueue(int* array, int data) {
	if(count == size) {
		printf("Resizing needs to be done since size %d exceeded the limit\n", size);
		ResizeArray(array);
		tail = count;
	}
	printf("Enqueued %d at Tail %d\n", data, tail);
	array[tail] = data;
	tail = (tail+1) % size;
	count++;
}

void Dequeue(int array[size]) {
	if(count) {
		printf("Dequeued %d at Head %d\n", array[head], head);
		head = (head+1) % size;
		count--;
	}
	else {
		printf("No items to Dequeue\n");
	}
}

void main() {
	int* array = malloc(N*sizeof(int));
	int i;
	for(i = 0; i < 2*N; i++) {
		Enqueue(array, rand() % (20+i));
	}
	printf("Size of Q is %d\n", size);
	for(i = 0; i < N+1; i++) {
		Dequeue(array);
	}

	Enqueue(array, rand() % 20);
	Dequeue(array);
	Enqueue(array, rand() % 20);
	Dequeue(array);
}
