#include<stdio.h>
#include<malloc.h>

#define SIZE 20

// Problem No 14.20 of Elements of Programming interview[300 Programming InterViewQuestions].

typedef struct Line {
	int leftEndPoint;
	int rightEndPoint;
	char* color;
	int height;
} Line;

typedef struct Array {
	struct Line* left;
	struct Line* right;
} Array;

void Insert(Array array[SIZE], int leftEndPoint, int rightEndPoint, char* color, int height) {
	Line* line = malloc(sizeof(Line));
	line->leftEndPoint = leftEndPoint;
	line->rightEndPoint = rightEndPoint;
	line->color = color;
	line->height = height;
	
	int count = leftEndPoint;
	while(count <= rightEndPoint) {
		if(count > leftEndPoint && (array[count].left == NULL || array[count].left->height < height))              
                        array[count].left = line;

		if(count < rightEndPoint && (array[count].right == NULL || array[count].right->height < height)) 
                	array[count].right = line;
		count++;
	}

}

void InsertLines(Array array[SIZE]) {
	Insert(array, 0, 4, "Red", 1);
        Insert(array, 5, 7, "Blue", 1);
	Insert(array, 9, 18, "Black", 1);
        Insert(array, 2, 7, "Navy", 2);
        Insert(array, 8, 9, "Yellow", 2);
        Insert(array, 12, 15, "Orange", 2);
        Insert(array, 1, 3, "Ferozi", 3);
        Insert(array, 6, 10, "Violet", 3);
        Insert(array, 11, 13, "Brown", 3);
        Insert(array, 14, 15, "Indigo", 3);
        Insert(array, 16, 17, "Green", 3);
        Insert(array, 4, 5, "Sharbati", 4);	
}

void Print(Array line, int leftEndPoint, int rightEndPoint) {
	printf("(%d, ", leftEndPoint);
	printf("%d, ", rightEndPoint);
        printf("%s, ", line.right->color);
        printf("%d)\n", line.right->height);
}

void ViewLinesFromTop(Array array[SIZE]) {
	int count = 0;
	while(!(array[count].right))
		count++;
	int leftEndPoint = count;
	int rightEndPoint = count;
	while(count < SIZE) {
		while(count + 1 < SIZE && array[count].right && array[count + 1].right && array[count].right == array[count+1].right)
			count++;
		rightEndPoint = ++count;
		if(array[leftEndPoint].right)
			Print(array[leftEndPoint], leftEndPoint, rightEndPoint);
		leftEndPoint = count;
	}
}

void main() {
	Array array[20];
	int count = 0;
	while(count < SIZE) {
		array[count].left = NULL;
		array[count++].right = NULL;
	}

	InsertLines(array);
	ViewLinesFromTop(array);
}
