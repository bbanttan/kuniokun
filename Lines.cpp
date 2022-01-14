
#include "stdafx.h"
#include "Lines.h"

/*Lines::Lines() :
	CNT(0),
	STR_IDX(0),
	APPROACH(true),
	KILL_COMPLETE(false),
	LAUNCH_COMPLETE(false),
	CLOCK_1(0.0f)
{

}

Lines::~Lines()
{

}

HRESULT Lines::init(RECT _rect, int _fontsize, bool _alive, int _time, string _Lines)
{
	LINE_RECT	= _rect;		//�Է¹��� �ؽ�Ʈ���� ��Ʈ�� �����Ѵ�.
	SUBSTR_LINE = _Lines;		//�Է¹��� ��縦 �����Ѵ�.
	FONT_SIZE	= _fontsize;	//��Ʈ������
	ALIVE		= _alive;		//TRUE�϶� Ư���ð���ŭ �ִٰ� ���� FALSE�϶� ��Ӷ��
	CLOCK		= (float)_time;	//ALIVE�� TRUE�϶� �������������������ΰ�.
	return S_OK;
}

void Lines::release()
{

}

void Lines::update()
{
	if (!ALIVE)
	{
		launcher_Line();
	}
	else if (ALIVE)
	{
		if (!LAUNCH_COMPLETE) launcher_Line();
		if (LAUNCH_COMPLETE)  CLOCK_1 += (1.0f/60.0f);	//�������� 60fps �̹Ƿ� 1/60�ϸ� 1�ʿ� 1�̵ȴ�.
		if (CLOCK_1 >= CLOCK) kill_Line();
	}
}

void Lines::render()
{
	HFONT Font = CreateFont(FONT_SIZE, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "�ü�ü");
	HFONT oFont = (HFONT)SelectObject(getMemDC(), Font);

	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), TRANSPARENT);

	if (LAUNCH_COMPLETE == false)	DrawText(getMemDC(), OUTPUT_LINE, strlen(OUTPUT_LINE), &LINE_RECT, DT_WORDBREAK | DT_LEFT);
	if (LAUNCH_COMPLETE)			DrawText(getMemDC(), OUTPUT_LINE, strlen(OUTPUT_LINE), &LINE_RECT, DT_WORDBREAK | DT_RIGHT);
	//DrawText(getMemDC(), OUTPUT_LINE, strlen(OUTPUT_LINE), &LINE_RECT, DT_WORDBREAK | DT_LEFT);

	SetTextColor(getMemDC(), RGB(0, 0, 0));

	SelectObject(getMemDC(), oFont);
	DeleteObject(Font);
}

void Lines::launcher_Line()
{
	if (APPROACH)
	{
		CNT = CNT % 2;

		if (!CNT)
		{	//���� : 1byte, �ѱ� : 2byte
			if ((SUBSTR_LINE[STR_IDX] & 0x80) == 0x80)		//�ѱ��϶�
			{
				STR_IDX += 2;	//2����Ʈ�� (�����ָ� �ܰ��� ���� ��)
				C_STR_LINE = SUBSTR_LINE.substr(0, STR_IDX);
			}
			else											//�ѱ��� �ƴҋ�
			{
				STR_IDX++;		//1����Ʈ��
				C_STR_LINE = SUBSTR_LINE.substr(0, STR_IDX);
			}
			//���� ������ �ε����� �Է¹��� ���ڿ��� �ε������� Ŀ���ų� ��������
			if (STR_IDX >= SUBSTR_LINE.size())
			{
				APPROACH = false;
				LAUNCH_COMPLETE = true;
				STR_IDX = 0;
				C_STR_LINE = SUBSTR_LINE.substr(0, SUBSTR_LINE.size());
			}
			//string�� ���ڿ� C_STR_LINE�� c_str()�� �̿��� char �������� �ٲ� OUTPUT_LINE�� ������.
			sprintf_s(OUTPUT_LINE, "%s", C_STR_LINE.c_str());
		}
		CNT++;
	}
}

void Lines::kill_Line()
{
	if (KILL_COMPLETE == false)
	{
		CNT = CNT % 2;

		if (!CNT)
		{	//���� : 1byte, �ѱ� : 2byte
			if ((SUBSTR_LINE[STR_IDX] & 0x80) == 0x80)		//�ѱ��϶�
			{
				STR_IDX += 2;	//2����Ʈ�� (�����ָ� �ܰ��� ���� ��)
				C_STR_LINE = SUBSTR_LINE.substr(STR_IDX, SUBSTR_LINE.size());
			}
			else											//�ѱ��� �ƴҋ�
			{
				STR_IDX++;		//1����Ʈ��
				C_STR_LINE = SUBSTR_LINE.substr(STR_IDX, SUBSTR_LINE.size());
			}
			//���� ������ �ε����� �Է¹��� ���ڿ��� �ε������� Ŀ���ų� ��������
			if (STR_IDX >= SUBSTR_LINE.size())
			{
				KILL_COMPLETE = true;
				C_STR_LINE = SUBSTR_LINE.substr(SUBSTR_LINE.size(), SUBSTR_LINE.size());
			}
			//string�� ���ڿ� C_STR_LINE�� c_str()�� �̿��� char �������� �ٲ� OUTPUT_LINE�� ������.
			sprintf_s(OUTPUT_LINE, "%s", C_STR_LINE.c_str());
		}
		CNT++;
	}
}

//     int nHeight,               // ����(���� ũ��)
//     int nWidth,                // ��. 0�� �־��ָ� ���̿� �����
//     int nEscapement,           // ���� ��ü ����
//     int nOrientation,          // ���ؼ��� ������ �ְ� ���� ����
//     int fnWeight,              // ��Ʈ�� �β�
//     DWORD fdwItalic,           // ���Ÿ�
//     DWORD fdwUnderline,        // ����
//     DWORD fdwStrikeOut,        // ��Ҽ�
//     DWORD fdwCharSet,		  // ĳ���� ��
//     DWORD fdwOutputPrecision,  // ���е�
//     DWORD fdwClipPrecision,    // ���е�
//     DWORD fdwQuality,          // ���е�
//     DWORD fdwPitchAndFamily,   // ���е�
//     LPCTSTR lpszFace           // �۲��̸�
*/
/*
Lines::Lines() :
	CURRENT_LEN(0),
	CNT(0),
	APPROACH(false),
	I(0),
	IMDEAD(false)
{

}

Lines::~Lines()
{

}

HRESULT Lines::init(POINT _pos, int _fontsize, int _time, string _Lines)
{
	FONT_SIZE = _fontsize;
	SUBSTR_LINE = _Lines;
	CLOCK = (float)_time;

	int e = 0;
	int h = 0;

	//�ѱ��� �ѱ��ڸ� ����� ���Ϳ� ��´�.
	for (int i = 0; i < SUBSTR_LINE.size(); )
	{
		oneChar ONE_WORD;

		if (SUBSTR_LINE[i] == '/')
		{
			e = 0;
			h++;
			i++;
			continue;
		}
		ONE_WORD._x = _pos.x + (e * FONT_SIZE);
		ONE_WORD._y = _pos.y + (h * FONT_SIZE);

		string C_STR_LINE;

		if ((SUBSTR_LINE[i] & 0x80) == 0x80)
		{
			C_STR_LINE = SUBSTR_LINE.substr(i, 2);
			i += 2;
		}
		else
		{
			C_STR_LINE = SUBSTR_LINE.substr(i, 1);
			i++;
		}

		sprintf_s(ONE_WORD.oChar, "%s", C_STR_LINE.c_str());

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
	if (!APPROACH) newLine();
	if (APPROACH) CURRENT_CLOCK += (1.0f / 60.0f);
	if (APPROACH && CURRENT_CLOCK >= CLOCK) deleteLine();
}

void Lines::render()
{
	HFONT Font = CreateFont(FONT_SIZE, 0, 0, 0, 1000, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "RCR");
	HFONT oFont = (HFONT)SelectObject(getMemDC(), Font);

	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), TRANSPARENT);

	for (int i = I; i < CURRENT_LEN; i++)
	{
		TextOut(getMemDC(), _vChar[i]._x, _vChar[i]._y, _vChar[i].oChar, strlen(_vChar[i].oChar));
	}

	SetTextColor(getMemDC(), RGB(0, 0, 0));

	SelectObject(getMemDC(), oFont);
	DeleteObject(Font);
}

void Lines::newLine()
{
	CNT = CNT % 1;

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
	CNT = CNT % 1;

	if (!CNT)
	{
		if (CURRENT_LEN >= I) I++;
		if (CURRENT_LEN <= I) IMDEAD = true;
	}

	CNT++;
}*/

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
		'��', '/', '\'', '[', ']', '<' ,'>' ,'(' , ')', '^', '_', '@', '|', '~', '+', ' ',
		'��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��','��',
		'`','��', '��', '��', '��', '��',
		'*', '\"', '!', '?', '-', ',' ,'.' ,':', ';', '&', '/,', '��', '#', '=', '{', '}',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'0','1','2','3','4','5','6','7','8','9','$','��'
	};
	int I_LIST[] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
		16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,
		42, 43, 44, 45, 46, 47,
		48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
		64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
		90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115,
		116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127
	};

	strcpy_s(WORD_CLIST, 256, C_LIST);

	for (int i = 0; i < sizeof(I_LIST) / sizeof(int); i++)
	{
		WORD_ILIST[i] = I_LIST[i];
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

	//�ѱ��� �ѱ��ڸ� ����� ���Ϳ� ��´�.
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

		//if (sizeof(char) < sizeof(SUBSTR_LINE[i])) //2����Ʈ �ѱ��ϋ�
		//else if (sizeof(char) == sizeof(SUBSTR_LINE[i])) //1����Ʈ�϶�

		for (int j = 0; j < 256; j++)
		{
			if (SUBSTR_LINE[i] == WORD_CLIST[j])
			{
				if (!BOLD)		ONE_WORD.oChar = WORD_ILIST[j];
				else if (BOLD)  ONE_WORD.oChar = WORD_ILIST[j] - 48;
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
		IMG->frameRender("Ÿ�ϼ�", getMemDC(), _currOrg.x + _vChar[i]._x, _currOrg.y + _vChar[i]._y,
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
			_vChar[_i].oChar = WORD_ILIST[i];
			return;
		}
	}
}
