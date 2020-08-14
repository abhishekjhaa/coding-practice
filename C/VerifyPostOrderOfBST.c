#include<stdio.h>
#include<stdbool.h>

bool VerifyIfPostOrder(int* array, int start, int length) {
	if(start == length - 1 || start == length)
		return true;
	int rootValue = array[length - 1];
	int i = start;
	while(rootValue > array[i])
		i++;
	int j = i;
	while(j < length - 1) {
		if(array[j] < rootValue)
			return false;
		j++;
	}
	bool result = VerifyIfPostOrder(array, start, i) && VerifyIfPostOrder(array, i, length - 1);
	return result;
}

void main() {
	//int postOrderArray[] = {5,7,6,9,10,11,8}; // Is postOrder
	int postOrderArray[] = {7,4,6,5}; // Is not Post Order
	int length = 7;
	bool result = VerifyIfPostOrder(postOrderArray, 0, length);
	printf("Sequence is PostOrder : %s\n", result ? "True" : "False");
}
