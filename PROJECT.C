#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define cx 200
#define cy 800
#define screensize 24
typedef struct coordinate {
	int x;
	int y;
	int z;

} coordinate;

const float pi = 3.14;
const int radius = 20;

void donutGenerator(coordinate donut[][36],coordinate circle[]);
void circleGenerator(coordinate circle[], coordinate center);
void putShapeInScreen(coordinate shape[][36], char screen[screensize][screensize], int size);
void setxy(short x, short y);
void getScreen(char screen[screensize][screensize]);
void printScreen(char screen[screensize][screensize]);

int main() {
	int gdriver = DETECT, gmode;
	coordinate circle[36];
	coordinate donut[36][36];
	coordinate center = {18, 12, 0};
	char screen[screensize][screensize];
	getScreen(screen);
	system("cls");
	initgraph(&gdriver, &gmode, "c:\\turbo3\\bgi");
	outtextxy(cx, cy, ".");
	//circleGenerator(circle, center);
	//donutGenerator(donut, circle);
	//putShapeInScreen(donut, screen, 360/10);
	//printScreen(screen);
	getch();
	closegraph();
	return 0;
}
void donutGenerator(coordinate donut[][360/10],coordinate circle[]) {
	int i, j;
	float angle = 0;
	for(i=0; i<36; i++) {
		for(j=0; j<36; j++) {
			donut[i][j].y = circle[j].y;
			donut[i][j].x = (int) (circle[j].x * cos(angle*2*pi/360) + 0.5);
			donut[i][j].z = (int) (circle[j].z * sin(angle*2*pi/360) + 0.5);
			angle+=10;
		}
		angle=0;
	}

}

void circleGenerator(coordinate circle[], coordinate center) {
	int i;
	for(i=0; i<36; i++) {
		circle[i].x = (int)((center.x + radius*cos(pi*(i*10)/360)) + 0.5);
		circle[i].y = (int)((center.y + radius*sin(pi*(i*10)/360)) + 0.5);
		circle[i].z = 0;
		//printf("(%d, %d)\n", circle[i].x, circle[i].y);
	}
}
void putShapeInScreen(coordinate shape[][360/10], char screen[screensize][screensize], int size) {
	int i, j;
	for(i=0; i<36; i++) {
		for(j=0; j<36; j++) {
			screen[shape[i][j].y][shape[i][j].x]='.';
		}
	}

}

void getScreen(char screen[screensize][screensize]) {
	int i, j;
	for(i=0; i<screensize; i++) {
		for(j=0; j<screensize; j++) {
			screen[i][j]=' ';
		}
	}
}

void printScreen(char screen[screensize][screensize]) {
	int i, j;
	for(i=0; i<screensize; i++) {
		for(j=0; j<screensize; j++) {
			//aouttextxy();
		}
		printf("\n");
	}
}

