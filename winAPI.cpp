#include "stdafx.h"
#include "playground.h"

// �޸� ���� ������
#ifdef _DEBUG 
#include <crtdbg.h>
#endif

HINSTANCE	_hInst;
HWND		_hWnd;
POINT		_mouse, _currOrg, _newOrg;
RECT		_camMovLim, _totRegion;
BOOL		_moveKeyDisabled, _isInShop, _shouldBePaused, _shouldFadeOut, _shouldShowMenuScreen;
float		_currMasterVolume, _currBGMVolume, _currSFXVolume;
string		_playerChName = "";
int			_lineSpd = 2;

playground _pg;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// ���� �Լ�
int APIENTRY WinMain(_In_ HINSTANCE hInstance,
					 _In_opt_ HINSTANCE hPrevInstance,
					 _In_ LPSTR    lpCmdLine,
					 _In_ int       nCmdShow)
{
#ifdef _DEBUG 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // �޸� ������ �����Ѵ�.
	//_CrtSetBreakAlloc(3362); // �޸� ���� ���� ��ġ���� ������ �����Ѵ�.
#endif

	MSG			message;
	WNDCLASS	wndClass;

	_hInst = hInstance;

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	RECT winRect = {0, 0, WINW, WINH};

	AdjustWindowRect(&winRect, WS_CAPTION | WS_SYSMENU, FALSE);

	_hWnd = CreateWindow(
		WINNAME, WINNAME,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		WINX + winRect.left, WINY + winRect.top, winRect.right - winRect.left, winRect.bottom - winRect.top,
		nullptr, nullptr, hInstance, nullptr
	);

	ShowWindow(_hWnd, nCmdShow);

	if (FAILED(_pg.init()))	return NULL;

	while (TRUE)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			TIME->update(60.0f);
			_pg.update();
			_pg.render();
		}
	}
	
	_pg.release();

	UnregisterClass(WINNAME, _hInst);

	return (int)message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _pg.MainProc(hWnd, iMessage, wParam, lParam);
}
