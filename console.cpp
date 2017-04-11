#include"console.h"



void gotoxy(int x, int y)
    {
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
    }

void BGcolor(WORD color){
	 CONSOLE_SCREEN_BUFFER_INFO thongtinbuffermanhinh;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &thongtinbuffermanhinh);
    WORD k = thongtinbuffermanhinh.wAttributes;
    color &= 0x000f;
    color <<= 4;
    k &= 0xff0f;
    k |= color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void Objectcolor(WORD color)
	{
		color--;
	 CONSOLE_SCREEN_BUFFER_INFO thongtinbuffermanhinh;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &thongtinbuffermanhinh);

    WORD k = thongtinbuffermanhinh.wAttributes;
    color &= 0x000f;
    k &= 0xfff0;
    k |= color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
}
