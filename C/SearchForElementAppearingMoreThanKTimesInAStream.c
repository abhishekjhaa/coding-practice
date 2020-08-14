#include<stdio.h>

//Print all the characters which appear more than n/k times in the stream. You can read stream only twice. 
void main() {
	char* stream = "aebeicedaaefgbheiebj";
	int count = 0, size = 256;
	int k = 6;

	int hashMap[size];
	while(count < size)
		hashMap[count++] = 0;
	
	count = 0;
	while(stream[count] != '\0')
		hashMap[stream[count++]] += 1;	
	int lengthOfStream = count;
	printf("Characters that appear more than %d times are : ", lengthOfStream/k);
	count = 0;
	while(stream[count] != '\0') {
                if(hashMap[stream[count]] >= lengthOfStream/k) {
			printf("%c, ", stream[count]);
			hashMap[stream[count]] = 0;
		}
		count++;
	}
	
	printf("\n");
}
