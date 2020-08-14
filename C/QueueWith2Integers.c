#include<stdio.h>
#include<math.h>

// Compile with -lm at the end to include math library i.e., cc QueueWith2Integers.c -lm
void Enqueue(unsigned int* q, int data, int* size) {
	printf("%d| ", data);
	*q = (*q)*10 + data;
	(*size)++;
}

void Dequeue(unsigned int* q, int* size) {
	if(*size) {
		if(*q == 0)
			printf("Dequeued 0\n");
		else {
			unsigned int d = floor(log10(*q));
			if(d + 1 == *size) {
				int ret = (*q)/pow(10.0, d);
				*q -= pow(10.0, d)*ret; 
				printf("Dequeued %d & remaining Queue is %d\n", ret, *q);
			}	
		}

		(*size)--;			
	}
	else {
		printf("Empty Queue\n");
	}
}

void main() {
	unsigned int q = 0;
	unsigned int qCount = 0;
	while(qCount < 9) {
		Enqueue(&q, 0, &qCount);
	}
	printf("\n");
	printf("Queued Items %d\n", q);
	while(qCount > 0)
		Dequeue(&q, &qCount);
	
	q = 0, qCount = 0;
	while(qCount < 9)
                Enqueue(&q, rand() % 10, &qCount);
        printf("\n");
        printf("Queued Items %d\n", q);
        while(qCount > 0)
                Dequeue(&q, &qCount);
}
