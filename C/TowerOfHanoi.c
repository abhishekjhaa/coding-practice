/*
Case n = 2. 
Can we move Disk 1 and Disk 2 from Tower 1 to Tower 3? Yes. 
1. Move Disk 1 from Tower 1 to Tower 2 
2. Move Disk 2 from Tower 1 to Tower 3 
3. Move Disk 1 from Tower 2 to Tower 3 
Note how in the above steps, Tower 2 acts as a buffer, holding a disk while we move other disks to Tower 3. 
Case n = 3. 
Can we move Disk 1, 2, and 3 from Tower 1 to Tower 3? Yes. 
1. We know we can move the top two disks from one tower to another (as shown earlier), so let's assume we've already done that. But instead, let's move them to Tower 2. 
2. Move Disk 3 to Tower 3. 
3. Move Disk 1 and Disk 2 to Tower 3. We already know how to do this—we just repeat what we did in Step 1. 
*/

#include<stdio.h>
#include<malloc.h>

#define N 3

typedef struct Stack {
	int diskSize;
	int stackNum;
	struct Stack* next;
} Stack;

void PutOnDisks(Stack** stack) {
	int n = N;
	while(n > 0) {
		Stack* disk = malloc(sizeof(Stack));
		disk->diskSize = n--;
		disk->stackNum = 1;
		disk->next = *stack;
		*stack = disk;
	}
}

void AddAndThenRemoveDisk(Stack* array[3], int destination, int origin) {
	Stack* node = array[origin];
	printf("Moved disk%d from Stack%d to Stack%d\n", node->diskSize, origin + 1, destination + 1);
	array[origin] = (array[origin])->next;
	node->stackNum = destination;
	node->next = array[destination];
	array[destination] = node;
}

void TransferDisks(int numberOfDisks, Stack* array[3], int origin, int destination, int buffer) {
	if(numberOfDisks > 0) {
		/* move top (n - 1) disks from origin to buffer, using destination as a buffer. */ 
		TransferDisks(numberOfDisks - 1, array, origin, buffer, destination);
		/* move top from origin to destination*/
		AddAndThenRemoveDisk(array, destination, origin);
		/* move top (n - 1) disks from buffer to destination, using origin as a buffer.*/
		TransferDisks(numberOfDisks - 1, array, buffer, destination, origin);
	}
}

void main() {
	Stack* origin;
	PutOnDisks(&origin);
	Stack* destination;
	Stack* buffer;
	Stack* array[] = { origin, destination, buffer };
	TransferDisks(N, array, 0, 1, 2);
}
