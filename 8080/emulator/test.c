#include <Windows.h>
#include <stdint.h>
#include <stdio.h>

// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
// {
//     HWND h;
//     h = CreateWindow("BUTTON", "Hit me", WS_OVERLAPPEDWINDOW, 350, 300, 250, 100, 0, 0, hInstance, 0);
//     ShowWindow(h, nCmdShow);

//     MessageBox(0, "Press Me", "Waiting", MB_OK);
// }




int main()
{

    uint8_t a = 41;
    uint8_t b = 42;
    uint8_t c = 32;
    uint8_t d = 0;
    uint8_t e = 138;


    printf("norm: %x   twos: %x\n", a - b, ((uint16_t) a + (uint16_t) ~b + 1) & 0xff);
    printf("norm: %i   twos: %i\n", a - c, a + ~c + 1);
    printf("norm: %i   twos: %i\n", a - d, a + ~d + 1);
    printf("norm: %i   twos: %i\n", a - e, a + ~e + 1);





    return 0;
}