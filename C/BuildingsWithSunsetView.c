#include<stdio.h>
#include<malloc.h>

#define N 10

typedef struct Stack {
	int height;
	struct Stack* next;
} Stack;

void Push(Stack** stack, int buildingHeight) {
	Stack* building = malloc(sizeof(Stack));
	building->height = buildingHeight;
	building->next = *stack;
	*stack = building;
}

void Pop(Stack** stack) {
	*stack = (*stack)->next;
}

void ExamineSunsetViewOfBuilding(int buildingHeight, Stack** stack) {
	if(!(*stack) || (*stack)->height > buildingHeight) {
		Push(stack, buildingHeight);
		return;
	}
	
	if((*stack)->height < buildingHeight) {
		while((*stack) && (*stack)->height < buildingHeight)
			Pop(stack);
		Push(stack, buildingHeight);
		return;
	}


}

void main() {
	int numberOfBuildings = N;
	int buildingHeight[N];
	while(numberOfBuildings > 0) {
		buildingHeight[numberOfBuildings - 1] = rand() % 10;
		numberOfBuildings--;
	}
	
	printf("Height Of Buildings From East To West\n");
	int count = 0;
	while(count < N) {
		printf("%d| ", buildingHeight[count++]);
	}
	printf("\n");

	Stack* listOfBuildingsWithSunsetView = NULL;

	while(numberOfBuildings < N) {
		ExamineSunsetViewOfBuilding(buildingHeight[numberOfBuildings], &listOfBuildingsWithSunsetView);
		numberOfBuildings++;
	}

	printf("List of Buildings with Sunset View\n");
	while(listOfBuildingsWithSunsetView) {
		printf("%d| ", listOfBuildingsWithSunsetView->height);
		listOfBuildingsWithSunsetView = listOfBuildingsWithSunsetView->next;
	}

	printf("\n");
}
