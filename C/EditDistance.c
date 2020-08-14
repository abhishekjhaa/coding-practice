#include<stdio.h>
#include<malloc.h>
#include<string.h>

int Minimum(int i, int j, int k) {
	return i > j ? (j > k ? k : j) : (i > k ? k : i);
}

int GetDistance(char* str1, int len1, char* str2, int len2) {
	if(len2 == 0)
		return len1;	
	else if(len1 == 0)
		return len2;
	else if(str1[len1 -  1] == str2[len2 - 1])
		return GetDistance(str1, len1 - 1, str2, len2 - 1);
	else
		return Minimum(GetDistance(str1, len1 - 1, str2, len2), GetDistance(str1, len1, str2, len2 - 1), GetDistance(str1, len1 - 1, str2, len2 - 1)) + 1;
}

void main() {
	char* str1 = "Sunday";
	char* str2 = "Saturday";
	int count = 0;
        while(str1[count])
                count++;
        int len1 = count;
        count = 0;
        while(str2[count])
                count++;
        int len2 = count;
	int result = GetDistance(str1, len1, str2, len2);
	printf("Edit Distance between %s and %s is %d \n", str1, str2, result);
}
