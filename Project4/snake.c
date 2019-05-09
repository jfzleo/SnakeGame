//贪吃蛇

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include "graphics.h"
#include "genlib.h"
#include "conio.h"
#include "imgui.h"
#include "random.h"
#include <conio.h>

#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <time.h>

#include "snake.h"

void TimerEventProcess(int timerID);
int time1 = 0;
struct pos				//建立链表储存每个关节的位置
{
	int x;
	int y;
	struct pos*next;
};
unsigned int struct_size;
struct_size = sizeof(struct pos);	
int n = 0;				//记录节点个数

void Main()
{	
	InitConsole();
	printf("按任意键开始");
	_getch();
	InitGraphics();								//初始化图形界面
	SetWindowTitle("SNAKE");
	InitGUI();									//初始化GUI
	Randomize();								//初始化随机数
	struct pos*head = (struct pos *)malloc(struct_size);    //建立头指针
	double x, y;                            //记录位置  
	int f;                                         //记录方向
	registerTimerEvent(TimerEventProcess);
	startTimer(1, 1000);
	InitGameBox();
	MovePen(5, 3);
	StartFilledRegion(0.5);
	DrawArc(0.25, 0, 360);
	EndFilledRegion();
	
}

void InitGameBox()
{
	double windowWidth, windowHeight;   //记录窗口大小
	windowWidth = GetWindowWidth();
	windowHeight = GetWindowHeight();    //获取窗口大小
	MovePen(windowWidth / 2 - 2.5, 0);   
	DrawLine(boxWidth, 0);
	DrawLine(0, boxHeight);
	DrawLine(-boxWidth, 0);
	DrawLine(0, -boxHeight);                   //绘制游戏窗口
	gameBox_x1 = windowWidth / 2 - 2.5;
	gameBox_x2 = windowWidth / 2 + 2.5;
	gameBox_y1 = 0;
	gameBox_y2 = 5;                     //初始化游戏边缘坐标
	
}
void TimerEventProcess(int timerID)
{
	switch (timerID)
	{
	case 1:time1++;
		if (time1 == 5)
		{
			MovePen(5.006, 3);
			SetEraseMode(TRUE);
			StartFilledRegion(0);
			DrawArc(0.256, 0, 360);
			EndFilledRegion();
			SetEraseMode(FALSE);
		}
	}
}

