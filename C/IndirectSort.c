#include<stdio.h>
#include<string.h>
#define SIZE 5

void Sort(char** textFile[SIZE]) {
	int i, j;
	// time complexity n^2.
	for(i = 0; i < SIZE; i++)
		for(j = i; j < SIZE; j++)
			if(strlen(*textFile[i]) > strlen(*textFile[j])) {
				char** temp = textFile[i];
				textFile[i] = textFile[j];
				textFile[j] = temp;
			}

	// We can do better by implementing a nlogn sort algo if there are thousands of lines in the file.
}

// Created a wrapper cause if in future we need to implement better sorting we can do it.
void IndirectSort(char** textFile[SIZE]) {
	Sort(textFile);
}

// Sort based on length of lines in the text file, in increasing order.
// Instead of copying whole line from one address to another we should swap the address of each line.
void main() {
	char* textFileStream[SIZE] = {"Hello", "My Name is", "Abhishek", "How are you doing?", "Good"};
	int count = 0;
	char** textFile[SIZE];
	while(count < SIZE) {
		textFile[count] = &textFileStream[count];
		count++;
	}
	
	// create an array and store the addresses of lines of textfile.
	count = 0;
        while(count < SIZE) {
                printf("%p - %s\n", &textFileStream[count], textFileStream[count]);
		count++;
	}
	printf("-------------------------------------------------------\n");

	
	IndirectSort(textFile);

	count = 0;
	while(count < SIZE) {
                printf("%p - %s\n", textFile[count], *textFile[count]);
                count++;
        }
	printf("------------------------------------------------------\nPlaying With Address assignments\n");
	char* temp = "Huh !";
	char** temp1 = &temp;
	char* temp2 = temp;
	printf("Temp  : %p - %s\nTemp1 : %p - %s Same Address as Temp\nTemp2 : %p - %s New Address assigned\n", &temp, temp, temp1, *temp1, &temp2, temp2);

}
