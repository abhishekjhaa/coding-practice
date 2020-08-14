#include<stdio.h>

int FindTurningNumber(int array[]) {
	int count = 0;
	while(array[count])
		count++;
	int end = count - 2;
	int start = 0;
	int middle = (start + end) / 2;
	while(start < end - 1) {
		if(array[middle - 1] < array[middle] && array[middle] < array[middle + 1]) {
			start = middle;
			middle = (start + end) / 2;
		}
		
		if(array[middle - 1] > array[middle] && array[middle] > array[middle + 1]) {
                        end = middle;
                        middle = (start + end) / 2;
                }
		
		if(array[middle] > array[middle -1] && array[middle] > array[middle + 1])
			return middle;
	}

	return -1;
}

void main() {
	int array[] = {1,2,3,4,5,10,9,8,7,6};
	int index = FindTurningNumber(array);
	if(index != -1)
		printf("Turning Number is %d at index %d \n", array[index], index);
	else
		printf("No Turning No Found \n");
}
