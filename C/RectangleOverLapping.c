#include<stdio.h>
#include<stdbool.h>

struct Rectangle {
	int x;
	int y;
	int lenX;
	int lenY;
};

void MakeRectangle(struct Rectangle* rect, int x, int y, int lenX, int lenY) {
	(*rect).x = x;
        (*rect).y = y;
        (*rect).lenX = lenX;
        (*rect).lenY = lenY;
}

bool CheckIntersect(struct Rectangle R, struct Rectangle S) {

	return R.x < S.x + S.lenX && R.y < S.y + S.lenY &&
		R.x + R.lenX >= S.x && R.y + R.lenY >= S.y;

}

int Min(int a, int b) {
	return a > b ? b : a;
}

int Max(int a, int b) {
	return a > b ? a : b;
}

void main() {
	struct Rectangle R;
	struct Rectangle S;
	MakeRectangle(&R, 3, 3, 5, 4);
        MakeRectangle(&S, 5, 5, 7, 6);

	bool intersect = CheckIntersect(R, S);
	
	if(intersect) {
		struct Rectangle P;
		P.x = Max(R.x, S.x);
		P.y = Max(R.y, S.y);
		P.lenX = Min(R.x + R.lenX, S.x + S.lenX) - P.x;
		P.lenY = Min(R.y + R.lenY, S.y + S.lenY) - P.y;
		
		printf("New Intersected Recatanlge: x = %d y = %d length = %d width = %d\n", P.x, P.y, P.lenX, P.lenY);
	}
	else
		printf("Rectangles don't Intersect\n");
}
