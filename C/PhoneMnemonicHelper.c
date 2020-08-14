#include<stdio.h>
#include<malloc.h>

static char* dict[10] = { "0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

void GetAllPossibleNames(char* num, int len, int index, char* ans) {
	if(index == len)
		printf("%s\n", ans);
	else {
		int i = 0;
		char* temp = dict[(num[index] - '0')];
		while(temp[i] != '\0') {
			ans[index] = temp[i++];
			GetAllPossibleNames(num, len, index + 1, ans);
		}
	}
}

void main() {
	char* numberSeq = "951";
	int length = 3, index = 0;
	char* ans = malloc(sizeof(numberSeq));
	printf("%s\n", numberSeq);
	GetAllPossibleNames(numberSeq, length, index, ans);	
}
