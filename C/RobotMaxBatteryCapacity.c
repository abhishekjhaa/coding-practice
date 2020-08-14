#include<stdio.h>
#include<limits.h>

void main() {
	int zAxis[] = {1,2,5,3,8,5,1,9,5};
	int length = 9;

	int height;
	int capacity = 0;
	int i, maxCapacity = INT_MIN;
	for(i = 0; i < length - 1; i++) {
		height = zAxis[i+1] - zAxis[i];
/*
		if(height < 0)
			// battery gets recharged
			capacity = capacity - height;
		else {
			if(capacity < height)
				capacity = capacity + height;
			else
				capacity = capacity - height;
		}

*/		if(capacity >= height)
			capacity -= height; // battery either gets recharged or gets spent.
		else
			capacity += height;
		
		if(maxCapacity < capacity)
			maxCapacity = capacity;
	}

	printf("Maximum Battery Capacity Needed for robot to move up & down is: %d\n", maxCapacity);
}
