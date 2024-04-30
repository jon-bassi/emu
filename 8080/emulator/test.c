#include <Windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    HWND h;
    h = CreateWindow("BUTTON", "Hit me", WS_OVERLAPPEDWINDOW, 350, 300, 250, 100, 0, 0, hInstance, 0);
    ShowWindow(h, nCmdShow);

    MessageBox(0, "Press Me", "Waiting", MB_OK);
}