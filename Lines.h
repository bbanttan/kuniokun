
#pragma once
#include "gameNode.h"
#include <vector>

class Lines : public gameNode
{
private:
	//������ �ѱ����ѱ��ڿ� ���� ��ǥ�� ����
	struct oneChar
	{
		float _x, _y;
		int oChar;
	};

	int
		CNT,				//���¼ӵ������� ���͹�
		FONT_SIZE,			//��Ʈ ������
		CURRENT_LEN,		//���簡��Ű���ִ� �迭��ȣ
		I					//�̰Ǳ׳� ���ﶧ �ʿ��� ����
		;

	bool
		APPROACH,			//��������, ���ڰ� ������ �Ϸ�ɶ� true�� �ȴ�.
		IMDEAD,
		BOLD
		;

	float
		CLOCK,				//init���� ���� �޾ƿ� �ʴ����ð�
		CURRENT_CLOCK		//���� �����ӿ� ���� 1�ʸ� ī��Ʈ���ִ� ����
		;

	string
		SUBSTR_LINE,		//init���� ���� �޾ƿ� ��� ���ڿ�
		NAME
		;

	POINT LINE_POS;			//init���� ���� �޾ƿ� ������ġ

	char WORD_CLIST[128];

	vector<oneChar> _vChar;	//�ѱ����ѱ��ڿ��� ����Ǿ��ִ� ����

public:
	Lines();
	~Lines();

	virtual HRESULT init(POINT _pos, int _time, string _Lines, bool _bold, string _name);
	virtual void release();
	virtual void update();
	virtual void render();

	void setLineKill() { CURRENT_CLOCK = 99999; }

	void charRender();

	void deleteLine();

	void newLine();

	bool getDead() { return IMDEAD; }
	void setPos(POINT _pos);
	void setPlace(POINT _pos);
	string getName() { return NAME; }
	void chageWord(int _i, char _cW);
	POINT getPos()
	{
		POINT POS = { _vChar[0]._x, _vChar[0]._y };
		return POS;
	}
	char getSelectArrWord(int _i) { return WORD_CLIST[_vChar[_i].oChar]; }
};