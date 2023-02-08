#ifndef SCREENPREPARE_H
#define SCREENPREPARE_H

#define WINDOW_WIDTH  120 * 2
#define WINDOW_HEIGHT 30 * 2

const char gradient[] = " .:!/r(l1Z4H9W8$@";
const int  gradientSize = 17;

const float windowAspect = (float)WINDOW_WIDTH / WINDOW_HEIGHT,
			charAspect = 9.0f / 20.0f;

void PrepareWindow(size_t width, size_t height);
void RedrawScreenBuffer(HANDLE hConsole, wchar_t* screenBuffer);
void DestroyScreenBuffer(wchar_t* screenBuffer);
HANDLE GetConsoleHandle();
wchar_t* CreateScreenBuffer();

#endif