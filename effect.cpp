#include "stdafx.h"
#include "effect.h"
#include "animation.h"

effect::effect()
	: _effectImage(NULL),
	_effectAnimation(NULL),
	_isRunning(false),
	_x(0), _y(0)
{
}

effect::~effect()
{
}

HRESULT effect::init(image * effectImage, int frameW, int frameH, int fps, float elapsedTime)
{
	if (!effectImage) return E_FAIL;

	_effectImage = effectImage;
	_elapsedTime = elapsedTime;

	if (!_effectAnimation) _effectAnimation = new animation;

	_effectAnimation->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAnimation->setDefPlaylist(false, false);
	_effectAnimation->setFPS(fps);
	_effectAnimation->stop();

	return S_OK;
}

void effect::release()
{
	_effectImage = NULL;
	SAFE_DEL(_effectAnimation);
}

void effect::update()
{
	if (!_isRunning) return;

	_effectAnimation->frameUpdate(_elapsedTime);

	if (!_effectAnimation->isPlay()) kill();
}

void effect::render()
{
	if (!_isRunning) return;

	_effectImage->aniRender(getMemDC(), _x, _y, _effectAnimation);
}

void effect::start(int x, int y)
{
	if (!_effectImage || !_effectAnimation) return;

	_x = x - (_effectAnimation->getFrameWidth() / 2);
	_y = y - (_effectAnimation->getFrameHeight() / 2);

	_isRunning = true;
	_effectAnimation->start();
}

void effect::kill()
{
	_isRunning = false;
}
