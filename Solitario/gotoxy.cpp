#include "gotoxy.h"
void gotoXY(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}