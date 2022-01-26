
#include "stdafx.h"
#include "Lines.h"

Lines::Lines() :
	CURRENT_LEN(0),
	CNT(0),
	APPROACH(false),
	I(0),
	IMDEAD(false),
	BOLD(false)
{
	char C_LIST[] =
	{
		'ⓒ', '/', '\'', '[', ']', '<' ,'>' ,'(' , ')', '^', '_', '@', '|', '~', '+', ' ',
		'Ａ','Ｂ','Ｃ','Ｄ','Ｅ','Ｆ','Ｇ','Ｈ','Ｉ','Ｊ','Ｋ','Ｌ','Ｍ','Ｎ','Ｏ','Ｐ','Ｑ','Ｒ','Ｓ','Ｔ','Ｕ','Ｖ','Ｗ','Ｘ','Ｙ','Ｚ',
		'`','→', '￣', '┐', '˛', '．',
		'*', '\"', '!', '?', '-', ',' ,'.' ,':', ';', '&', '/,', '▶', '#', '=', '{', '}',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'0','1','2','3','4','5','6','7','8','9','$','▼'
	};


	//strcpy_s(WORD_CLIST, 256, C_LIST);

	for (int i = 0 ; i < 128; i++)
	{
		WORD_CLIST[i] = C_LIST[i];
	}

}

Lines::~Lines()
{
}

HRESULT Lines::init(POINT _pos, int _time, string _Lines, bool _bold, string _name)
{
	SUBSTR_LINE = _Lines;
	CLOCK = (float)_time;
	BOLD = _bold;
	NAME = _name;

	int e = 0;
	int h = 0;

	//한글자 한글자를 떼어내서 벡터에 담는다.
	for (int i = 0; i < SUBSTR_LINE.size(); i++)
	{
		oneChar ONE_WORD;

		if (SUBSTR_LINE[i] == '%')
		{
			e = 0;
			h++;
			continue;
		}
		ONE_WORD._x = _pos.x + (e * 32);
		ONE_WORD._y = _pos.y + (h * 60);

		//if (sizeof(char) < sizeof(SUBSTR_LINE[i])) //2바이트 한글일떄
		//else if (sizeof(char) == sizeof(SUBSTR_LINE[i])) //1바이트일때

		for (int j = 0; j < 256; j++)
		{
			if (SUBSTR_LINE[i] == WORD_CLIST[j])
			{
				if (!BOLD)		ONE_WORD.oChar = j;
				else if (BOLD)  ONE_WORD.oChar = j - 48;
				break;
			}
		}

		_vChar.push_back(ONE_WORD);

		e++;

	}
	return S_OK;
}


void Lines::release()
{

}

void Lines::update()
{
	if (CLOCK == 99998 && NAME == "CaLm")
	{
		I = 0;
		CURRENT_LEN = _vChar.size();
	}

	if (CLOCK != 99998 && NAME != "CaLm")
	{
		if (!APPROACH) newLine();
		if (APPROACH) CURRENT_CLOCK += (1.0f / 60.0f);
		if (APPROACH && CURRENT_CLOCK >= CLOCK) deleteLine();
	}

}

void Lines::render()
{
	charRender();
}

void Lines::charRender()
{
	for (int i = I; i < CURRENT_LEN; i++)
	{
		IMG->frameRender("타일셋", getMemDC(), _currOrg.x + _vChar[i]._x, _currOrg.y + _vChar[i]._y,
			((_vChar[i].oChar) % 16),
			(_vChar[i].oChar) / 16
		);
	}
}

void Lines::newLine()
{
	CNT = CNT % _lineSpd;

	if (!CNT)
	{
		if (CURRENT_LEN < _vChar.size())
		{
			CURRENT_LEN++;
		}
		else if (CURRENT_LEN >= _vChar.size())
		{
			CNT = 0;
			APPROACH = true;
		}
	}

	CNT++;
}

void Lines::deleteLine()
{
	CNT = CNT % _lineSpd;

	if (!CNT)
	{
		if (CURRENT_LEN >= I) I++;
		if (CURRENT_LEN <= I) IMDEAD = true;
	}

	CNT++;
}

void Lines::setPos(POINT _pos)
{
	for (int i = 0; i < _vChar.size(); i++)
	{
		_vChar[i]._x += _pos.x;
		_vChar[i]._y += _pos.y;
	}
}

void Lines::setPlace(POINT _pos)
{
	for (int i = 0; i < _vChar.size(); i++)
	{
		_vChar[i]._x = _pos.x;
		_vChar[i]._y = _pos.y;
	}
}

void Lines::chageWord(int _i, char _cW)
{
	for (int i = 0; i < 256; i++)
	{
		if (_cW == WORD_CLIST[i])
		{
			_vChar[_i].oChar = i;
			return;
		}
	}
}
