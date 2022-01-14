
#pragma once
#include "singleton.h"
#include "Lines.h"
#include <fstream>
#include <vector>

enum Trigger
{
	NO,			//�׳� �ʱ�ȭ
	P_DIE,		//�÷��̾ �׾��� ��
	E_DIE,		//���� �׾��� ��
	E_HELP,		//���� ������ ��
	MAP1,		//�� 1�� ��
	MAP2,		//�� 2�� ��
	MAP3,		//�� 3�� ��
	MAP4,		//�� 4�� ��
	MAP4_2,		//�� 4-2�� ��
	MAP5		//�� 5�� ��
};

class LineManager : public singleton<LineManager>
{
private:
	bool POSITION;
	vector<Lines*> _vLine;

public:
	LineManager();
	~LineManager();

	virtual HRESULT init();
	virtual void release();

	virtual void update();
	void selectUpdate(string _name);

	virtual void render();
	void selectRender(string _name);

	void CreateLine(POINT _rect, string _Lines, string _name, bool _bold, int _time = 99999);
	void calmLine(POINT _rect, string _Lines);
	void CorrectLine(string _name, POINT _pos);
	void setPosLine(string _name, POINT _pos);
	void trgLine(Trigger _trg, string _name = "no");

	void AllDeleteLine();
	void selectDeleteLine(string _name);

	void selectChangeLine(string _name, int _i, char _cW);

	string txtFind(string _line, string _name = "no", int _plusLine = 1);
	POINT getLinePos(string _name)
	{
		for (int i = 0; i < _vLine.size(); i++)
		{
			if (_vLine[i]->getName() == _name)
			{
				return _vLine[i]->getPos();
			}
		}
	}
	void setKill(string _name)
	{
		for (int i = 0; i < _vLine.size(); i++)
		{
			if (_vLine[i]->getName() == _name)
			{
				_vLine[i]->setLineKill();
			}
		}
	}
	char getArrWord(string _name, int _i)
	{
		for (int i = 0; i < _vLine.size(); i++)
		{
			if (_vLine[i]->getName() == _name)
			{
				return _vLine[i]->getSelectArrWord(_i);
			}
		}
	}
};

