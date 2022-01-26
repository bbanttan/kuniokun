#include "stdafx.h"
#include "playground.h"
#include "loadingScene.h"

playground::playground()
{
}


playground::~playground()
{
}

HRESULT playground::init()
{
	gameNode::init(true);
	keysToCheck = { VK_ADD, VK_SUBTRACT, VK_RETURN, VK_LBUTTON, VK_RBUTTON, VK_RSHIFT, 'W', 'A', 'S', 'D', 'J', 'K' }; // �Է��� Ȯ���� Ű ����(��� Ű ����)

#ifdef _DEBUG
	vector<int> debugKeysToCheck = { VK_SPACE, VK_ESCAPE, 
		VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12,
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
		'Q', 'E' }; // �Է��� Ȯ���� Ű ����(��� Ű ����, ����� ����)
	keysToCheck.insert(end(keysToCheck), begin(debugKeysToCheck), end(debugKeysToCheck));
#endif

	SC->addScene("�ε� ���", new loadingScene);

	_moveKeyDisabled = FALSE;
	_shouldFadeOut = FALSE;
	_shouldShowMenuScreen = FALSE;
	SC->changeScene("�ε� ���");

	_blackScreenAlpha = 0x00;

	_currMasterVolume = 1.f;
	_currBGMVolume = _currSFXVolume = 0.5f;

	return S_OK;
}


void playground::release()
{
	gameNode::release();
}

void playground::update()
{
	KEY->updateKeyState(keysToCheck);

#ifdef _DEBUG
	if (KEY->down(VK_SUBTRACT))
	{
		_currMasterVolume = max(0.f, _currMasterVolume - 0.1f);
		SND->updateMasterVolume();
	}
	else if (KEY->down(VK_ADD))
	{
		_currMasterVolume = min(1.f, _currMasterVolume + 0.1f);
		SND->updateMasterVolume();
	}
#endif

	gameNode::update();

	if (_shouldFadeOut)
	{
		// ���̵�ƿ��� �°� ���� ���� �����Ѵ�.
		if (_blackScreenAlpha < 0xFF) _blackScreenAlpha += min(0x22, 0xFF - _blackScreenAlpha);
	}
	else if (_blackScreenAlpha != 0x00)
	{
		// ���̵��ο� �°� ���� ���� �����Ѵ�.
		if (_blackScreenAlpha > 0x00) _blackScreenAlpha -= min(0x22, _blackScreenAlpha);
	}

	SC->update();
}


void playground::render()
{
	// PatBlt(getMemDC(), 0, 0, WINW, WINH, BLACKNESS);

	if (!_shouldFadeOut) SC->render();

	if (_blackScreenAlpha > 0x00) IMG->alphaRender("���� ȭ��", getMemDC(), _currOrg.x, _currOrg.y, _blackScreenAlpha);
	
	if (KEY->isToggledOn(VK_SCROLL))
	{
		TIME->render(getMemDC());

		char str[256];
#ifdef _DEBUG
		{
			sprintf_s(str, "Current master volume: %d%% (Num+, Num-)", static_cast<int>(roundf(_currMasterVolume * 100.f)));
			TextOut(getMemDC(), 0, 80, str, static_cast<int>(strlen(str)));
			sprintf_s(str, "Current BGM volume: %d%%", static_cast<int>(roundf(_currBGMVolume * 100.f)));
			TextOut(getMemDC(), 0, 96, str, static_cast<int>(strlen(str)));
			sprintf_s(str, "Current SFX volume: %d%%", static_cast<int>(roundf(_currSFXVolume * 100.f)));
			TextOut(getMemDC(), 0, 112, str, static_cast<int>(strlen(str)));
		}
#endif
	}

	_backBuffer->render(getHDC(), _currOrg.x, _currOrg.y, 0, 0, WINW, WINH);
}

