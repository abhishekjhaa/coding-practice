//A & B are playing a game where probability of A winning a round is 0.6
//They decide to play till a player win 11 rounds. Prize Money was 100
//But it got interrupted and players had to leave. A was leading B by 7 to 5.
//Divide the prize money fairly between A & B.
//Define pk(x, y) to be the probability that player A is the first to k wins, given a current score of x to y.
//pk(x, y) = 0.6*pk(x + 1, y) + 0.4*pk(x, y + 1), pk(k, y) = 1, pk(x, k) = 0 for all x, y < k.

#define NoOfGames 11
#define PrizeMoney 100

#include<stdio.h>

double Helper(int gamesWonByA, int gamesWonByB, double AWon) {
	if(gamesWonByA == NoOfGames)
		return 1;
	if(gamesWonByB == NoOfGames)
		return 0;
	return AWon*Helper(gamesWonByA + 1, gamesWonByB, AWon) + (1 - AWon)*Helper(gamesWonByA, gamesWonByB + 1, AWon);
}

void main() {
	int gamesWonByA = 7;
	int gamesWonByB = 5;
	int noOfGames = 11;
	double AWon = 0.6;
	
	double probabilityOfAWinning = AWon*Helper(gamesWonByA + 1, gamesWonByB, AWon) + (1 - AWon)*Helper(gamesWonByA, gamesWonByB + 1, AWon);

	printf("PrizeMoney A got = %f after winning %d out of %d with Probabilty %f\n", PrizeMoney*probabilityOfAWinning, gamesWonByA, NoOfGames, AWon);
}
