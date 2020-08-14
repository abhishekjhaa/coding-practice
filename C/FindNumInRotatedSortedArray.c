/*Given a sorted array of n integers that has been rotated an unknown number of 
times, write code to find an element in the array. You may assume that the array was 
originally sorted in increasing order. */

#include<stdio.h>

int FindMinimum(int array[], int start, int end, int num) {
	if(end - start < 0)
		return -1;
	int middle = start + (end - start)/2;
	if(array[middle] == num)
		return middle;
	if(array[start] < array[middle]) { // It means left half is sorted
		if(array[start] <= num && num < array[middle]) // Search in left half
			return FindMinimum(array, start, middle - 1, num);
		else
			return FindMinimum(array, middle + 1, end, num); //Search in right half
	}
	else if(array[middle] < array[end]) { // It means right half is sorted
                if(array[end] >= num && num > array[middle]) // Search in right half
                        return FindMinimum(array, middle + 1, end, num);
                else
                        return FindMinimum(array, start, middle - 1, num); //Search in left half
        }
	else if(array[start] == array[middle]) { //Left half has all repeated numbers
		if(array[middle] != array[end]) // If right is different
			return FindMinimum(array, middle + 1, end, num); // Search in right half
	}
	else { // We have to search both halves
		int result = FindMinimum(array, start, middle - 1, num); // Find in left half
		if(result == -1) // if its not in left half
			result = FindMinimum(array, middle + 1, end, num); // search right half
		return result;
	}

	return -1;
}


void main() {
	int array[] = {10, 15 , 20, 0, 5};
	int end = 4, start = 0;
	int num = 5;
	int result = FindMinimum(array, start, end, num);
	if(result != -1)
		printf("Num %d is found\n", num);
	else
		printf("Num %d is not found\n", num);
}
