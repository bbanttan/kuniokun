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
	_emSet.CH = pt;				//��ġ

	ani1Set();
	ani2Set();
	ani3Set();
	ani4Set();
	ani6Set();
	ani7Set();

	//����
	if (_type == 0)
	{
		_walk = IMG->find("����-�ȱ�");
		_run = IMG->find("����-�޸���");
		_punch = IMG->find("����-��ġ");
		_kick = IMG->find("����-ű");
		_uppercut = IMG->find("����-������");
		_highkick = IMG->find("����-����ű");
		_run_punch = IMG->find("����-�޸�����ġ");
		_jump = IMG->find("����-����");
		_jumpkick = IMG->find("����-����ű");
		_defend = IMG->find("����-���");
		_beatup = IMG->find("����-�ǰ�");
		_ko = IMG->find("����-KO");
		_stick_pipe = IMG->find("����-��ƽ");
		_chain = IMG->find("����-ü��");
		_knuckles = IMG->find("����-��Ŭ");
		_rock = IMG->find("����-��");
		_lift_trashcan = IMG->find("����-������");
		_lift_crate = IMG->find("����-�ڽ�");
		_lift_tire = IMG->find("����-Ÿ�̾�");
		_lift_human = IMG->find("����-���");
		_throw_stick_pipe = IMG->find("����-��ƽ������");
		_throw_chain = IMG->find("����-ü�δ�����");
		_throw_knuckles = IMG->find("����-��Ŭ������");
		_throw_rock = IMG->find("����-��������");
		_throw_trashcan = IMG->find("����-�����������");
		_throw_crate = IMG->find("����-�ڽ�������");
		_throw_tire = IMG->find("����-Ÿ�̾������");
		_throw_human = IMG->find("����-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		if (_color == 0)
		{
			_emSet.chName = "Moose";	//�̸�

			_emStatus.punch = 26;	//��ġ
			_emStatus.kick = 35;	//ű
			_emStatus.weapon = 23;	//����
			_emStatus.power = 28;	//��
			_emStatus.agility = 25;	//��ø
			_emStatus.guard = 25;	//����
			_emStatus.endure = 22;	//����
			_emStatus.energy = 24;	//���
			_emStatus.hp = _emStatus.maxHP = 52;	//ü��
			_emStatus.money = 225;	//�� ���
		}

		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

	}
	//Ÿ��1
	if (_type == 1)
	{

		_walk = IMG->find("1-�ȱ�");
		_run = IMG->find("1-�޸���");
		_punch = IMG->find("1-��ġ");
		_kick = IMG->find("1-ű");
		_uppercut = IMG->find("1-������");
		_highkick = IMG->find("1-����ű");
		_run_punch = IMG->find("1-�޸�����ġ");
		_jump = IMG->find("1-����");
		_jumpkick = IMG->find("1-����ű");
		_defend = IMG->find("1-���");
		_beatup = IMG->find("1-�ǰ�");
		_ko = IMG->find("1-KO");
		_stick_pipe = IMG->find("1-��ƽ");
		_chain = IMG->find("1-ü��");
		_knuckles = IMG->find("1-��Ŭ");
		_rock = IMG->find("1-��");
		_lift_trashcan = IMG->find("1-������");
		_lift_crate = IMG->find("1-�ڽ�");
		_lift_tire = IMG->find("1-Ÿ�̾�");
		_lift_human = IMG->find("1-���");
		_throw_stick_pipe = IMG->find("1-��ƽ������");
		_throw_chain = IMG->find("1-ü�δ�����");
		_throw_knuckles = IMG->find("1-��Ŭ������");
		_throw_rock = IMG->find("1-��������");
		_throw_trashcan = IMG->find("1-�����������");
		_throw_crate = IMG->find("1-�ڽ�������");
		_throw_tire = IMG->find("1-Ÿ�̾������");
		_throw_human = IMG->find("1-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Larry";	//�̸�

			_emStatus.punch = 12;	//��ġ
			_emStatus.kick = 4;	//ű
			_emStatus.weapon = 6;	//����
			_emStatus.power = 1;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 5;	//����
			_emStatus.endure = 5;	//����
			_emStatus.energy = 8;	//���
			_emStatus.hp = _emStatus.maxHP = 13;	//ü��
			_emStatus.money = 50;	//�� ���
		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Skip";		//�̸�

			_emStatus.punch = 18;	//��ġ
			_emStatus.kick = 4;	//ű
			_emStatus.weapon = 7;	//����
			_emStatus.power = 8;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 4;	//����
			_emStatus.endure = 11;	//����
			_emStatus.energy = 7;	//���
			_emStatus.hp = _emStatus.maxHP = 12;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Rex";		//�̸�

			_emStatus.punch = 15;	//��ġ
			_emStatus.kick = 10;	//ű
			_emStatus.weapon = 10;	//����
			_emStatus.power = 8;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 12;	//����
			_emStatus.endure = 8;	//����
			_emStatus.energy = 10;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Robby";		//�̸�

			_emStatus.punch = 22;	//��ġ
			_emStatus.kick = 11;	//ű
			_emStatus.weapon = 13;	//����
			_emStatus.power = 14;	//��
			_emStatus.agility = 10;	//��ø
			_emStatus.guard = 11;	//����
			_emStatus.endure = 14;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Lefty";		//�̸�

			_emStatus.punch = 26;	//��ġ
			_emStatus.kick = 15;	//ű
			_emStatus.weapon = 14;	//����
			_emStatus.power = 17;	//��
			_emStatus.agility = 14;	//��ø
			_emStatus.guard = 15;	//����
			_emStatus.endure = 13;	//����
			_emStatus.energy = 13;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Herb";		//�̸�

			_emStatus.punch = 24;	//��ġ
			_emStatus.kick = 19;	//ű
			_emStatus.weapon = 19;	//����
			_emStatus.power = 14;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 16;	//����
			_emStatus.endure = 20;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Boris";		//�̸�

			_emStatus.punch = 31;	//��ġ
			_emStatus.kick = 19;	//ű
			_emStatus.weapon = 16;	//����
			_emStatus.power = 17;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 21;	//����
			_emStatus.endure = 18;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Bubba";		//�̸�

			_emStatus.punch = 30;	//��ġ
			_emStatus.kick = 17;	//ű
			_emStatus.weapon = 24;	//����
			_emStatus.power = 21;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 21;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Slash";		//�̸�

			_emStatus.punch = 34;	//��ġ
			_emStatus.kick = 24;	//ű
			_emStatus.weapon = 22;	//����
			_emStatus.power = 19;	//��
			_emStatus.agility = 24;	//��ø
			_emStatus.guard = 25;	//����
			_emStatus.endure = 23;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���
	}
	//Ÿ��2
	if (_type == 2)
	{
		_walk = IMG->find("2-�ȱ�");
		_run = IMG->find("2-�޸���");
		_punch = IMG->find("2-��ġ");
		_kick = IMG->find("2-ű");
		_uppercut = IMG->find("2-������");
		_highkick = IMG->find("2-����ű");
		_run_punch = IMG->find("2-�޸�����ġ");
		_jump = IMG->find("2-����");
		_jumpkick = IMG->find("2-����ű");
		_defend = IMG->find("2-���");
		_beatup = IMG->find("2-�ǰ�");
		_ko = IMG->find("2-KO");
		_stick_pipe = IMG->find("2-��ƽ");
		_chain = IMG->find("2-ü��");
		_knuckles = IMG->find("2-��Ŭ");
		_rock = IMG->find("2-��");
		_lift_trashcan = IMG->find("2-������");
		_lift_crate = IMG->find("2-�ڽ�");
		_lift_tire = IMG->find("2-Ÿ�̾�");
		_lift_human = IMG->find("2-���");
		_throw_stick_pipe = IMG->find("2-��ƽ������");
		_throw_chain = IMG->find("2-ü�δ�����");
		_throw_knuckles = IMG->find("2-��Ŭ������");
		_throw_rock = IMG->find("2-��������");
		_throw_trashcan = IMG->find("2-�����������");
		_throw_crate = IMG->find("2-�ڽ�������");
		_throw_tire = IMG->find("2-Ÿ�̾������");
		_throw_human = IMG->find("2-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Barry";	//�̸�

			_emStatus.punch = 2;	//��ġ
			_emStatus.kick = 14;	//ű
			_emStatus.weapon = 5;	//����
			_emStatus.power = 2;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 5;	//����
			_emStatus.endure = 4;	//����
			_emStatus.energy = 9;	//���
			_emStatus.hp = _emStatus.maxHP = 11;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Trent";		//�̸�

			_emStatus.punch = 8;	//��ġ
			_emStatus.kick = 14;	//ű
			_emStatus.weapon = 6;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 8;	//��ø
			_emStatus.guard = 4;	//����
			_emStatus.endure = 10;	//����
			_emStatus.energy = 8;	//���
			_emStatus.hp = _emStatus.maxHP = 10;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Lance";		//�̸�

			_emStatus.punch = 5;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 9;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 8;	//��ø
			_emStatus.guard = 12;	//����
			_emStatus.endure = 7;	//����
			_emStatus.energy = 11;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Chip";		//�̸�

			_emStatus.punch = 12;	//��ġ
			_emStatus.kick = 21;	//ű
			_emStatus.weapon = 12;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 11;	//��ø
			_emStatus.guard = 11;	//����
			_emStatus.endure = 13;	//����
			_emStatus.energy = 15;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Sid";		//�̸�

			_emStatus.punch = 16;	//��ġ
			_emStatus.kick = 25;	//ű
			_emStatus.weapon = 13;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 15;	//��ø
			_emStatus.guard = 15;	//����
			_emStatus.endure = 12;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Erwin";		//�̸�

			_emStatus.punch = 14;	//��ġ
			_emStatus.kick = 29;	//ű
			_emStatus.weapon = 18;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 16;	//����
			_emStatus.endure = 19;	//����
			_emStatus.energy = 15;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Yemi";		//�̸�

			_emStatus.punch = 21;	//��ġ
			_emStatus.kick = 29;	//ű
			_emStatus.weapon = 15;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 21;	//����
			_emStatus.endure = 17;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Shane";		//�̸�

			_emStatus.punch = 20;	//��ġ
			_emStatus.kick = 27;	//ű
			_emStatus.weapon = 23;	//����
			_emStatus.power = 22;	//��
			_emStatus.agility = 21;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 20;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Edge";		//�̸�

			_emStatus.punch = 24;	//��ġ
			_emStatus.kick = 34;	//ű
			_emStatus.weapon = 21;	//����
			_emStatus.power = 20;	//��
			_emStatus.agility = 25;	//��ø
			_emStatus.guard = 25;	//����
			_emStatus.endure = 22;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

	}
	//Ÿ��3
	if (_type == 3)
	{

		_walk = IMG->find("3-�ȱ�");
		_run = IMG->find("3-�޸���");
		_punch = IMG->find("3-��ġ");
		_kick = IMG->find("3-ű");
		_uppercut = IMG->find("3-������");
		_highkick = IMG->find("3-����ű");
		_run_punch = IMG->find("3-�޸�����ġ");
		_jump = IMG->find("3-����");
		_jumpkick = IMG->find("3-����ű");
		_defend = IMG->find("3-���");
		_beatup = IMG->find("3-�ǰ�");
		_ko = IMG->find("3-KO");
		_stick_pipe = IMG->find("3-��ƽ");
		_chain = IMG->find("3-ü��");
		_knuckles = IMG->find("3-��Ŭ");
		_rock = IMG->find("3-��");
		_lift_trashcan = IMG->find("3-������");
		_lift_crate = IMG->find("3-�ڽ�");
		_lift_tire = IMG->find("3-Ÿ�̾�");
		_lift_human = IMG->find("3-���");
		_throw_stick_pipe = IMG->find("3-��ƽ������");
		_throw_chain = IMG->find("3-ü�δ�����");
		_throw_knuckles = IMG->find("3-��Ŭ������");
		_throw_rock = IMG->find("3-��������");
		_throw_trashcan = IMG->find("3-�����������");
		_throw_crate = IMG->find("3-�ڽ�������");
		_throw_tire = IMG->find("3-Ÿ�̾������");
		_throw_human = IMG->find("3-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Terry";	//�̸�

			_emStatus.punch = 3;	//��ġ
			_emStatus.kick = 4;	//ű
			_emStatus.weapon = 15;	//����
			_emStatus.power = 1;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 5;	//����
			_emStatus.endure = 4;	//����
			_emStatus.energy = 9;	//���
			_emStatus.hp = _emStatus.maxHP = 11;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Logan";		//�̸�

			_emStatus.punch = 9;	//��ġ
			_emStatus.kick = 4;	//ű
			_emStatus.weapon = 16;	//����
			_emStatus.power = 8;	//��
			_emStatus.agility = 8;	//��ø
			_emStatus.guard = 4;	//����
			_emStatus.endure = 10;	//����
			_emStatus.energy = 8;	//���
			_emStatus.hp = _emStatus.maxHP = 10;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Dirk";		//�̸�

			_emStatus.punch = 6;	//��ġ
			_emStatus.kick = 10;	//ű
			_emStatus.weapon = 19;	//����
			_emStatus.power = 8;	//��
			_emStatus.agility = 8;	//��ø
			_emStatus.guard = 12;	//����
			_emStatus.endure = 7;	//����
			_emStatus.energy = 11;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Ernie";		//�̸�

			_emStatus.punch = 13;	//��ġ
			_emStatus.kick = 11;	//ű
			_emStatus.weapon = 22;	//����
			_emStatus.power = 14;	//��
			_emStatus.agility = 11;	//��ø
			_emStatus.guard = 11;	//����
			_emStatus.endure = 13;	//����
			_emStatus.energy = 15;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Tony";		//�̸�

			_emStatus.punch = 17;	//��ġ
			_emStatus.kick = 15;	//ű
			_emStatus.weapon = 23;	//����
			_emStatus.power = 17;	//��
			_emStatus.agility = 15;	//��ø
			_emStatus.guard = 15;	//����
			_emStatus.endure = 12;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Felix";		//�̸�

			_emStatus.punch = 15;	//��ġ
			_emStatus.kick = 19;	//ű
			_emStatus.weapon = 28;	//����
			_emStatus.power = 14;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 16;	//����
			_emStatus.endure = 19;	//����
			_emStatus.energy = 15;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Fuji";		//�̸�

			_emStatus.punch = 22;	//��ġ
			_emStatus.kick = 19;	//ű
			_emStatus.weapon = 25;	//����
			_emStatus.power = 17;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 21;	//����
			_emStatus.endure = 17;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Bart";		//�̸�

			_emStatus.punch = 21;	//��ġ
			_emStatus.kick = 17;	//ű
			_emStatus.weapon = 33;	//����
			_emStatus.power = 21;	//��
			_emStatus.agility = 21;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 20;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Blaze";		//�̸�

			_emStatus.punch = 25;	//��ġ
			_emStatus.kick = 24;	//ű
			_emStatus.weapon = 31;	//����
			_emStatus.power = 19;	//��
			_emStatus.agility = 25;	//��ø
			_emStatus.guard = 25;	//����
			_emStatus.endure = 22;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���
	}
	//Ÿ��4
	if (_type == 4)
	{

		_walk = IMG->find("4-�ȱ�");
		_run = IMG->find("4-�޸���");
		_punch = IMG->find("4-��ġ");
		_kick = IMG->find("4-ű");
		_uppercut = IMG->find("4-������");
		_highkick = IMG->find("4-����ű");
		_run_punch = IMG->find("4-�޸�����ġ");
		_jump = IMG->find("4-����");
		_jumpkick = IMG->find("4-����ű");
		_defend = IMG->find("4-���");
		_beatup = IMG->find("4-�ǰ�");
		_ko = IMG->find("4-KO");
		_stick_pipe = IMG->find("4-��ƽ");
		_chain = IMG->find("4-ü��");
		_knuckles = IMG->find("4-��Ŭ");
		_rock = IMG->find("4-��");
		_lift_trashcan = IMG->find("4-������");
		_lift_crate = IMG->find("4-�ڽ�");
		_lift_tire = IMG->find("4-Ÿ�̾�");
		_lift_human = IMG->find("4-���");
		_throw_stick_pipe = IMG->find("4-��ƽ������");
		_throw_chain = IMG->find("4-ü�δ�����");
		_throw_knuckles = IMG->find("4-��Ŭ������");
		_throw_rock = IMG->find("4-��������");
		_throw_trashcan = IMG->find("4-�����������");
		_throw_crate = IMG->find("4-�ڽ�������");
		_throw_tire = IMG->find("4-Ÿ�̾������");
		_throw_human = IMG->find("4-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Jerry";	//�̸�

			_emStatus.punch = 2;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 5;	//����
			_emStatus.power = 11;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 5;	//����
			_emStatus.endure = 5;	//����
			_emStatus.energy = 8;	//���
			_emStatus.hp = _emStatus.maxHP = 13;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Biff";		//�̸�

			_emStatus.punch = 8;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 6;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 4;	//����
			_emStatus.endure = 11;	//����
			_emStatus.energy = 7;	//���
			_emStatus.hp = _emStatus.maxHP = 12;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Nick";		//�̸�

			_emStatus.punch = 5;	//��ġ
			_emStatus.kick = 11;	//ű
			_emStatus.weapon = 9;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 12;	//����
			_emStatus.endure = 8;	//����
			_emStatus.energy = 10;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Steve";		//�̸�

			_emStatus.punch = 12;	//��ġ
			_emStatus.kick = 12;	//ű
			_emStatus.weapon = 12;	//����
			_emStatus.power = 24;	//��
			_emStatus.agility = 10;	//��ø
			_emStatus.guard = 11;	//����
			_emStatus.endure = 14;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Marco";		//�̸�

			_emStatus.punch = 16;	//��ġ
			_emStatus.kick = 16;	//ű
			_emStatus.weapon = 13;	//����
			_emStatus.power = 27;	//��
			_emStatus.agility = 14;	//��ø
			_emStatus.guard = 15;	//����
			_emStatus.endure = 13;	//����
			_emStatus.energy = 13;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Morty";		//�̸�

			_emStatus.punch = 14;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 18;	//����
			_emStatus.power = 24;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 16;	//����
			_emStatus.endure = 20;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Wang";		//�̸�

			_emStatus.punch = 21;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 15;	//����
			_emStatus.power = 27;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 21;	//����
			_emStatus.endure = 18;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Luke";		//�̸�

			_emStatus.punch = 20;	//��ġ
			_emStatus.kick = 18;	//ű
			_emStatus.weapon = 23;	//����
			_emStatus.power = 31;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 21;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Tonto";		//�̸�

			_emStatus.punch = 24;	//��ġ
			_emStatus.kick = 25;	//ű
			_emStatus.weapon = 21;	//����
			_emStatus.power = 29;	//��
			_emStatus.agility = 24;	//��ø
			_emStatus.guard = 25;	//����
			_emStatus.endure = 23;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

	}
	//Ÿ��5
	if (_type == 5)
	{

		_walk = IMG->find("5-�ȱ�");
		_run = IMG->find("5-�޸���");
		_punch = IMG->find("5-��ġ");
		_kick = IMG->find("5-ű");
		_uppercut = IMG->find("5-������");
		_highkick = IMG->find("5-����ű");
		_run_punch = IMG->find("5-�޸�����ġ");
		_jump = IMG->find("5-����");
		_jumpkick = IMG->find("5-����ű");
		_defend = IMG->find("5-���");
		_beatup = IMG->find("5-�ǰ�");
		_ko = IMG->find("5-KO");
		_stick_pipe = IMG->find("5-��ƽ");
		_chain = IMG->find("5-ü��");
		_knuckles = IMG->find("5-��Ŭ");
		_rock = IMG->find("5-��");
		_lift_trashcan = IMG->find("5-������");
		_lift_crate = IMG->find("5-�ڽ�");
		_lift_tire = IMG->find("5-Ÿ�̾�");
		_lift_human = IMG->find("5-���");
		_throw_stick_pipe = IMG->find("5-��ƽ������");
		_throw_chain = IMG->find("5-ü�δ�����");
		_throw_knuckles = IMG->find("5-��Ŭ������");
		_throw_rock = IMG->find("5-��������");
		_throw_trashcan = IMG->find("5-�����������");
		_throw_crate = IMG->find("5-�ڽ�������");
		_throw_tire = IMG->find("5-Ÿ�̾������");
		_throw_human = IMG->find("5-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Cary";	//�̸�

			_emStatus.punch = 4;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 6;	//����
			_emStatus.power = 2;	//��
			_emStatus.agility = 15;	//��ø
			_emStatus.guard = 6;	//����
			_emStatus.endure = 3;	//����
			_emStatus.energy = 8;	//���
			_emStatus.hp = _emStatus.maxHP = 9;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Drake";		//�̸�

			_emStatus.punch = 10;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 7;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 16;	//��ø
			_emStatus.guard = 5;	//����
			_emStatus.endure = 9;	//����
			_emStatus.energy = 7;	//���
			_emStatus.hp = _emStatus.maxHP = 8;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Brad";		//�̸�

			_emStatus.punch = 7;	//��ġ
			_emStatus.kick = 11;	//ű
			_emStatus.weapon = 10;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 16;	//��ø
			_emStatus.guard = 13;	//����
			_emStatus.endure = 6;	//����
			_emStatus.energy = 10;	//���
			_emStatus.hp = _emStatus.maxHP = 12;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Doug";		//�̸�

			_emStatus.punch = 14;	//��ġ
			_emStatus.kick = 12;	//ű
			_emStatus.weapon = 13;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 12;	//����
			_emStatus.endure = 12;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Vinny";		//�̸�

			_emStatus.punch = 18;	//��ġ
			_emStatus.kick = 16;	//ű
			_emStatus.weapon = 14;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 23;	//��ø
			_emStatus.guard = 16;	//����
			_emStatus.endure = 11;	//����
			_emStatus.energy = 13;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Berni";		//�̸�

			_emStatus.punch = 16;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 19;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 28;	//��ø
			_emStatus.guard = 17;	//����
			_emStatus.endure = 18;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Akbar";		//�̸�

			_emStatus.punch = 23;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 16;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 28;	//��ø
			_emStatus.guard = 22;	//����
			_emStatus.endure = 16;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Duke";		//�̸�

			_emStatus.punch = 22;	//��ġ
			_emStatus.kick = 18;	//ű
			_emStatus.weapon = 24;	//����
			_emStatus.power = 22;	//��
			_emStatus.agility = 29;	//��ø
			_emStatus.guard = 21;	//����
			_emStatus.endure = 19;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Stick";		//�̸�

			_emStatus.punch = 26;	//��ġ
			_emStatus.kick = 25;	//ű
			_emStatus.weapon = 22;	//����
			_emStatus.power = 20;	//��
			_emStatus.agility = 33;	//��ø
			_emStatus.guard = 26;	//����
			_emStatus.endure = 21;	//����
			_emStatus.energy = 21;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

	}
	//Ÿ��6
	if (_type == 6)
	{

		_walk = IMG->find("6-�ȱ�");
		_run = IMG->find("6-�޸���");
		_punch = IMG->find("6-��ġ");
		_kick = IMG->find("6-ű");
		_uppercut = IMG->find("6-������");
		_highkick = IMG->find("6-����ű");
		_run_punch = IMG->find("6-�޸�����ġ");
		_jump = IMG->find("6-����");
		_jumpkick = IMG->find("6-����ű");
		_defend = IMG->find("6-���");
		_beatup = IMG->find("6-�ǰ�");
		_ko = IMG->find("6-KO");
		_stick_pipe = IMG->find("6-��ƽ");
		_chain = IMG->find("6-ü��");
		_knuckles = IMG->find("6-��Ŭ");
		_rock = IMG->find("6-��");
		_lift_trashcan = IMG->find("6-������");
		_lift_crate = IMG->find("6-�ڽ�");
		_lift_tire = IMG->find("6-Ÿ�̾�");
		_lift_human = IMG->find("6-���");
		_throw_stick_pipe = IMG->find("6-��ƽ������");
		_throw_chain = IMG->find("6-ü�δ�����");
		_throw_knuckles = IMG->find("6-��Ŭ������");
		_throw_rock = IMG->find("6-��������");
		_throw_trashcan = IMG->find("6-�����������");
		_throw_crate = IMG->find("6-�ڽ�������");
		_throw_tire = IMG->find("6-Ÿ�̾������");
		_throw_human = IMG->find("6-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Gary";	//�̸�

			_emStatus.punch = 4;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 6;	//����
			_emStatus.power = 3;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 14;	//����
			_emStatus.endure = 3;	//����
			_emStatus.energy = 7;	//���
			_emStatus.hp = _emStatus.maxHP = 11;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Trip";		//�̸�

			_emStatus.punch = 10;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 7;	//����
			_emStatus.power = 10;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 13;	//����
			_emStatus.endure = 9;	//����
			_emStatus.energy = 6;	//���
			_emStatus.hp = _emStatus.maxHP = 10;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Matt";		//�̸�

			_emStatus.punch = 7;	//��ġ
			_emStatus.kick = 11;	//ű
			_emStatus.weapon = 10;	//����
			_emStatus.power = 10;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 21;	//����
			_emStatus.endure = 6;	//����
			_emStatus.energy = 9;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Greg";		//�̸�

			_emStatus.punch = 14;	//��ġ
			_emStatus.kick = 12;	//ű
			_emStatus.weapon = 13;	//����
			_emStatus.power = 16;	//��
			_emStatus.agility = 10;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 12;	//����
			_emStatus.energy = 13;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Mouse";		//�̸�

			_emStatus.punch = 18;	//��ġ
			_emStatus.kick = 16;	//ű
			_emStatus.weapon = 14;	//����
			_emStatus.power = 19;	//��
			_emStatus.agility = 14;	//��ø
			_emStatus.guard = 24;	//����
			_emStatus.endure = 11;	//����
			_emStatus.energy = 12;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Byron";		//�̸�

			_emStatus.punch = 16;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 19;	//����
			_emStatus.power = 16;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 25;	//����
			_emStatus.endure = 18;	//����
			_emStatus.energy = 13;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Juan";		//�̸�

			_emStatus.punch = 23;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 16;	//����
			_emStatus.power = 19;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 30;	//����
			_emStatus.endure = 16;	//����
			_emStatus.energy = 20;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Slim";		//�̸�

			_emStatus.punch = 22;	//��ġ
			_emStatus.kick = 18;	//ű
			_emStatus.weapon = 24;	//����
			_emStatus.power = 23;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 29;	//����
			_emStatus.endure = 19;	//����
			_emStatus.energy = 20;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Mooky";		//�̸�

			_emStatus.punch = 26;	//��ġ
			_emStatus.kick = 25;	//ű
			_emStatus.weapon = 22;	//����
			_emStatus.power = 21;	//��
			_emStatus.agility = 24;	//��ø
			_emStatus.guard = 34;	//����
			_emStatus.endure = 21;	//����
			_emStatus.energy = 20;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

	}
	//Ÿ��7
	if (_type == 7)
	{

		_walk = IMG->find("7-�ȱ�");
		_run = IMG->find("7-�޸���");
		_punch = IMG->find("7-��ġ");
		_kick = IMG->find("7-ű");
		_uppercut = IMG->find("7-������");
		_highkick = IMG->find("7-����ű");
		_run_punch = IMG->find("7-�޸�����ġ");
		_jump = IMG->find("7-����");
		_jumpkick = IMG->find("7-����ű");
		_defend = IMG->find("7-���");
		_beatup = IMG->find("7-�ǰ�");
		_ko = IMG->find("7-KO");
		_stick_pipe = IMG->find("7-��ƽ");
		_chain = IMG->find("7-ü��");
		_knuckles = IMG->find("7-��Ŭ");
		_rock = IMG->find("7-��");
		_lift_trashcan = IMG->find("7-������");
		_lift_crate = IMG->find("7-�ڽ�");
		_lift_tire = IMG->find("7-Ÿ�̾�");
		_lift_human = IMG->find("7-���");
		_throw_stick_pipe = IMG->find("7-��ƽ������");
		_throw_chain = IMG->find("7-ü�δ�����");
		_throw_knuckles = IMG->find("7-��Ŭ������");
		_throw_rock = IMG->find("7-��������");
		_throw_trashcan = IMG->find("7-�����������");
		_throw_crate = IMG->find("7-�ڽ�������");
		_throw_tire = IMG->find("7-Ÿ�̾������");
		_throw_human = IMG->find("7-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Harry";	//�̸�

			_emStatus.punch = 3;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 7;	//����
			_emStatus.power = 3;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 5;	//����
			_emStatus.endure = 13;	//����
			_emStatus.energy = 7;	//���
			_emStatus.hp = _emStatus.maxHP = 9;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Tyler";		//�̸�

			_emStatus.punch = 9;	//��ġ
			_emStatus.kick = 5;	//ű
			_emStatus.weapon = 8;	//����
			_emStatus.power = 10;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 4;	//����
			_emStatus.endure = 19;	//����
			_emStatus.energy = 6;	//���
			_emStatus.hp = _emStatus.maxHP = 8;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Curt";		//�̸�

			_emStatus.punch = 6;	//��ġ
			_emStatus.kick = 11;	//ű
			_emStatus.weapon = 11;	//����
			_emStatus.power = 10;	//��
			_emStatus.agility = 7;	//��ø
			_emStatus.guard = 12;	//����
			_emStatus.endure = 16;	//����
			_emStatus.energy = 9;	//���
			_emStatus.hp = _emStatus.maxHP = 12;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Peter";		//�̸�

			_emStatus.punch = 13;	//��ġ
			_emStatus.kick = 12;	//ű
			_emStatus.weapon = 14;	//����
			_emStatus.power = 16;	//��
			_emStatus.agility = 10;	//��ø
			_emStatus.guard = 11;	//����
			_emStatus.endure = 22;	//����
			_emStatus.energy = 13;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Max";		//�̸�

			_emStatus.punch = 17;	//��ġ
			_emStatus.kick = 16;	//ű
			_emStatus.weapon = 15;	//����
			_emStatus.power = 19;	//��
			_emStatus.agility = 14;	//��ø
			_emStatus.guard = 15;	//����
			_emStatus.endure = 21;	//����
			_emStatus.energy = 12;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Howie";		//�̸�

			_emStatus.punch = 15;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 20;	//����
			_emStatus.power = 16;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 16;	//����
			_emStatus.endure = 28;	//����
			_emStatus.energy = 13;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Andre";		//�̸�

			_emStatus.punch = 22;	//��ġ
			_emStatus.kick = 20;	//ű
			_emStatus.weapon = 17;	//����
			_emStatus.power = 19;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 21;	//����
			_emStatus.endure = 26;	//����
			_emStatus.energy = 20;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Jed";		//�̸�

			_emStatus.punch = 21;	//��ġ
			_emStatus.kick = 18;	//ű
			_emStatus.weapon = 25;	//����
			_emStatus.power = 23;	//��
			_emStatus.agility = 20;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 29;	//����
			_emStatus.energy = 20;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Snake";		//�̸�

			_emStatus.punch = 25;	//��ġ
			_emStatus.kick = 25;	//ű
			_emStatus.weapon = 23;	//����
			_emStatus.power = 21;	//��
			_emStatus.agility = 24;	//��ø
			_emStatus.guard = 25;	//����
			_emStatus.endure = 31;	//����
			_emStatus.energy = 20;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

	}
	//Ÿ��8
	if (_type == 8)
	{

		_walk = IMG->find("8-�ȱ�");
		_run = IMG->find("8-�޸���");
		_punch = IMG->find("8-��ġ");
		_kick = IMG->find("8-ű");
		_uppercut = IMG->find("8-������");
		_highkick = IMG->find("8-����ű");
		_run_punch = IMG->find("8-�޸�����ġ");
		_jump = IMG->find("8-����");
		_jumpkick = IMG->find("8-����ű");
		_defend = IMG->find("8-���");
		_beatup = IMG->find("8-�ǰ�");
		_ko = IMG->find("8-KO");
		_stick_pipe = IMG->find("8-��ƽ");
		_chain = IMG->find("8-ü��");
		_knuckles = IMG->find("8-��Ŭ");
		_rock = IMG->find("8-��");
		_lift_trashcan = IMG->find("8-������");
		_lift_crate = IMG->find("8-�ڽ�");
		_lift_tire = IMG->find("8-Ÿ�̾�");
		_lift_human = IMG->find("8-���");
		_throw_stick_pipe = IMG->find("8-��ƽ������");
		_throw_chain = IMG->find("8-ü�δ�����");
		_throw_knuckles = IMG->find("8-��Ŭ������");
		_throw_rock = IMG->find("8-��������");
		_throw_trashcan = IMG->find("8-�����������");
		_throw_crate = IMG->find("8-�ڽ�������");
		_throw_tire = IMG->find("8-Ÿ�̾������");
		_throw_human = IMG->find("8-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Perry";	//�̸�

			_emStatus.punch = 3;	//��ġ
			_emStatus.kick = 6;	//ű
			_emStatus.weapon = 7;	//����
			_emStatus.power = 2;	//��
			_emStatus.agility = 5;	//��ø
			_emStatus.guard = 4;	//����
			_emStatus.endure = 4;	//����
			_emStatus.energy = 17;	//���
			_emStatus.hp = _emStatus.maxHP = 11;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Grant";		//�̸�

			_emStatus.punch = 9;	//��ġ
			_emStatus.kick = 6;	//ű
			_emStatus.weapon = 8;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 3;	//����
			_emStatus.endure = 10;	//����
			_emStatus.energy = 16;	//���
			_emStatus.hp = _emStatus.maxHP = 10;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Mike";		//�̸�

			_emStatus.punch = 6;	//��ġ
			_emStatus.kick = 12;	//ű
			_emStatus.weapon = 11;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 11;	//����
			_emStatus.endure = 7;	//����
			_emStatus.energy = 19;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Bobby";		//�̸�

			_emStatus.punch = 13;	//��ġ
			_emStatus.kick = 13;	//ű
			_emStatus.weapon = 14;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 9;	//��ø
			_emStatus.guard = 10;	//����
			_emStatus.endure = 13;	//����
			_emStatus.energy = 23;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Manny";		//�̸�

			_emStatus.punch = 17;	//��ġ
			_emStatus.kick = 17;	//ű
			_emStatus.weapon = 15;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 13;	//��ø
			_emStatus.guard = 14;	//����
			_emStatus.endure = 12;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Waldo";		//�̸�

			_emStatus.punch = 15;	//��ġ
			_emStatus.kick = 21;	//ű
			_emStatus.weapon = 20;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 18;	//��ø
			_emStatus.guard = 15;	//����
			_emStatus.endure = 19;	//����
			_emStatus.energy = 23;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Hans";		//�̸�

			_emStatus.punch = 22;	//��ġ
			_emStatus.kick = 21;	//ű
			_emStatus.weapon = 17;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 18;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 17;	//����
			_emStatus.energy = 30;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Dusty";		//�̸�

			_emStatus.punch = 21;	//��ġ
			_emStatus.kick = 19;	//ű
			_emStatus.weapon = 25;	//����
			_emStatus.power = 22;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 19;	//����
			_emStatus.endure = 20;	//����
			_emStatus.energy = 30;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Sting";		//�̸�

			_emStatus.punch = 25;	//��ġ
			_emStatus.kick = 26;	//ű
			_emStatus.weapon = 23;	//����
			_emStatus.power = 20;	//��
			_emStatus.agility = 23;	//��ø
			_emStatus.guard = 24;	//����
			_emStatus.endure = 22;	//����
			_emStatus.energy = 30;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

	}
	//Ÿ��9
	if (_type == 9)
	{

		_walk = IMG->find("9-�ȱ�");
		_run = IMG->find("9-�޸���");
		_punch = IMG->find("9-��ġ");
		_kick = IMG->find("9-ű");
		_uppercut = IMG->find("9-������");
		_highkick = IMG->find("9-����ű");
		_run_punch = IMG->find("9-�޸�����ġ");
		_jump = IMG->find("9-����");
		_jumpkick = IMG->find("9-����ű");
		_defend = IMG->find("9-���");
		_beatup = IMG->find("9-�ǰ�");
		_ko = IMG->find("9-KO");
		_stick_pipe = IMG->find("9-��ƽ");
		_chain = IMG->find("9-ü��");
		_knuckles = IMG->find("9-��Ŭ");
		_rock = IMG->find("9-��");
		_lift_trashcan = IMG->find("9-������");
		_lift_crate = IMG->find("9-�ڽ�");
		_lift_tire = IMG->find("9-Ÿ�̾�");
		_lift_human = IMG->find("9-���");
		_throw_stick_pipe = IMG->find("9-��ƽ������");
		_throw_chain = IMG->find("9-ü�δ�����");
		_throw_knuckles = IMG->find("9-��Ŭ������");
		_throw_rock = IMG->find("9-��������");
		_throw_trashcan = IMG->find("9-�����������");
		_throw_crate = IMG->find("9-�ڽ�������");
		_throw_tire = IMG->find("9-Ÿ�̾������");
		_throw_human = IMG->find("9-���������");

		_emSet.img = _run;			//�̹���
		_emSet.ani = _2Rani;		//�ִ�
		_emSet.ani->stop();			//�ִ� ��ž

		//û��(��������)
		if (_color == 0)
		{
			_emSet.chName = "Ralph";	//�̸�

			_emStatus.punch = 3;	//��ġ
			_emStatus.kick = 6;	//ű
			_emStatus.weapon = 6;	//����
			_emStatus.power = 2;	//��
			_emStatus.agility = 5;	//��ø
			_emStatus.guard = 4;	//����
			_emStatus.endure = 4;	//����
			_emStatus.energy = 9;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 50;	//�� ���

		}
		//��ȫ(��ī����)
		if (_color == 1)
		{
			_emSet.chName = "Clark";		//�̸�

			_emStatus.punch = 9;	//��ġ
			_emStatus.kick = 6;	//ű
			_emStatus.weapon = 7;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 3;	//����
			_emStatus.endure = 10;	//����
			_emStatus.energy = 8;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 55;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		}
		//����(������ī)
		if (_color == 2)
		{
			_emSet.chName = "Jake";		//�̸�

			_emStatus.punch = 6;	//��ġ
			_emStatus.kick = 12;	//ű
			_emStatus.weapon = 10;	//����
			_emStatus.power = 9;	//��
			_emStatus.agility = 6;	//��ø
			_emStatus.guard = 11;	//����
			_emStatus.endure = 7;	//����
			_emStatus.energy = 11;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 60;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		}
		//���(ȣ�����)
		if (_color == 3)
		{
			_emSet.chName = "Brady";		//�̸�

			_emStatus.punch = 13;	//��ġ
			_emStatus.kick = 13;	//ű
			_emStatus.weapon = 13;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 9;	//��ø
			_emStatus.guard = 10;	//����
			_emStatus.endure = 13;	//����
			_emStatus.energy = 15;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 75;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		}
		//ȸ��(����Ÿ��)
		if (_color == 4)
		{
			_emSet.chName = "Louie";		//�̸�

			_emStatus.punch = 17;	//��ġ
			_emStatus.kick = 17;	//ű
			_emStatus.weapon = 14;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 13;	//��ø
			_emStatus.guard = 14;	//����
			_emStatus.endure = 12;	//����
			_emStatus.energy = 14;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 90;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		}
		//����(��Ÿ����)
		if (_color == 5)
		{
			_emSet.chName = "Linus";		//�̸�

			_emStatus.punch = 15;	//��ġ
			_emStatus.kick = 21;	//ű
			_emStatus.weapon = 19;	//����
			_emStatus.power = 15;	//��
			_emStatus.agility = 18;	//��ø
			_emStatus.guard = 15;	//����
			_emStatus.endure = 19;	//����
			_emStatus.energy = 15;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 100;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		}
		//�ʷ�(ȣ��)
		if (_color == 6)
		{
			_emSet.chName = "Lars";		//�̸�

			_emStatus.punch = 22;	//��ġ
			_emStatus.kick = 21;	//ű
			_emStatus.weapon = 16;	//����
			_emStatus.power = 18;	//��
			_emStatus.agility = 18;	//��ø
			_emStatus.guard = 20;	//����
			_emStatus.endure = 17;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 120;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		}
		//����(Ÿ�Ϲٳ�)
		if (_color == 7)
		{
			_emSet.chName = "Merle";		//�̸�

			_emStatus.punch = 21;	//��ġ
			_emStatus.kick = 19;	//ű
			_emStatus.weapon = 24;	//����
			_emStatus.power = 22;	//��
			_emStatus.agility = 19;	//��ø
			_emStatus.guard = 19;	//����
			_emStatus.endure = 20;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 125;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		}
		//��Ȳ(����ȣ)
		if (_color == 8)
		{
			_emSet.chName = "Ziggy";		//�̸�

			_emStatus.punch = 25;	//��ġ
			_emStatus.kick = 26;	//ű
			_emStatus.weapon = 22;	//����
			_emStatus.power = 20;	//��
			_emStatus.agility = 23;	//��ø
			_emStatus.guard = 24;	//����
			_emStatus.endure = 22;	//����
			_emStatus.energy = 22;	//���
			_emStatus.hp = _emStatus.maxHP = 14;	//ü��
			_emStatus.money = 150;	//�� ���

			//_emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
		}

		_emST = IDLE;	//����

		_emState.jump = false;	//��������
		_left = false;	//���ʿ���
		_emState.run = false;	//�޸��� ����

		_emSet.CH = pt;				//��ġ
		_emSet.ch = MakeRct(_emSet.CH.x - 33, _emSet.CH.y - 130, 66, 130);	//�ǰݹ���

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
	//���� �� ���󺯰��Ű���� �սô�
	//�ִϷ���Z
	_emSet.img->aniRender(getMemDC(), pos.x - 316 / 2, pos.y - 408 / 2, _emSet.ani);
	if (_color != 0)
	{
		if (_color == 1) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(252, 116, 180));//��ȫ ü����
		else if (_color == 2) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(128, 208, 16));//���η� ü����
		else if (_color == 3) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(240, 188, 60));//������� ü����
		else if (_color == 4) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(116, 116, 116));//ȸ������ ü����
		else if (_color == 5) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�������� ü����
		else if (_color == 6) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(124, 8, 0));//�ʷ����� ü����
		else if (_color == 7) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(24, 60, 92));//�������� ü����
		else if (_color == 8) _emSet.img->setTransColor(RGB(0, 232, 216), RGB(216, 40, 0));//��Ȳ���� ü����
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
	//������ �� �� ���� ���� ��
	_7_2L_Rani = new animation;
	_7_2L_Rani->init(2212, 408, 316, 204);
	_7_2L_Rani->setPlaylist(_7_3L_Right, 2, false);
	_7_2L_Rani->setFPS(1);
	//���� �� �� ������ ���� ��
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
		//���ݸ�� ������ �ٷε� �����ִٰ��� �Ŀ� IDLE�� ��ȯ
		break;
	case KICK:
		_emSet.img = _kick;
		if (_left)_emSet.ani = _3Lani;
		else if (!_left)_emSet.ani = _3Rani;
		_emSet.ani->resume();
		//���ݸ�� ������ �ٷε� �����ִٰ��� �Ŀ� IDLE�� ��ȯ
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
			//���ֺ��� ���� ��
			_emSet.ani = _7_3L_Lani;
			//��ڸ� ���� ��
			_emSet.ani = _7_2R_Lani;
		}
		else if (!_left)
		{
			//���ֺ��� ���� ��
			_emSet.ani = _7_3R_Rani;
			//��ڸ� ���� ��
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
		//���� ������
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

