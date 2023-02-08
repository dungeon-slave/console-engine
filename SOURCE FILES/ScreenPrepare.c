#include <windows.h>
#include <stdio.h>

#include "ScreenPrepare.h"

void PrepareWindow(size_t width, size_t height) 
{
	COORD coord;
		coord.X = (SHORT)(width);
		coord.Y = (SHORT)(height);

	SMALL_RECT Rect;
		Rect.Top = 0;
		Rect.Left = 0;
		Rect.Bottom = (SHORT)(height - 1);
		Rect.Right = (SHORT)(width - 1);

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

HANDLE GetConsoleHandle() 
{
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);

	return hConsole;
}

wchar_t* CreateScreenBuffer() 
{
	return malloc(sizeof(wchar_t[WINDOW_WIDTH * WINDOW_HEIGHT]));
}

void DestroyScreenBuffer(wchar_t* buffer) 
{
	free(buffer);
}

void RedrawScreenBuffer(HANDLE hConsole, wchar_t* screenBuffer) 
{
	DWORD dwBytesWritten = 0;
	COORD coord;
		coord.X = 0;
		coord.Y = 0;
	
	screenBuffer[WINDOW_WIDTH * WINDOW_HEIGHT - 1] = '\0';
	WriteConsoleOutputCharacter(hConsole, screenBuffer, WINDOW_WIDTH * WINDOW_HEIGHT, coord, &dwBytesWritten);
}