#include<stdio.h>

//One Character appears more than sum of others 
void main() {
	char* stream = "aebecedeefgeheeeiej";
	int count = 0;
	char candidate;
	while(*stream != '\0') {
		if(count == 0) {
			candidate = *stream;
			count++;			
		}
		else if(*stream == candidate)
			count++;
		else
			count--;

		stream++;	
	}

	printf("Character that appears more than the sum of appreances of other characters is : '%c'\n", candidate);
}
