/*
 * CircleBressenham.cpp
 *
 * -------------------------------------
 * Draw Circle with Bressenham's Algorithm
 * -------------------------------------
 *
 * Copyright 2014 Imancha <imancha_266@ymail.com>
 *
 */

#include <iostream>
#include <graphics.h>

using namespace std;

void DrawCircle(int xc, int yc, int x, int y){
	putpixel(xc+x, yc+y, GREEN);
	putpixel(xc-x, yc+y, GREEN);
	putpixel(xc+x, yc-y, GREEN);
	putpixel(xc-x, yc-y, GREEN);
	putpixel(xc+y, yc+x, GREEN);
	putpixel(xc-y, yc+x, GREEN);
	putpixel(xc+y, yc-x, GREEN);
	putpixel(xc-y, yc-x, GREEN);
}

void Circle(int xc, int yc, int r){
	int i = 0;
	int x = 0;
	int y = r;
	int d = 3 - 2 * r;

	cout << "\n i \tP \t(x,y) \n --------------------";

	putpixel(xc, getmaxy()-yc, GREEN);

	while (x < y){
		DrawCircle(xc, getmaxy()-yc, x, y);
		x++;

		cout << "\n " << i++ << "\t" << d << "\t";

		if (d < 0){
			d = d + 4 * x + 6;
		}else{
			y--;
			d = d + 4 * (x - y) + 10;
		}

		cout << "(" << x << "," << y << ")";
		DrawCircle(xc, getmaxy()-yc, x, y);
		delay(20);
	}
	cout << "\n";
}

int main(int argc, char **argv)
{
	int xc, yc, r;

	printf("Koordinat titik tengah X Y : "); scanf("%d %d", &xc, &yc);
	printf("Radius Lingkaran           : "); scanf("%d", &r);

	int gd = DETECT;
	int gm = getmaxmode();

	initgraph(&gd, &gm, NULL);

	Circle(xc, yc, r);

	getchar();
	closegraph();

	return 0;
}
