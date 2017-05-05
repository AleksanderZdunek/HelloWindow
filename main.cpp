//Basic window
#include <Windows.h>
#include "Window.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	Window::Init();
	Window::Run();
	return 0;
}