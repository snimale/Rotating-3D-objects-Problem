#include <windows.h>
#include<stdio.h>
#include<conio.h>
COORD c = {0, 0};

void setxy (int x, int y)
{
 c.X = x; c.Y = y; // Set X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
 int x, y, rollno;
 char name[10];

 printf("Enter your Roll No.:");
 scanf("%d", &rollno);

 printf("Enter your name:");
 scanf("%s", name);

 printf("Where you want to print on Screen?\n");
 printf("Enter your X coordinate:");
 scanf("%d", &x);

 printf("Enter your Y coordinate:");
 scanf("%d", &y);

 setxy(x,y);
 printf("Your Roll No. is %d.", rollno);

 setxy(x,y+1); //add 1 in y to print at new line
 printf("Your Name is %s.", name);

 return 0;
}