//#define HouseHeight         2.0
//#define HouseWidth          3.0
//#define AtticHeight         0.7
//
//#define DoorWidth           0.4
//#define DoorHeight          0.7
//#define DoorknobRadius      0.03
//#define DoorknobInset       0.07
//
//#define PaneHeight          0.25
//#define PaneWidth           0.2
//
//#define FirstFloorWindows   0.3
//#define SecondFloorWindows  1.25
//
///* Function prototypes */
//
//void DrawHouse(double x, double y);
//void DrawOutline(double x, double y);
//void DrawWindows(double x, double y);
//void DrawDoor(double x, double y);
//void DrawBox(double x, double y, double width, double height);
//void DrawTriangle(double x, double y, double base, double height);
//void DrawCenteredCircle(double x, double y, double r);
//void DrawGrid(double x, double y, double width, double height,
//              int columns, int rows);
//
///* Main program */
//
//void Main()
//{
//    double cx, cy;
//
//    InitGraphics();
//    cx = GetWindowWidth() / 2;
//    cy = GetWindowHeight() / 2;
//    DrawHouse(cx - HouseWidth / 2,
//              cy - (HouseHeight + AtticHeight) / 2);
//}
//
///*
// * Function: DrawHouse
// * Usage: DrawHouse(x, y);
// * -----------------------
// * This function draws a house diagram with the lower left corner
// * at (x, y).  This level of the function merely divides up
// * the work.
// */
//
//void DrawHouse(double x, double y)
//{
//    DrawOutline(x, y);
//    DrawDoor(x + (HouseWidth - DoorWidth) / 2, y);
//    DrawWindows(x, y);
//}
//
///*
// * Function: DrawOutline
// * Usage: DrawOutline(x, y);
// * -------------------------
// * This function draws the outline for the house, using (x, y)
// * as the origin.  The outline consists of a box with a triangle
// * on top.
// */
//
//void DrawOutline(double x, double y)
//{
//    DrawBox(x, y, HouseWidth, HouseHeight);
//    DrawTriangle(x, y + HouseHeight, HouseWidth, AtticHeight);
//}
//
///*
// * Function: DrawDoor
// * Usage: DrawDoor(x, y);
// * ----------------------
// * This function draws a door, with its doorknob.  As usual,
// * (x, y) specifies the lower left corner of the door.
// */
//
//void DrawDoor(double x, double y)
//{
//    DrawBox(x, y, DoorWidth, DoorHeight);
//    DrawCenteredCircle(x + DoorWidth - DoorknobInset,
//                       y + DoorHeight / 2, DoorknobRadius);
//}
//
///*
// * Function: DrawWindows
// * Usage: DrawWindows(x, y);
// * -------------------------
// * This function draws all the windows for the house,
// * taking advantage of the fact that the windows are all
// * arranged in two-dimensional grids of equal-sized panes.
// * By calling the function DrawGrid, this implementation
// * can create all of the window structures using a single
// * tool.
// */
//
//void DrawWindows(double x, double y)
//{
//    double xleft, xright;
//
//    xleft = x + HouseWidth * 0.25;
//    xright = x + HouseWidth * 0.75;
//    DrawGrid(xleft - PaneWidth * 1.5, y + FirstFloorWindows,
//             PaneWidth, PaneHeight, 3, 2);
//    DrawGrid(xright - PaneWidth * 1.5, y + FirstFloorWindows,
//             PaneWidth, PaneHeight, 3, 2);
//    DrawGrid(xleft - PaneWidth, y + SecondFloorWindows,
//             PaneWidth, PaneHeight, 2, 2);
//    DrawGrid(xright - PaneWidth, y + SecondFloorWindows,
//             PaneWidth, PaneHeight, 2, 2);
//}
//
///*
// * Function: DrawBox
// * Usage: DrawBox(x, y, width, height)
// * -----------------------------------
// * This function draws a rectangle of the given width and
// * height with its lower left corner at (x, y).
// */
//
//void DrawBox(double x, double y, double width, double height)
//{
//    MovePen(x, y);
//    DrawLine(0, height);
//    DrawLine(width, 0);
//    DrawLine(0, -height);
//    DrawLine(-width, 0);
//}
//
///*
// * Function: DrawTriangle
// * Usage: DrawTriangle(x, y, base, height)
// * ---------------------------------------
// * This function draws an isosceles triangle (i.e., one with
// * two equal sides) with a horizontal base.  The coordinate of
// * the left endpoint of the base is (x, y), and the triangle
// * has the indicated base length and height.  If height is
// * positive, the triangle points upward.  If height is negative,
// * the triangle points downward.
// */
//
//void DrawTriangle(double x, double y, double base, double height)
//{
//    MovePen(x, y);
//    DrawLine(base, 0);
//    DrawLine(-base / 2, height);
//    DrawLine(-base / 2, -height);
//}
//
///*
// * Function: DrawCenteredCircle
// * Usage: DrawCenteredCircle(x, y, r);
// * -----------------------------------
// * This function draws a circle of radius r with its
// * center at (x, y).
// */
//
//void DrawCenteredCircle(double x, double y, double r)
//{
//    MovePen(x + r, y);
//    DrawArc(r, 0, 360);
//}
//
///*
// * Function: DrawGrid
// * Usage: DrawGrid(x, y, width, height, columns, rows);
// * ----------------------------------------------------
// * DrawGrid draws rectangles arranged in a two-dimensional
// * grid.  As always, (x, y) specifies the lower left corner
// * of the figure.
// */
//
//void DrawGrid(double x, double y, double width, double height,
//              int columns, int rows)
//{
//    int i, j;
//
//    for (i = 0; i < columns; i++) {
//        for (j = 0; j < rows; j++) {
//            DrawBox(x + i * width, y + j * height,
//                    width, height);
//        }
//    }
//}
