#include <windows.h>
#include <iostream>
#include <math.h>
#define UNICODE
using namespace std;

int screenWidth = 120;
int screenHeight = 30;

int main(){
    system("color 0a");
    wchar_t *screen = new wchar_t[screenWidth*screenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten;
    screen[screenWidth*screenHeight - 1] = '\0';
    int i = 0;
    while (1)
    {
        screen[i] = 97 + rand()%26;
        
        Beep(5000,50);
        i++;
        WriteConsoleOutputCharacterW(hConsole, screen, screenWidth * screenHeight, {0,0}, &dwBytesWritten);
    }
    
    return 0;
}