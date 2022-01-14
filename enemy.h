#pragma once
#include "character.h"
class enemy :
    public character
{
protected:
	STATE _emST;				//�� ���� enum STATE 
	tagState _emState;			//�� ���� tagState
	tagStatus _emStatus;		//�� ���� Status
	tagCharacterSetting _emSet;	//�� ���� Setting

	image* _run, *_walk, *_punch, *_kick, *_uppercut, *_highkick,
		*_run_punch, *_jump, *_jumpkick, *_defend, *_beatup, *_ko,
		*_stick_pipe, *_chain, *_knuckles, *_rock, *_lift_trashcan,
		*_lift_crate, *_lift_tire, *_lift_human, *_throw_stick_pipe,
		*_throw_chain, *_throw_knuckles, *_throw_rock, *_throw_trashcan,
		*_throw_crate, *_throw_tire, *_throw_human;
	animation *_1Rani, *_2Rani, *_2RaniL, *_3Rani, *_3RaniL, *_4Rani, *_6Rani, *_7Rani;//������ ������ ���
	//�Ϻ� ��� 
	//2_1�� 1��° / 2_2�� 2��° ���徿�� ��� // 7_2 �� 7�� �� 2�� ��� / 7_3�� 7�� �� 3�� ���
	animation *_2_1Rani, *_2_1Lani, *_2_2Rani, *_2_2Lani, *_7_2L_Rani, *_7_3L_Lani, *_7_2R_Lani, *_7_3R_Rani;
	animation *_1Lani, *_2Lani, *_2LaniL, *_3Lani, *_3LaniL, *_4Lani, *_6Lani, *_7Lani;//������ ���� ���
	animation *_7_1Lani, *_7_1Rani;//7_1�� 7�� �� 1�� ���
	int _type, _color;

	bool _left;
public:
	enemy() {};
    ~enemy() override = 0;
	HRESULT init() override;
	HRESULT init(POINT3D pt, int type = 0, int color = 0);
	void release() override;
	void update() override;
	void render() override;

	void ani1Set();
	void ani2Set();
	void ani3Set();
	void ani4Set();
	void ani6Set();
	void ani7Set();

	void aniSwitch();

	int getMaxHP() { return _emStatus.maxHP; }
	int getEnergy() { return _emStatus.energy; }
	int getPunch() { return _emStatus.punch; }
	int getkick() { return _emStatus.kick; }
	int getWeapon() { return _emStatus.weapon; }
	int getPower() { return _emStatus.power; }
	int getAgility() { return _emStatus.agility; }
	int getGuard() { return _emStatus.guard; }
	int getEndure() { return _emStatus.endure; }
	int getMoney() { return _emStatus.money; }
	string getName() { return _emSet.chName; }
};

