#include<stdio.h>
int ScanWindow(int array[], int i, int j) {
	int max = 0; 
	while(i <= j) {
                if(array[i] > max)
                        max = array[i];
                i++;
        }
	
	return max;
}

void main() {
	int array[] = {2,3,4,2,6,2,5,1};
	int length = 8;
	int slidingWindow = 3;
	int i = 0;
	int max = 0;
	while(i < slidingWindow) {
		if(array[i] > max)
			max = array[i];
		i++;
	}

	int newArray[length - 2];
	newArray[0] = max;
	int j = 1;
	while(i < length) {
		int prevNum = array[i - 3];
		int nextNum = array[i];
		if(prevNum == max && nextNum < max) {
			max = array[i - 2] > array[i - 1] ? array[i -2] : array[i - 1];
			newArray[j++] = max;
		}
		else if(nextNum > max) {
			max = nextNum;
                        newArray[j++] = max;
		}
		else 
			newArray[j++] = max;
		i++;
	}
	i = 0;
	while(i < j)
		printf("%d| ", newArray[i++]);
	printf("\n");
}
