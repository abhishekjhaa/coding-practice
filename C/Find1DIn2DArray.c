#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

#define LEN 3
#define WID 3
#define SIZE 4

typedef struct List {
	int data;
	int row;
	int column;
	struct List* next;
} List;

void AddDataToList(List** list, int i, int j, int data) {
	List* node = malloc(sizeof(List));
	node->row = i;
	node->column = j;
	node->data = data;
	node->next = NULL;
	
	*list = node;
}

bool MatchPattern(int twoDArray[LEN][WID], int i, int j, int* array, int k, List** list) {
        if((i < 0 || i >= LEN || j < 0 || j >= WID) && k < SIZE)
                return false;
        if((i >= 0 && i <= LEN && j >= 0 && j <= WID) && k == SIZE)
                return true;
        if(twoDArray[i + 1][j] == array[k]) {
		AddDataToList(list, i + 1, j, array[k]);
                return MatchPattern(twoDArray, i + 1, j, array, k + 1, &(*list)->next);
	}
        if(twoDArray[i - 1][j] == array[k]) {
                AddDataToList(list, i - 1, j, array[k]);
                return MatchPattern(twoDArray, i - 1, j, array, k + 1, &(*list)->next);
	}
        if(twoDArray[i][j + 1] == array[k]) {
                AddDataToList(list, i, j + 1, array[k]);
                return MatchPattern(twoDArray, i, j + 1, array, k + 1, &(*list)->next);
	}
        if(twoDArray[i][j - 1] == array[k]) {
                AddDataToList(list, i, j - 1, array[k]);
                return MatchPattern(twoDArray, i, j - 1, array, k + 1, &(*list)->next);
	}

	return false;
}

void main() {
        int twoDArray[LEN][WID] = {     {1, 2, 3},
                                        {3, 4, 5},
                                        {5, 6, 7}       };
        int array[SIZE] = {1, 3, 4, 6};
        int i, j, k = 0;
	List* list = malloc(sizeof(List));
        for(i = 0; i < LEN; i++)
                for(j = 0; j < WID; j++) {
                        if(twoDArray[i][j] == array[k] && MatchPattern(twoDArray, i, j, array, k + 1, &(list->next))) {
                                printf("Found patter in 2D Array for row = %d & column = %d\n", i, j);
				list->data = array[k];
				list->row = i;
				list->column = j;
				while(list) {
					printf("%d at (%d, %d)",list->data, list->row, list->column);
					list = list->next;
					printf("\n");
				}
                                return;
			}
			else
				list->next = NULL;
		}
}
