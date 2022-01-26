
#pragma once
#include "gameNode.h"
#include <vector>

class Lines : public gameNode
{
private:
	//각각의 한글자한글자에 대한 좌표와 글자
	struct oneChar
	{
		float _x, _y;
		int oChar;
	};

	int
		CNT,				//띄우는속도에대한 인터벌
		FONT_SIZE,			//폰트 사이즈
		CURRENT_LEN,		//현재가리키고있는 배열번호
		I					//이건그냥 지울때 필요한 변수
		;

	bool
		APPROACH,			//접근제한, 글자가 생성이 완료될때 true가 된다.
		IMDEAD,
		BOLD
		;

	float
		CLOCK,				//init으로 부터 받아온 초단위시간
		CURRENT_CLOCK		//현재 프레임에 맞춰 1초를 카운트해주는 변수
		;

	string
		SUBSTR_LINE,		//init으로 부터 받아온 대사 문자열
		NAME
		;

	POINT LINE_POS;			//init으로 부터 받아온 생성위치

	char WORD_CLIST[128];

	vector<oneChar> _vChar;	//한글자한글자에가 저장되어있는 벡터

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