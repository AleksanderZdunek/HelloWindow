#include <Windows.h>

namespace Window
{

HWND hWindow(nullptr);

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;

	switch (message)
	{
	case WM_SIZE:
	{
		UINT width = LOWORD(lParam);
		UINT height = HIWORD(lParam);
		//OnResize(width, height);
	}
	result = 0;
	break;

	case WM_DISPLAYCHANGE:
		InvalidateRect(hWnd, nullptr, false);
		result = 0;
		break;

	case WM_PAINT:
		//OnRender();
		ValidateRect(hWnd, nullptr);
		result = 0;
		break;

	case WM_LBUTTONDOWN:
		//OnClick(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		result = 1;
		break;

	case WM_CHAR:
		//CharInput(static_cast<wchar_t>(wParam));
		result = 0;
		break;

	case WM_COMMAND:
	default:
		result = DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return result;
}

void Init()
{
	const UINT width(CW_USEDEFAULT);
	const UINT height(CW_USEDEFAULT);

	const wchar_t* title = L"Hello Window";

	//Register the window class.
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(0);
	wcex.hIcon = nullptr;
	wcex.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	wcex.hbrBackground = nullptr;
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"arbitraryclassname";
	wcex.hIconSm = nullptr;

	RegisterClassEx(&wcex);

	hWindow = CreateWindowEx(WS_EX_ACCEPTFILES, wcex.lpszClassName, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, nullptr, nullptr, GetModuleHandle(0), nullptr);

	ShowWindow(hWindow, SW_SHOWNORMAL);
	UpdateWindow(hWindow);
}

void Run()
{
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

}