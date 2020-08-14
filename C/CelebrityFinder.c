/*
For any two distinct people a and b, a may or may not know b. However, the "knows" 
relation is not symmetric, which means that a may know b, but b may not know a. 
The knows relation is anti-reflexive, i.e., a does not know a. At a party, everyone 
knows someone else. Now a celebrity joins the party—everyone knows him, but he knows no one. 

Let F be an n x n Boolean 2D array representing the "knows" relation for n people; 
F[a][b] is true if a knows b, and F[a][a] is always false. Design an O(n) algorithm to find the celebrity. 
*/

#include<stdio.h>

#define N 4

int FindCeleb(int F[N][N]) {
/*
If F[i][j] is false, we move to F[i][j+1] as j not a celebrity candidate anymore but i still is.

If F[i][j] is true, we know that i is not the celebrity, 
and for all j' < j, j' is not a celebrity because F[i][j'] must be false, 
allowing us to advance from F[i][j] to F[j][j + 1] since i < j.
We eliminate one candidate each step in 0(1) time which gives us a O(n) time algorithm.
*/
	int i = 0, j = 1;
	while(j < N) {
		if(F[i][j] == 1)
			i = j++; // all candidates j' < j are not celebrity candidates
		else
			j++; // i is still a celebrity candidate but j is not.
	}

	return i;
}

void main() {
	int F[N][N] = {	{0,1,1,0},
			{0,0,1,1},
			{0,0,0,0},
			{1,0,1,0}};
	
	int celeb = FindCeleb(F);
	printf("Celeb is %dth guy\n", celeb+1);
}
