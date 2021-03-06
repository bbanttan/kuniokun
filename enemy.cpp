#include "stdafx.h"
#include "enemy.h"

HRESULT enemy::init()
{
	return S_OK;
}

HRESULT enemy::init(POINT3D pt, int type, int color)
{
	_type = type;
	_color = color;
	_emSet.CH = pt;				//위치

	ani1Set();
	ani2Set();
	ani3Set();
	ani4Set();
	ani6Set();
	ani7Set();

	//보스
	if (_type == 0)
	{
		_walk = IMG->find("보스-걷기");
		_run = IMG->find("보스-달리기");
		_punch = IMG->find("보스-펀치");
		_kick = IMG->find("보스-킥");
		_uppercut = IMG->find("보스-어퍼컷");
		_highkick = IMG->find("보스-하이킥");
		_run_punch = IMG->find("보스-달리기펀치");
		_jump = IMG->find("보스-점프");
		_jumpkick = IMG->find("보스-점프킥");
		_defend = IMG->find("보스-방어");
		_beatup = IMG->find("보스-피격");
		_ko = IMG->find("보스-KO");
		_stick_pipe = IMG->find("보스-스틱");
		_chain = IMG->find("보스-체인");
		_knuckles = IMG->find("보스-너클");
		_rock = IMG->find("보스-돌");
		_lift_trashcan = IMG->find("보스-쓰레기");
		_lift_crate = IMG->find("보스-박스");
		_lift_tire = IMG->find("보스-타이어");
		_lift_human = IMG->find("보스-사람");
		_throw_stick_pipe = IMG->find("보스-스틱던지기");
		_throw_chain = IMG->find("보스-체인던지기");
		_throw_knuckles = IMG->find("보스-너클던지기");
		_throw_rock = IMG->find("보스-돌던지기");
		_throw_trashcan = IMG->find("보스-쓰레기던지기");
		_throw_crate = IMG->find("보스-박스던지기");
		_throw_tire = IMG->find("보스-타이어던지기");
		_throw_human = IMG->find("보스-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		if (_color == 0)
		{
			_emSet.chName = "Moose";	//이름

			_emStatus.punch = 26;	//펀치
			_emStatus.kick = 35;	//킥
			_emStatus.weapon = 23;	//무기
			_emStatus.power = 28;	//힘
			_emStatus.agility = 25;	//민첩
			_emStatus.guard = 25;	//가드
			_emStatus.endure = 22;	//맷집
			_emStatus.energy = 24;	//기력
			_emStatus.hp = _emStatus.maxHP = 52;	//체력
			_emStatus.money = 225;	//돈 드랍
		}

		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

	}
	//타입1
	if (_type == 1)
	{

		_walk = IMG->find("1-걷기");
		_run = IMG->find("1-달리기");
		_punch = IMG->find("1-펀치");
		_kick = IMG->find("1-킥");
		_uppercut = IMG->find("1-어퍼컷");
		_highkick = IMG->find("1-하이킥");
		_run_punch = IMG->find("1-달리기펀치");
		_jump = IMG->find("1-점프");
		_jumpkick = IMG->find("1-점프킥");
		_defend = IMG->find("1-방어");
		_beatup = IMG->find("1-피격");
		_ko = IMG->find("1-KO");
		_stick_pipe = IMG->find("1-스틱");
		_chain = IMG->find("1-체인");
		_knuckles = IMG->find("1-너클");
		_rock = IMG->find("1-돌");
		_lift_trashcan = IMG->find("1-쓰레기");
		_lift_crate = IMG->find("1-박스");
		_lift_tire = IMG->find("1-타이어");
		_lift_human = IMG->find("1-사람");
		_throw_stick_pipe = IMG->find("1-스틱던지기");
		_throw_chain = IMG->find("1-체인던지기");
		_throw_knuckles = IMG->find("1-너클던지기");
		_throw_rock = IMG->find("1-돌던지기");
		_throw_trashcan = IMG->find("1-쓰레기던지기");
		_throw_crate = IMG->find("1-박스던지기");
		_throw_tire = IMG->find("1-타이어던지기");
		_throw_human = IMG->find("1-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Larry";	//이름

			_emStatus.punch = 12;	//펀치
			_emStatus.kick = 4;	//킥
			_emStatus.weapon = 6;	//무기
			_emStatus.power = 1;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 5;	//가드
			_emStatus.endure = 5;	//맷집
			_emStatus.energy = 8;	//기력
			_emStatus.hp = _emStatus.maxHP = 13;	//체력
			_emStatus.money = 50;	//돈 드랍
		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Skip";		//이름

			_emStatus.punch = 18;	//펀치
			_emStatus.kick = 4;	//킥
			_emStatus.weapon = 7;	//무기
			_emStatus.power = 8;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 4;	//가드
			_emStatus.endure = 11;	//맷집
			_emStatus.energy = 7;	//기력
			_emStatus.hp = _emStatus.maxHP = 12;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Rex";		//이름

			_emStatus.punch = 15;	//펀치
			_emStatus.kick = 10;	//킥
			_emStatus.weapon = 10;	//무기
			_emStatus.power = 8;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 12;	//가드
			_emStatus.endure = 8;	//맷집
			_emStatus.energy = 10;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Robby";		//이름

			_emStatus.punch = 22;	//펀치
			_emStatus.kick = 11;	//킥
			_emStatus.weapon = 13;	//무기
			_emStatus.power = 14;	//힘
			_emStatus.agility = 10;	//민첩
			_emStatus.guard = 11;	//가드
			_emStatus.endure = 14;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Lefty";		//이름

			_emStatus.punch = 26;	//펀치
			_emStatus.kick = 15;	//킥
			_emStatus.weapon = 14;	//무기
			_emStatus.power = 17;	//힘
			_emStatus.agility = 14;	//민첩
			_emStatus.guard = 15;	//가드
			_emStatus.endure = 13;	//맷집
			_emStatus.energy = 13;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Herb";		//이름

			_emStatus.punch = 24;	//펀치
			_emStatus.kick = 19;	//킥
			_emStatus.weapon = 19;	//무기
			_emStatus.power = 14;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 16;	//가드
			_emStatus.endure = 20;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Boris";		//이름

			_emStatus.punch = 31;	//펀치
			_emStatus.kick = 19;	//킥
			_emStatus.weapon = 16;	//무기
			_emStatus.power = 17;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 21;	//가드
			_emStatus.endure = 18;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Bubba";		//이름

			_emStatus.punch = 30;	//펀치
			_emStatus.kick = 17;	//킥
			_emStatus.weapon = 24;	//무기
			_emStatus.power = 21;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 21;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Slash";		//이름

			_emStatus.punch = 34;	//펀치
			_emStatus.kick = 24;	//킥
			_emStatus.weapon = 22;	//무기
			_emStatus.power = 19;	//힘
			_emStatus.agility = 24;	//민첩
			_emStatus.guard = 25;	//가드
			_emStatus.endure = 23;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위
	}
	//타입2
	if (_type == 2)
	{
		_walk = IMG->find("2-걷기");
		_run = IMG->find("2-달리기");
		_punch = IMG->find("2-펀치");
		_kick = IMG->find("2-킥");
		_uppercut = IMG->find("2-어퍼컷");
		_highkick = IMG->find("2-하이킥");
		_run_punch = IMG->find("2-달리기펀치");
		_jump = IMG->find("2-점프");
		_jumpkick = IMG->find("2-점프킥");
		_defend = IMG->find("2-방어");
		_beatup = IMG->find("2-피격");
		_ko = IMG->find("2-KO");
		_stick_pipe = IMG->find("2-스틱");
		_chain = IMG->find("2-체인");
		_knuckles = IMG->find("2-너클");
		_rock = IMG->find("2-돌");
		_lift_trashcan = IMG->find("2-쓰레기");
		_lift_crate = IMG->find("2-박스");
		_lift_tire = IMG->find("2-타이어");
		_lift_human = IMG->find("2-사람");
		_throw_stick_pipe = IMG->find("2-스틱던지기");
		_throw_chain = IMG->find("2-체인던지기");
		_throw_knuckles = IMG->find("2-너클던지기");
		_throw_rock = IMG->find("2-돌던지기");
		_throw_trashcan = IMG->find("2-쓰레기던지기");
		_throw_crate = IMG->find("2-박스던지기");
		_throw_tire = IMG->find("2-타이어던지기");
		_throw_human = IMG->find("2-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Barry";	//이름

			_emStatus.punch = 2;	//펀치
			_emStatus.kick = 14;	//킥
			_emStatus.weapon = 5;	//무기
			_emStatus.power = 2;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 5;	//가드
			_emStatus.endure = 4;	//맷집
			_emStatus.energy = 9;	//기력
			_emStatus.hp = _emStatus.maxHP = 11;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Trent";		//이름

			_emStatus.punch = 8;	//펀치
			_emStatus.kick = 14;	//킥
			_emStatus.weapon = 6;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 8;	//민첩
			_emStatus.guard = 4;	//가드
			_emStatus.endure = 10;	//맷집
			_emStatus.energy = 8;	//기력
			_emStatus.hp = _emStatus.maxHP = 10;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Lance";		//이름

			_emStatus.punch = 5;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 9;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 8;	//민첩
			_emStatus.guard = 12;	//가드
			_emStatus.endure = 7;	//맷집
			_emStatus.energy = 11;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Chip";		//이름

			_emStatus.punch = 12;	//펀치
			_emStatus.kick = 21;	//킥
			_emStatus.weapon = 12;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 11;	//민첩
			_emStatus.guard = 11;	//가드
			_emStatus.endure = 13;	//맷집
			_emStatus.energy = 15;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Sid";		//이름

			_emStatus.punch = 16;	//펀치
			_emStatus.kick = 25;	//킥
			_emStatus.weapon = 13;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 15;	//민첩
			_emStatus.guard = 15;	//가드
			_emStatus.endure = 12;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Erwin";		//이름

			_emStatus.punch = 14;	//펀치
			_emStatus.kick = 29;	//킥
			_emStatus.weapon = 18;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 16;	//가드
			_emStatus.endure = 19;	//맷집
			_emStatus.energy = 15;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Yemi";		//이름

			_emStatus.punch = 21;	//펀치
			_emStatus.kick = 29;	//킥
			_emStatus.weapon = 15;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 21;	//가드
			_emStatus.endure = 17;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Shane";		//이름

			_emStatus.punch = 20;	//펀치
			_emStatus.kick = 27;	//킥
			_emStatus.weapon = 23;	//무기
			_emStatus.power = 22;	//힘
			_emStatus.agility = 21;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 20;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Edge";		//이름

			_emStatus.punch = 24;	//펀치
			_emStatus.kick = 34;	//킥
			_emStatus.weapon = 21;	//무기
			_emStatus.power = 20;	//힘
			_emStatus.agility = 25;	//민첩
			_emStatus.guard = 25;	//가드
			_emStatus.endure = 22;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

	}
	//타입3
	if (_type == 3)
	{

		_walk = IMG->find("3-걷기");
		_run = IMG->find("3-달리기");
		_punch = IMG->find("3-펀치");
		_kick = IMG->find("3-킥");
		_uppercut = IMG->find("3-어퍼컷");
		_highkick = IMG->find("3-하이킥");
		_run_punch = IMG->find("3-달리기펀치");
		_jump = IMG->find("3-점프");
		_jumpkick = IMG->find("3-점프킥");
		_defend = IMG->find("3-방어");
		_beatup = IMG->find("3-피격");
		_ko = IMG->find("3-KO");
		_stick_pipe = IMG->find("3-스틱");
		_chain = IMG->find("3-체인");
		_knuckles = IMG->find("3-너클");
		_rock = IMG->find("3-돌");
		_lift_trashcan = IMG->find("3-쓰레기");
		_lift_crate = IMG->find("3-박스");
		_lift_tire = IMG->find("3-타이어");
		_lift_human = IMG->find("3-사람");
		_throw_stick_pipe = IMG->find("3-스틱던지기");
		_throw_chain = IMG->find("3-체인던지기");
		_throw_knuckles = IMG->find("3-너클던지기");
		_throw_rock = IMG->find("3-돌던지기");
		_throw_trashcan = IMG->find("3-쓰레기던지기");
		_throw_crate = IMG->find("3-박스던지기");
		_throw_tire = IMG->find("3-타이어던지기");
		_throw_human = IMG->find("3-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Terry";	//이름

			_emStatus.punch = 3;	//펀치
			_emStatus.kick = 4;	//킥
			_emStatus.weapon = 15;	//무기
			_emStatus.power = 1;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 5;	//가드
			_emStatus.endure = 4;	//맷집
			_emStatus.energy = 9;	//기력
			_emStatus.hp = _emStatus.maxHP = 11;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Logan";		//이름

			_emStatus.punch = 9;	//펀치
			_emStatus.kick = 4;	//킥
			_emStatus.weapon = 16;	//무기
			_emStatus.power = 8;	//힘
			_emStatus.agility = 8;	//민첩
			_emStatus.guard = 4;	//가드
			_emStatus.endure = 10;	//맷집
			_emStatus.energy = 8;	//기력
			_emStatus.hp = _emStatus.maxHP = 10;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Dirk";		//이름

			_emStatus.punch = 6;	//펀치
			_emStatus.kick = 10;	//킥
			_emStatus.weapon = 19;	//무기
			_emStatus.power = 8;	//힘
			_emStatus.agility = 8;	//민첩
			_emStatus.guard = 12;	//가드
			_emStatus.endure = 7;	//맷집
			_emStatus.energy = 11;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Ernie";		//이름

			_emStatus.punch = 13;	//펀치
			_emStatus.kick = 11;	//킥
			_emStatus.weapon = 22;	//무기
			_emStatus.power = 14;	//힘
			_emStatus.agility = 11;	//민첩
			_emStatus.guard = 11;	//가드
			_emStatus.endure = 13;	//맷집
			_emStatus.energy = 15;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Tony";		//이름

			_emStatus.punch = 17;	//펀치
			_emStatus.kick = 15;	//킥
			_emStatus.weapon = 23;	//무기
			_emStatus.power = 17;	//힘
			_emStatus.agility = 15;	//민첩
			_emStatus.guard = 15;	//가드
			_emStatus.endure = 12;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Felix";		//이름

			_emStatus.punch = 15;	//펀치
			_emStatus.kick = 19;	//킥
			_emStatus.weapon = 28;	//무기
			_emStatus.power = 14;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 16;	//가드
			_emStatus.endure = 19;	//맷집
			_emStatus.energy = 15;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Fuji";		//이름

			_emStatus.punch = 22;	//펀치
			_emStatus.kick = 19;	//킥
			_emStatus.weapon = 25;	//무기
			_emStatus.power = 17;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 21;	//가드
			_emStatus.endure = 17;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Bart";		//이름

			_emStatus.punch = 21;	//펀치
			_emStatus.kick = 17;	//킥
			_emStatus.weapon = 33;	//무기
			_emStatus.power = 21;	//힘
			_emStatus.agility = 21;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 20;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Blaze";		//이름

			_emStatus.punch = 25;	//펀치
			_emStatus.kick = 24;	//킥
			_emStatus.weapon = 31;	//무기
			_emStatus.power = 19;	//힘
			_emStatus.agility = 25;	//민첩
			_emStatus.guard = 25;	//가드
			_emStatus.endure = 22;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위
	}
	//타입4
	if (_type == 4)
	{

		_walk = IMG->find("4-걷기");
		_run = IMG->find("4-달리기");
		_punch = IMG->find("4-펀치");
		_kick = IMG->find("4-킥");
		_uppercut = IMG->find("4-어퍼컷");
		_highkick = IMG->find("4-하이킥");
		_run_punch = IMG->find("4-달리기펀치");
		_jump = IMG->find("4-점프");
		_jumpkick = IMG->find("4-점프킥");
		_defend = IMG->find("4-방어");
		_beatup = IMG->find("4-피격");
		_ko = IMG->find("4-KO");
		_stick_pipe = IMG->find("4-스틱");
		_chain = IMG->find("4-체인");
		_knuckles = IMG->find("4-너클");
		_rock = IMG->find("4-돌");
		_lift_trashcan = IMG->find("4-쓰레기");
		_lift_crate = IMG->find("4-박스");
		_lift_tire = IMG->find("4-타이어");
		_lift_human = IMG->find("4-사람");
		_throw_stick_pipe = IMG->find("4-스틱던지기");
		_throw_chain = IMG->find("4-체인던지기");
		_throw_knuckles = IMG->find("4-너클던지기");
		_throw_rock = IMG->find("4-돌던지기");
		_throw_trashcan = IMG->find("4-쓰레기던지기");
		_throw_crate = IMG->find("4-박스던지기");
		_throw_tire = IMG->find("4-타이어던지기");
		_throw_human = IMG->find("4-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Jerry";	//이름

			_emStatus.punch = 2;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 5;	//무기
			_emStatus.power = 11;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 5;	//가드
			_emStatus.endure = 5;	//맷집
			_emStatus.energy = 8;	//기력
			_emStatus.hp = _emStatus.maxHP = 13;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Biff";		//이름

			_emStatus.punch = 8;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 6;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 4;	//가드
			_emStatus.endure = 11;	//맷집
			_emStatus.energy = 7;	//기력
			_emStatus.hp = _emStatus.maxHP = 12;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Nick";		//이름

			_emStatus.punch = 5;	//펀치
			_emStatus.kick = 11;	//킥
			_emStatus.weapon = 9;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 12;	//가드
			_emStatus.endure = 8;	//맷집
			_emStatus.energy = 10;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Steve";		//이름

			_emStatus.punch = 12;	//펀치
			_emStatus.kick = 12;	//킥
			_emStatus.weapon = 12;	//무기
			_emStatus.power = 24;	//힘
			_emStatus.agility = 10;	//민첩
			_emStatus.guard = 11;	//가드
			_emStatus.endure = 14;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Marco";		//이름

			_emStatus.punch = 16;	//펀치
			_emStatus.kick = 16;	//킥
			_emStatus.weapon = 13;	//무기
			_emStatus.power = 27;	//힘
			_emStatus.agility = 14;	//민첩
			_emStatus.guard = 15;	//가드
			_emStatus.endure = 13;	//맷집
			_emStatus.energy = 13;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Morty";		//이름

			_emStatus.punch = 14;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 18;	//무기
			_emStatus.power = 24;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 16;	//가드
			_emStatus.endure = 20;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Wang";		//이름

			_emStatus.punch = 21;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 15;	//무기
			_emStatus.power = 27;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 21;	//가드
			_emStatus.endure = 18;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Luke";		//이름

			_emStatus.punch = 20;	//펀치
			_emStatus.kick = 18;	//킥
			_emStatus.weapon = 23;	//무기
			_emStatus.power = 31;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 21;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Tonto";		//이름

			_emStatus.punch = 24;	//펀치
			_emStatus.kick = 25;	//킥
			_emStatus.weapon = 21;	//무기
			_emStatus.power = 29;	//힘
			_emStatus.agility = 24;	//민첩
			_emStatus.guard = 25;	//가드
			_emStatus.endure = 23;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

	}
	//타입5
	if (_type == 5)
	{

		_walk = IMG->find("5-걷기");
		_run = IMG->find("5-달리기");
		_punch = IMG->find("5-펀치");
		_kick = IMG->find("5-킥");
		_uppercut = IMG->find("5-어퍼컷");
		_highkick = IMG->find("5-하이킥");
		_run_punch = IMG->find("5-달리기펀치");
		_jump = IMG->find("5-점프");
		_jumpkick = IMG->find("5-점프킥");
		_defend = IMG->find("5-방어");
		_beatup = IMG->find("5-피격");
		_ko = IMG->find("5-KO");
		_stick_pipe = IMG->find("5-스틱");
		_chain = IMG->find("5-체인");
		_knuckles = IMG->find("5-너클");
		_rock = IMG->find("5-돌");
		_lift_trashcan = IMG->find("5-쓰레기");
		_lift_crate = IMG->find("5-박스");
		_lift_tire = IMG->find("5-타이어");
		_lift_human = IMG->find("5-사람");
		_throw_stick_pipe = IMG->find("5-스틱던지기");
		_throw_chain = IMG->find("5-체인던지기");
		_throw_knuckles = IMG->find("5-너클던지기");
		_throw_rock = IMG->find("5-돌던지기");
		_throw_trashcan = IMG->find("5-쓰레기던지기");
		_throw_crate = IMG->find("5-박스던지기");
		_throw_tire = IMG->find("5-타이어던지기");
		_throw_human = IMG->find("5-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Cary";	//이름

			_emStatus.punch = 4;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 6;	//무기
			_emStatus.power = 2;	//힘
			_emStatus.agility = 15;	//민첩
			_emStatus.guard = 6;	//가드
			_emStatus.endure = 3;	//맷집
			_emStatus.energy = 8;	//기력
			_emStatus.hp = _emStatus.maxHP = 9;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Drake";		//이름

			_emStatus.punch = 10;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 7;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 16;	//민첩
			_emStatus.guard = 5;	//가드
			_emStatus.endure = 9;	//맷집
			_emStatus.energy = 7;	//기력
			_emStatus.hp = _emStatus.maxHP = 8;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Brad";		//이름

			_emStatus.punch = 7;	//펀치
			_emStatus.kick = 11;	//킥
			_emStatus.weapon = 10;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 16;	//민첩
			_emStatus.guard = 13;	//가드
			_emStatus.endure = 6;	//맷집
			_emStatus.energy = 10;	//기력
			_emStatus.hp = _emStatus.maxHP = 12;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Doug";		//이름

			_emStatus.punch = 14;	//펀치
			_emStatus.kick = 12;	//킥
			_emStatus.weapon = 13;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 12;	//가드
			_emStatus.endure = 12;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Vinny";		//이름

			_emStatus.punch = 18;	//펀치
			_emStatus.kick = 16;	//킥
			_emStatus.weapon = 14;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 23;	//민첩
			_emStatus.guard = 16;	//가드
			_emStatus.endure = 11;	//맷집
			_emStatus.energy = 13;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Berni";		//이름

			_emStatus.punch = 16;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 19;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 28;	//민첩
			_emStatus.guard = 17;	//가드
			_emStatus.endure = 18;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Akbar";		//이름

			_emStatus.punch = 23;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 16;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 28;	//민첩
			_emStatus.guard = 22;	//가드
			_emStatus.endure = 16;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Duke";		//이름

			_emStatus.punch = 22;	//펀치
			_emStatus.kick = 18;	//킥
			_emStatus.weapon = 24;	//무기
			_emStatus.power = 22;	//힘
			_emStatus.agility = 29;	//민첩
			_emStatus.guard = 21;	//가드
			_emStatus.endure = 19;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Stick";		//이름

			_emStatus.punch = 26;	//펀치
			_emStatus.kick = 25;	//킥
			_emStatus.weapon = 22;	//무기
			_emStatus.power = 20;	//힘
			_emStatus.agility = 33;	//민첩
			_emStatus.guard = 26;	//가드
			_emStatus.endure = 21;	//맷집
			_emStatus.energy = 21;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

	}
	//타입6
	if (_type == 6)
	{

		_walk = IMG->find("6-걷기");
		_run = IMG->find("6-달리기");
		_punch = IMG->find("6-펀치");
		_kick = IMG->find("6-킥");
		_uppercut = IMG->find("6-어퍼컷");
		_highkick = IMG->find("6-하이킥");
		_run_punch = IMG->find("6-달리기펀치");
		_jump = IMG->find("6-점프");
		_jumpkick = IMG->find("6-점프킥");
		_defend = IMG->find("6-방어");
		_beatup = IMG->find("6-피격");
		_ko = IMG->find("6-KO");
		_stick_pipe = IMG->find("6-스틱");
		_chain = IMG->find("6-체인");
		_knuckles = IMG->find("6-너클");
		_rock = IMG->find("6-돌");
		_lift_trashcan = IMG->find("6-쓰레기");
		_lift_crate = IMG->find("6-박스");
		_lift_tire = IMG->find("6-타이어");
		_lift_human = IMG->find("6-사람");
		_throw_stick_pipe = IMG->find("6-스틱던지기");
		_throw_chain = IMG->find("6-체인던지기");
		_throw_knuckles = IMG->find("6-너클던지기");
		_throw_rock = IMG->find("6-돌던지기");
		_throw_trashcan = IMG->find("6-쓰레기던지기");
		_throw_crate = IMG->find("6-박스던지기");
		_throw_tire = IMG->find("6-타이어던지기");
		_throw_human = IMG->find("6-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Gary";	//이름

			_emStatus.punch = 4;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 6;	//무기
			_emStatus.power = 3;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 14;	//가드
			_emStatus.endure = 3;	//맷집
			_emStatus.energy = 7;	//기력
			_emStatus.hp = _emStatus.maxHP = 11;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Trip";		//이름

			_emStatus.punch = 10;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 7;	//무기
			_emStatus.power = 10;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 13;	//가드
			_emStatus.endure = 9;	//맷집
			_emStatus.energy = 6;	//기력
			_emStatus.hp = _emStatus.maxHP = 10;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Matt";		//이름

			_emStatus.punch = 7;	//펀치
			_emStatus.kick = 11;	//킥
			_emStatus.weapon = 10;	//무기
			_emStatus.power = 10;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 21;	//가드
			_emStatus.endure = 6;	//맷집
			_emStatus.energy = 9;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Greg";		//이름

			_emStatus.punch = 14;	//펀치
			_emStatus.kick = 12;	//킥
			_emStatus.weapon = 13;	//무기
			_emStatus.power = 16;	//힘
			_emStatus.agility = 10;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 12;	//맷집
			_emStatus.energy = 13;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Mouse";		//이름

			_emStatus.punch = 18;	//펀치
			_emStatus.kick = 16;	//킥
			_emStatus.weapon = 14;	//무기
			_emStatus.power = 19;	//힘
			_emStatus.agility = 14;	//민첩
			_emStatus.guard = 24;	//가드
			_emStatus.endure = 11;	//맷집
			_emStatus.energy = 12;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Byron";		//이름

			_emStatus.punch = 16;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 19;	//무기
			_emStatus.power = 16;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 25;	//가드
			_emStatus.endure = 18;	//맷집
			_emStatus.energy = 13;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Juan";		//이름

			_emStatus.punch = 23;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 16;	//무기
			_emStatus.power = 19;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 30;	//가드
			_emStatus.endure = 16;	//맷집
			_emStatus.energy = 20;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Slim";		//이름

			_emStatus.punch = 22;	//펀치
			_emStatus.kick = 18;	//킥
			_emStatus.weapon = 24;	//무기
			_emStatus.power = 23;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 29;	//가드
			_emStatus.endure = 19;	//맷집
			_emStatus.energy = 20;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Mooky";		//이름

			_emStatus.punch = 26;	//펀치
			_emStatus.kick = 25;	//킥
			_emStatus.weapon = 22;	//무기
			_emStatus.power = 21;	//힘
			_emStatus.agility = 24;	//민첩
			_emStatus.guard = 34;	//가드
			_emStatus.endure = 21;	//맷집
			_emStatus.energy = 20;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

	}
	//타입7
	if (_type == 7)
	{

		_walk = IMG->find("7-걷기");
		_run = IMG->find("7-달리기");
		_punch = IMG->find("7-펀치");
		_kick = IMG->find("7-킥");
		_uppercut = IMG->find("7-어퍼컷");
		_highkick = IMG->find("7-하이킥");
		_run_punch = IMG->find("7-달리기펀치");
		_jump = IMG->find("7-점프");
		_jumpkick = IMG->find("7-점프킥");
		_defend = IMG->find("7-방어");
		_beatup = IMG->find("7-피격");
		_ko = IMG->find("7-KO");
		_stick_pipe = IMG->find("7-스틱");
		_chain = IMG->find("7-체인");
		_knuckles = IMG->find("7-너클");
		_rock = IMG->find("7-돌");
		_lift_trashcan = IMG->find("7-쓰레기");
		_lift_crate = IMG->find("7-박스");
		_lift_tire = IMG->find("7-타이어");
		_lift_human = IMG->find("7-사람");
		_throw_stick_pipe = IMG->find("7-스틱던지기");
		_throw_chain = IMG->find("7-체인던지기");
		_throw_knuckles = IMG->find("7-너클던지기");
		_throw_rock = IMG->find("7-돌던지기");
		_throw_trashcan = IMG->find("7-쓰레기던지기");
		_throw_crate = IMG->find("7-박스던지기");
		_throw_tire = IMG->find("7-타이어던지기");
		_throw_human = IMG->find("7-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Harry";	//이름

			_emStatus.punch = 3;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 7;	//무기
			_emStatus.power = 3;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 5;	//가드
			_emStatus.endure = 13;	//맷집
			_emStatus.energy = 7;	//기력
			_emStatus.hp = _emStatus.maxHP = 9;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Tyler";		//이름

			_emStatus.punch = 9;	//펀치
			_emStatus.kick = 5;	//킥
			_emStatus.weapon = 8;	//무기
			_emStatus.power = 10;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 4;	//가드
			_emStatus.endure = 19;	//맷집
			_emStatus.energy = 6;	//기력
			_emStatus.hp = _emStatus.maxHP = 8;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Curt";		//이름

			_emStatus.punch = 6;	//펀치
			_emStatus.kick = 11;	//킥
			_emStatus.weapon = 11;	//무기
			_emStatus.power = 10;	//힘
			_emStatus.agility = 7;	//민첩
			_emStatus.guard = 12;	//가드
			_emStatus.endure = 16;	//맷집
			_emStatus.energy = 9;	//기력
			_emStatus.hp = _emStatus.maxHP = 12;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Peter";		//이름

			_emStatus.punch = 13;	//펀치
			_emStatus.kick = 12;	//킥
			_emStatus.weapon = 14;	//무기
			_emStatus.power = 16;	//힘
			_emStatus.agility = 10;	//민첩
			_emStatus.guard = 11;	//가드
			_emStatus.endure = 22;	//맷집
			_emStatus.energy = 13;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Max";		//이름

			_emStatus.punch = 17;	//펀치
			_emStatus.kick = 16;	//킥
			_emStatus.weapon = 15;	//무기
			_emStatus.power = 19;	//힘
			_emStatus.agility = 14;	//민첩
			_emStatus.guard = 15;	//가드
			_emStatus.endure = 21;	//맷집
			_emStatus.energy = 12;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Howie";		//이름

			_emStatus.punch = 15;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 20;	//무기
			_emStatus.power = 16;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 16;	//가드
			_emStatus.endure = 28;	//맷집
			_emStatus.energy = 13;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Andre";		//이름

			_emStatus.punch = 22;	//펀치
			_emStatus.kick = 20;	//킥
			_emStatus.weapon = 17;	//무기
			_emStatus.power = 19;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 21;	//가드
			_emStatus.endure = 26;	//맷집
			_emStatus.energy = 20;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Jed";		//이름

			_emStatus.punch = 21;	//펀치
			_emStatus.kick = 18;	//킥
			_emStatus.weapon = 25;	//무기
			_emStatus.power = 23;	//힘
			_emStatus.agility = 20;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 29;	//맷집
			_emStatus.energy = 20;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Snake";		//이름

			_emStatus.punch = 25;	//펀치
			_emStatus.kick = 25;	//킥
			_emStatus.weapon = 23;	//무기
			_emStatus.power = 21;	//힘
			_emStatus.agility = 24;	//민첩
			_emStatus.guard = 25;	//가드
			_emStatus.endure = 31;	//맷집
			_emStatus.energy = 20;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

	}
	//타입8
	if (_type == 8)
	{

		_walk = IMG->find("8-걷기");
		_run = IMG->find("8-달리기");
		_punch = IMG->find("8-펀치");
		_kick = IMG->find("8-킥");
		_uppercut = IMG->find("8-어퍼컷");
		_highkick = IMG->find("8-하이킥");
		_run_punch = IMG->find("8-달리기펀치");
		_jump = IMG->find("8-점프");
		_jumpkick = IMG->find("8-점프킥");
		_defend = IMG->find("8-방어");
		_beatup = IMG->find("8-피격");
		_ko = IMG->find("8-KO");
		_stick_pipe = IMG->find("8-스틱");
		_chain = IMG->find("8-체인");
		_knuckles = IMG->find("8-너클");
		_rock = IMG->find("8-돌");
		_lift_trashcan = IMG->find("8-쓰레기");
		_lift_crate = IMG->find("8-박스");
		_lift_tire = IMG->find("8-타이어");
		_lift_human = IMG->find("8-사람");
		_throw_stick_pipe = IMG->find("8-스틱던지기");
		_throw_chain = IMG->find("8-체인던지기");
		_throw_knuckles = IMG->find("8-너클던지기");
		_throw_rock = IMG->find("8-돌던지기");
		_throw_trashcan = IMG->find("8-쓰레기던지기");
		_throw_crate = IMG->find("8-박스던지기");
		_throw_tire = IMG->find("8-타이어던지기");
		_throw_human = IMG->find("8-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Perry";	//이름

			_emStatus.punch = 3;	//펀치
			_emStatus.kick = 6;	//킥
			_emStatus.weapon = 7;	//무기
			_emStatus.power = 2;	//힘
			_emStatus.agility = 5;	//민첩
			_emStatus.guard = 4;	//가드
			_emStatus.endure = 4;	//맷집
			_emStatus.energy = 17;	//기력
			_emStatus.hp = _emStatus.maxHP = 11;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Grant";		//이름

			_emStatus.punch = 9;	//펀치
			_emStatus.kick = 6;	//킥
			_emStatus.weapon = 8;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 3;	//가드
			_emStatus.endure = 10;	//맷집
			_emStatus.energy = 16;	//기력
			_emStatus.hp = _emStatus.maxHP = 10;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Mike";		//이름

			_emStatus.punch = 6;	//펀치
			_emStatus.kick = 12;	//킥
			_emStatus.weapon = 11;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 11;	//가드
			_emStatus.endure = 7;	//맷집
			_emStatus.energy = 19;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Bobby";		//이름

			_emStatus.punch = 13;	//펀치
			_emStatus.kick = 13;	//킥
			_emStatus.weapon = 14;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 9;	//민첩
			_emStatus.guard = 10;	//가드
			_emStatus.endure = 13;	//맷집
			_emStatus.energy = 23;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Manny";		//이름

			_emStatus.punch = 17;	//펀치
			_emStatus.kick = 17;	//킥
			_emStatus.weapon = 15;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 13;	//민첩
			_emStatus.guard = 14;	//가드
			_emStatus.endure = 12;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Waldo";		//이름

			_emStatus.punch = 15;	//펀치
			_emStatus.kick = 21;	//킥
			_emStatus.weapon = 20;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 18;	//민첩
			_emStatus.guard = 15;	//가드
			_emStatus.endure = 19;	//맷집
			_emStatus.energy = 23;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Hans";		//이름

			_emStatus.punch = 22;	//펀치
			_emStatus.kick = 21;	//킥
			_emStatus.weapon = 17;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 18;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 17;	//맷집
			_emStatus.energy = 30;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Dusty";		//이름

			_emStatus.punch = 21;	//펀치
			_emStatus.kick = 19;	//킥
			_emStatus.weapon = 25;	//무기
			_emStatus.power = 22;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 19;	//가드
			_emStatus.endure = 20;	//맷집
			_emStatus.energy = 30;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Sting";		//이름

			_emStatus.punch = 25;	//펀치
			_emStatus.kick = 26;	//킥
			_emStatus.weapon = 23;	//무기
			_emStatus.power = 20;	//힘
			_emStatus.agility = 23;	//민첩
			_emStatus.guard = 24;	//가드
			_emStatus.endure = 22;	//맷집
			_emStatus.energy = 30;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

	}
	//타입9
	if (_type == 9)
	{

		_walk = IMG->find("9-걷기");
		_run = IMG->find("9-달리기");
		_punch = IMG->find("9-펀치");
		_kick = IMG->find("9-킥");
		_uppercut = IMG->find("9-어퍼컷");
		_highkick = IMG->find("9-하이킥");
		_run_punch = IMG->find("9-달리기펀치");
		_jump = IMG->find("9-점프");
		_jumpkick = IMG->find("9-점프킥");
		_defend = IMG->find("9-방어");
		_beatup = IMG->find("9-피격");
		_ko = IMG->find("9-KO");
		_stick_pipe = IMG->find("9-스틱");
		_chain = IMG->find("9-체인");
		_knuckles = IMG->find("9-너클");
		_rock = IMG->find("9-돌");
		_lift_trashcan = IMG->find("9-쓰레기");
		_lift_crate = IMG->find("9-박스");
		_lift_tire = IMG->find("9-타이어");
		_lift_human = IMG->find("9-사람");
		_throw_stick_pipe = IMG->find("9-스틱던지기");
		_throw_chain = IMG->find("9-체인던지기");
		_throw_knuckles = IMG->find("9-너클던지기");
		_throw_rock = IMG->find("9-돌던지기");
		_throw_trashcan = IMG->find("9-쓰레기던지기");
		_throw_crate = IMG->find("9-박스던지기");
		_throw_tire = IMG->find("9-타이어던지기");
		_throw_human = IMG->find("9-사람던지기");

		_emSet.img = _run;			//이미지
		_emSet.ani = _2Rani;		//애니
		_emSet.ani->stop();			//애니 스탑

		//청록(센리다이)
		if (_color == 0)
		{
			_emSet.chName = "Ralph";	//이름

			_emStatus.punch = 3;	//펀치
			_emStatus.kick = 6;	//킥
			_emStatus.weapon = 6;	//무기
			_emStatus.power = 2;	//힘
			_emStatus.agility = 5;	//민첩
			_emStatus.guard = 4;	//가드
			_emStatus.endure = 4;	//맷집
			_emStatus.energy = 9;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 50;	//돈 드랍

		}
		//분홍(사카슈쿠)
		if (_color == 1)
		{
			_emSet.chName = "Clark";		//이름

			_emStatus.punch = 9;	//펀치
			_emStatus.kick = 6;	//킥
			_emStatus.weapon = 7;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 3;	//가드
			_emStatus.endure = 10;	//맷집
			_emStatus.energy = 8;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 55;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		}
		//연두(누마오카)
		if (_color == 2)
		{
			_emSet.chName = "Jake";		//이름

			_emStatus.punch = 6;	//펀치
			_emStatus.kick = 12;	//킥
			_emStatus.weapon = 10;	//무기
			_emStatus.power = 9;	//힘
			_emStatus.agility = 6;	//민첩
			_emStatus.guard = 11;	//가드
			_emStatus.endure = 7;	//맷집
			_emStatus.energy = 11;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 60;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		}
		//노랑(호시쿠사)
		if (_color == 3)
		{
			_emSet.chName = "Brady";		//이름

			_emStatus.punch = 13;	//펀치
			_emStatus.kick = 13;	//킥
			_emStatus.weapon = 13;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 9;	//민첩
			_emStatus.guard = 10;	//가드
			_emStatus.endure = 13;	//맷집
			_emStatus.energy = 15;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 75;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		}
		//회색(하쿠타가)
		if (_color == 4)
		{
			_emSet.chName = "Louie";		//이름

			_emStatus.punch = 17;	//펀치
			_emStatus.kick = 17;	//킥
			_emStatus.weapon = 14;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 13;	//민첩
			_emStatus.guard = 14;	//가드
			_emStatus.endure = 12;	//맷집
			_emStatus.energy = 14;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 90;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		}
		//빨강(마타가와)
		if (_color == 5)
		{
			_emSet.chName = "Linus";		//이름

			_emStatus.punch = 15;	//펀치
			_emStatus.kick = 21;	//킥
			_emStatus.weapon = 19;	//무기
			_emStatus.power = 15;	//힘
			_emStatus.agility = 18;	//민첩
			_emStatus.guard = 15;	//가드
			_emStatus.endure = 19;	//맷집
			_emStatus.energy = 15;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 100;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		}
		//초록(호료)
		if (_color == 6)
		{
			_emSet.chName = "Lars";		//이름

			_emStatus.punch = 22;	//펀치
			_emStatus.kick = 21;	//킥
			_emStatus.weapon = 16;	//무기
			_emStatus.power = 18;	//힘
			_emStatus.agility = 18;	//민첩
			_emStatus.guard = 20;	//가드
			_emStatus.endure = 17;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 120;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		}
		//남색(타니바나)
		if (_color == 7)
		{
			_emSet.chName = "Merle";		//이름

			_emStatus.punch = 21;	//펀치
			_emStatus.kick = 19;	//킥
			_emStatus.weapon = 24;	//무기
			_emStatus.power = 22;	//힘
			_emStatus.agility = 19;	//민첩
			_emStatus.guard = 19;	//가드
			_emStatus.endure = 20;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 125;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		}
		//주황(레이호)
		if (_color == 8)
		{
			_emSet.chName = "Ziggy";		//이름

			_emStatus.punch = 25;	//펀치
			_emStatus.kick = 26;	//킥
			_emStatus.weapon = 22;	//무기
			_emStatus.power = 20;	//힘
			_emStatus.agility = 23;	//민첩
			_emStatus.guard = 24;	//가드
			_emStatus.endure = 22;	//맷집
			_emStatus.energy = 22;	//기력
			_emStatus.hp = _emStatus.maxHP = 14;	//체력
			_emStatus.money = 150;	//돈 드랍

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
		}

		_emST = IDLE;	//상태

		_emState.jump = false;	//점프여부
		_left = false;	//왼쪽여부
		_emState.run = false;	//달리기 여부

		_emSet.CH = pt;				//위치
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//피격범위

	}
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
}

void enemy::render()
{
	//렌더 때 색상변경시키도록 합시다
	//애니렌더Z
	_emSet.img->aniRender(getMemDC(), pos.x - 316 / 2, pos.y - 408 / 2, _emSet.ani);
	if (_color != 0)
	{
		if (_color == 1) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//분홍 체인지
		else if (_color == 2) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//연두로 체인지
		else if (_color == 3) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//노랑으로 체인지
		else if (_color == 4) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//회색으로 체인지
		else if (_color == 5) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//빨강으로 체인지
		else if (_color == 6) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//초록으로 체인지
		else if (_color == 7) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//남색으로 체인지
		else if (_color == 8) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//주황으로 체인지
	}
}


void enemy::ani1Set()
{
	_1Rani = new animation;
	_1Rani->init(316, 408, 316, 204);
	int _1Right[] = { 0 };
	_1Rani->setPlaylist(_1Right, 1, false);
	_1Rani->setFPS(1);

	_1Lani = new animation;
	_1Lani->init(316, 408, 316, 204);
	int _1Left[] = { 1 };
	_1Lani->setPlaylist(_1Left, 1, false);
	_1Lani->setFPS(1);

}

void enemy::ani2Set()
{
	int _2Right[] = { 0,1 };
	int _2Left[] = { 3,2 };

	_2Rani = new animation;
	_2Rani->init(632, 408, 316, 204);
	_2Rani->setPlaylist(_2Right, 2, false);
	_2Rani->setFPS(1);

	_2Lani = new animation;
	_2Lani->init(632, 408, 316, 204);
	_2Lani->setPlaylist(_2Left, 2, false);
	_2Lani->setFPS(1);

	_2RaniL = new animation;
	_2RaniL->init(632, 408, 316, 204);
	_2RaniL->setPlaylist(_2Right, 2, true);
	_2RaniL->setFPS(1);

	_2LaniL = new animation;
	_2LaniL->init(632, 408, 316, 204);
	_2LaniL->setPlaylist(_2Left, 2, true);
	_2LaniL->setFPS(1);

	int _2_1Right[] = { 0 };
	int _2_1Left[] = { 3 };
	_2_1Rani = new animation;
	_2_1Rani->init(632, 408, 316, 204);
	_2_1Rani->setPlaylist(_2_1Right, 1, false);
	_2_1Rani->setFPS(1);

	_2_1Lani = new animation;
	_2_1Lani->init(632, 408, 316, 204);
	_2_1Lani->setPlaylist(_2_1Left, 1, false);
	_2_1Lani->setFPS(1);

	int _2_2Right[] = { 1 };
	int _2_2Left[] = { 2 };
	_2_2Rani = new animation;
	_2_2Rani->init(632, 408, 316, 204);
	_2_2Rani->setPlaylist(_2_2Right, 1, false);
	_2_2Rani->setFPS(1);

	_2_2Lani = new animation;
	_2_2Lani->init(632, 408, 316, 204);
	_2_2Lani->setPlaylist(_2_2Left, 1, false);
	_2_2Lani->setFPS(1);
}

void enemy::ani3Set()
{
	int _3Right[] = { 0,1,2 };
	int _3Left[] = { 5,4,3 };

	_3Rani = new animation;
	_3Rani->init(948, 408, 316, 204);
	_3Rani->setPlaylist(_3Right, 3, false);
	_3Rani->setFPS(1);

	_3Lani = new animation;
	_3Lani->init(948, 408, 316, 204);
	_3Lani->setPlaylist(_3Left, 3, false);
	_3Lani->setFPS(1);

	_3RaniL = new animation;
	_3RaniL->init(948, 408, 316, 204);
	_3RaniL->setPlaylist(_3Right, 3, true);
	_3RaniL->setFPS(1);

	_3LaniL = new animation;
	_3LaniL->init(948, 408, 316, 204);
	_3LaniL->setPlaylist(_3Left, 3, true);
	_3LaniL->setFPS(1);
}

void enemy::ani4Set()
{
	int _4Right[] = { 0,1,2,3 };
	int _4Left[] = { 7,6,5,4 };

	_4Rani = new animation;
	_4Rani->init(1264, 408, 316, 204);
	_4Rani->setPlaylist(_4Right, 4, false);
	_4Rani->setFPS(1);

	_4Lani = new animation;
	_4Lani->init(1264, 408, 316, 204);
	_4Lani->setPlaylist(_4Left, 4, false);
	_4Lani->setFPS(1);
}

void enemy::ani6Set()
{
	int _6Right[] = { 0,1,2,3,4,5 };
	int _6Left[] = { 11,10,9,8,7,6 };

	_6Rani = new animation;
	_6Rani->init(1896, 408, 316, 204);
	_6Rani->setPlaylist(_6Right, 6, false);
	_6Rani->setFPS(1);

	_6Lani = new animation;
	_6Lani->init(1896, 408, 316, 204);
	_6Lani->setPlaylist(_6Left, 6, false);
	_6Lani->setFPS(1);
}

void enemy::ani7Set()
{
	int _7Right[] = { 0,1,2,3,4,5,6 };
	int _7Left[] = { 13,12,11,10,9,8,7 };

	_7Rani = new animation;
	_7Rani->init(2212, 408, 316, 204);
	_7Rani->setPlaylist(_7Right, 7, false);
	_7Rani->setFPS(1);

	_7Lani = new animation;
	_7Lani->init(2212, 408, 316, 204);
	_7Lani->setPlaylist(_7Left, 7, false);
	_7Lani->setFPS(1);

	int _7_3L_Right[] = { 3,0 };
	int _7_3R_Left[] = { 10,13 };
	//오른쪽 볼 때 왼쪽 맞을 때
	_7_2L_Rani = new animation;
	_7_2L_Rani->init(2212, 408, 316, 204);
	_7_2L_Rani->setPlaylist(_7_3L_Right, 2, false);
	_7_2L_Rani->setFPS(1);
	//왼쪽 볼 때 오른쪽 맞을 때
	_7_2R_Lani = new animation;
	_7_2R_Lani->init(2212, 408, 316, 204);
	_7_2R_Lani->setPlaylist(_7_3R_Left, 2, false);
	_7_2R_Lani->setFPS(1);


	int _7_3R_Right[] = { 2,1,0 };
	int _7_3L_Left[] = { 11,12,13 };

	_7_3L_Lani = new animation;
	_7_3L_Lani->init(2212, 408, 316, 204);
	_7_3L_Lani->setPlaylist(_7_3L_Left, 3, false);
	_7_3L_Lani->setFPS(1);

	_7_3R_Rani = new animation;
	_7_3R_Rani->init(2212, 408, 316, 204);
	_7_3R_Rani->setPlaylist(_7_3R_Right, 3, false);
	_7_3R_Rani->setFPS(1);

	int _7_1Right[] = { 2 };
	int _7_1Left[] = { 11 };

	_7_1Lani = new animation;
	_7_1Lani->init(2212, 408, 316, 204);
	_7_1Lani->setPlaylist(_7_1Left, 1, false);
	_7_1Lani->setFPS(1);

	_7_1Rani = new animation;
	_7_1Rani->init(2212, 408, 316, 204);
	_7_1Rani->setPlaylist(_7_1Right, 1, false);
	_7_1Rani->setFPS(1);

}

void enemy::aniSwitch()
{
	switch (_emST)
	{
	case IDLE:
		if (_emState.W == 0)
		{
			_emSet.img = _run;
			if (_left)_emSet.ani = _2_1Lani;
			else if (!_left)_emSet.ani = _2_1Rani;
			_emSet.ani->stop();
		}

		break;
	case WALK:
		_emSet.img = _walk;
		if (_left)_emSet.ani = _3LaniL;
		else if (!_left)_emSet.ani = _3RaniL;
		_emSet.ani->resume();
		break;
	case RUN:
		_emSet.img = _run;
		if (_left)_emSet.ani = _2LaniL;
		else if (!_left)_emSet.ani = _2RaniL;
		_emSet.ani->resume();
		break;
	case PUNCH:
		_emSet.img = _punch;
		if (_left)_emSet.ani = _3Lani;
		else if (!_left)_emSet.ani = _3Rani;
		_emSet.ani->resume();
		//공격모션 끝나고 바로든 조금있다가든 후에 IDLE로 변환
		break;
	case KICK:
		_emSet.img = _kick;
		if (_left)_emSet.ani = _3Lani;
		else if (!_left)_emSet.ani = _3Rani;
		_emSet.ani->resume();
		//공격모션 끝나고 바로든 조금있다가든 후에 IDLE로 변환
		break;
	case ITEM_PICK:
		_emSet.img = _jump;
		if (_left)_emSet.ani = _2_2Lani;
		else if (!_left)_emSet.ani = _2_2Rani;
		_emSet.ani->stop();
		break;
	case ITEM_ATTACK:
		if (_emState.W == 1)_emSet.img = _stick_pipe;
		else if (_emState.W == 2)_emSet.img = _chain;
		else if (_emState.W == 3)_emSet.img = _knuckles;
		else if (_emState.W == 4)_emSet.img = _rock;
		else if (_emState.W == 5)_emSet.img = _lift_trashcan;
		else if (_emState.W == 6)_emSet.img = _lift_crate;
		else if (_emState.W == 7)_emSet.img = _lift_tire;
		else if (_emState.W == 8)_emSet.img = _lift_human;
		if (_left)_emSet.ani = _4Lani;
		else if (!_left)_emSet.ani = _4Rani;
		_emSet.ani->resume();
		break;
	case ITEM_THROW:
		if (_emState.W == 1)_emSet.img = _throw_stick_pipe;
		else if (_emState.W == 2)_emSet.img = _throw_chain;
		else if (_emState.W == 3)_emSet.img = _throw_knuckles;
		else if (_emState.W == 4)_emSet.img = _throw_rock;
		else if (_emState.W == 5)_emSet.img = _throw_trashcan;
		else if (_emState.W == 6)_emSet.img = _throw_crate;
		else if (_emState.W == 7)_emSet.img = _throw_tire;
		else if (_emState.W == 8)_emSet.img = _throw_human;
		if (_left)_emSet.ani = _6Lani;
		else if (!_left)_emSet.ani = _6Rani;
		_emSet.ani->resume();
		break;
	case DEFEND:
		_emSet.img = _defend;
		if (_left)_emSet.ani = _1Lani;
		else if (!_left)_emSet.ani = _1Rani;
		_emSet.ani->stop();
		break;
	case HIT:
		_emSet.img = _beatup;
		if (_left)
		{
			//마주보고 맞을 때
			_emSet.ani = _7_3L_Lani;
			//등뒤를 맞을 때
			_emSet.ani = _7_2R_Lani;
		}
		else if (!_left)
		{
			//마주보고 맞을 때
			_emSet.ani = _7_3R_Rani;
			//등뒤를 맞을 때
			_emSet.ani = _7_2L_Rani;
		}
		_emSet.ani->resume();
		break;
	case FALL:
		_emSet.img = _beatup;
		if (_left)_emSet.ani = _7_1Lani;
		if (!_left)_emSet.ani = _7_1Rani;
		_emSet.ani->stop();
		break;
	case JUMP:
		_emSet.img = _jump;
		if (_left)_emSet.ani = _7_1Lani;
		if (!_left)_emSet.ani = _7_1Rani;
		_emSet.ani->stop();
		//점프 해제시
		{
			_emSet.ani->resume();
		}
		break;
	case KO:
		_emSet.img = _ko;
		if (_left)_emSet.ani = _2Lani;
		if (!_left)_emSet.ani = _2Rani;

		_emSet.ani->resume();
		break;
	default:
		break;
	}
}

