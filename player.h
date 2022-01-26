#pragma once
#include "character.h"

class item;
class player: public character
{
	private:
	STATE _p_state;
	tagCharacterSetting _p_character_set;
	tagStatus _p_status;
	tagState _p_tagState;

protected:
	image* _run, *_walk, *_punch, *_kick, *_uppercut, *_highkick,
		*_run_punch, *_jump, *_jumpkick, *_defend, *_beatup, *_ko,
		*_stick_pipe, *_chain, *_knuckles, *_rock, *_lift_trashcan,
		*_lift_create, *_lift_tire, *_lift_human, *_throw_stick_pipe,
		*_throw_chain, *_throw_knuckles, *_throw_rock, *_throw_trashcan,
		*_throw_crate, *_throw_tire, *_throw_human, *_roll, *_shop_stand_order,
		*_shop_stand_eat, *_shop_sit_order, *_shop_sit_eat;

	animation* _L_run, *_L_walk, *_L_punch, *_L_kick, *_L_uppercut, *_L_highkick,
		*_L_run_punch, *_L_jump, *_L_jumpkick, *_L_defend, *_L_beatup, *_L_ko,
		*_L_stick_pipe, *_L_chain, *_L_knuckles, *_L_rock, *_L_lift_trashcan,
		*_L_lift_create, *_L_lift_tire, *_L_lift_human, *_L_throw_stick_pipe,
		*_L_throw_chain, *_L_throw_knuckles, *_L_throw_rock, *_L_throw_trashcan,
		*_L_throw_crate, *_L_throw_tire, *_L_throw_human, *_L_roll, *_L_shop_stand_order,
		*_L_shop_stand_eat, *_L_shop_sit_order, *_L_shop_sit_eat;

	animation* _R_run, *_R_walk, *_R_punch, *_R_kick, *_R_uppercut, *_R_highkick,
		*_R_run_punch, *_R_jump, *_R_jumpkick, *_R_defend, *_R_beatup, *_R_ko,
		*_R_stick_pipe, *_R_chain, *_R_knuckles, *_R_rock, *_R_lift_trashcan,
		*_R_lift_create, *_R_lift_tire, *_R_lift_human, *_R_throw_stick_pipe,
		*_R_throw_chain, *_R_throw_knuckles, *_R_throw_rock, *_R_throw_trashcan,
		*_R_throw_crate, *_R_throw_tire, *_R_throw_human, _R_roll;

	RECT _attack_rc; // ���ݿ� ��Ʈ
	int dash_cnt; // �뽬 ī��Ʈ
	int _count; // ������ ī��Ʈ
	int _FrameI; // ������ �ε���
	float deltaX; //�̲����� ȿ���� ���� player ��ġ ����

	bool left; // �ִϸ��̼� ����� bool��
	bool _isJump; // ������ bool ��
	bool _isRun; // �뽬�� bool ��

	vector<item*> _vItem;

	float _JP;		//���� �ö󰡴� ��
	float _G;		//���� �� �������� �ϴ� �߷�
	float _deltaZ;	//pos.z�� ���Խ�Ű�� ���� ����
	float _MV;		//���� �� deltaX�� ���Խ�Ű�� ���� ����
	bool _WD;		//����������� bool��
public:
	player() {};
	~player() override {};

	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;


	inline void hitDamage(int damage) { _p_status.hp -= min(damage, _p_status.hp); } //�����
	int recoveryHp(int hpUp)
	{
		if (_p_status.hp + hpUp > _p_status.maxHP)
		{
			int realHPUp = _p_status.maxHP - _p_status.hp;
			_p_status.hp = _p_status.maxHP;
			return realHPUp;
		}
		else _p_status.hp += hpUp;
		return hpUp;
	} //ü�� ȸ��
	inline void maxHpUp(int maxHpUp) { _p_status.maxHP += maxHpUp; _p_status.maxHP = min(_p_status.maxHP, 127); }		//�ִ� ü�� ����(���� ���� ����)
	inline void recoveryEng(int engUp) { _p_status.energy += engUp; _p_status.energy = min(_p_status.energy, 64); }		//��� ȸ��
	inline void endureUp(int endUp) { _p_status.endure += endUp; _p_status.endure = min(_p_status.endure, 64); }			//���� ���
	inline void guardUp(int defUp) { _p_status.guard += defUp; _p_status.guard = min(_p_status.guard, 64); }			//���� ���
	inline void agilityUp(int agiUp) { _p_status.agility += agiUp; _p_status.agility = min(_p_status.agility, 64); }		//��ø ���
	inline void powerUp(int powUp) { _p_status.power += powUp; _p_status.power = min(_p_status.power, 64); }			//�� ���
	inline void weaponUp(int wepUp) { _p_status.weapon += wepUp; _p_status.weapon = min(_p_status.weapon, 64); }			//���� ���ݷ� ���
	inline void kickUp(int kAtkUp) { _p_status.kick += kAtkUp; _p_status.kick = min(_p_status.kick, 64); }			//������ ���ݷ� ���
	inline void punchUp(int pAtkUp) { _p_status.punch += pAtkUp; _p_status.punch = min(_p_status.punch, 64); }			//�ָ� ���ݷ� ���
	inline void moneyR(int money) { _p_status.money -= money; }				//������ ����
	pair<int, int> setAllStatusValuesUsingShopItem(int pAtkUp, int kAtkUp, int wepUp, int powUp, int agiUp, int defUp, int endUp, int engUp, int hpUp, int maxHpUp)
	{
		int realHPUp, remainingHPUp, realMaxHPUp;

		if (_p_status.hp + hpUp > _p_status.maxHP)
		{
			realHPUp = _p_status.maxHP - _p_status.hp;
			remainingHPUp = hpUp - realHPUp;
			_p_status.hp = _p_status.maxHP;
		}
		else { _p_status.hp += hpUp; realHPUp = hpUp; remainingHPUp = 0; }

		realMaxHPUp = max(1, static_cast<int>(roundf(static_cast<float>(maxHpUp) * static_cast<float>(remainingHPUp) / static_cast<float>(hpUp)))); // ���� ����
		if (_p_status.maxHP + realMaxHPUp > 127) realMaxHPUp = 127 - _p_status.maxHP;
		_p_status.maxHP += realMaxHPUp;
		_p_status.energy += engUp; _p_status.energy = min(_p_status.energy, 64);
		_p_status.endure += endUp; _p_status.endure = min(_p_status.endure, 64);
		_p_status.guard += defUp; _p_status.guard = min(_p_status.guard, 64);
		_p_status.agility += agiUp; _p_status.agility = min(_p_status.agility, 64);
		_p_status.power += powUp; _p_status.power = min(_p_status.power, 64);
		_p_status.weapon += wepUp; _p_status.weapon = min(_p_status.weapon, 64);
		_p_status.kick += kAtkUp; _p_status.kick = min(_p_status.kick, 64);
		_p_status.punch += pAtkUp; _p_status.punch = min(_p_status.punch, 64);
		return make_pair(remainingHPUp, realMaxHPUp);
	};

	inline int currentMoney() { return _p_status.money; }
	inline int currentHP() { return _p_status.hp; }
	inline int currentMaxHP() { return _p_status.maxHP; }
	inline int currentEnergy() { return _p_status.energy; }
	inline int currentPunch() { return _p_status.punch; }
	inline int currentKick() { return _p_status.kick; }
	inline int currentWeapon() { return _p_status.weapon; }
	inline int currentPower() { return _p_status.power; }
	inline int currentAgility() { return _p_status.agility; }
	inline int currentGuard() { return _p_status.guard; }
	inline int currentEndure() { return _p_status.endure; }

	inline void setMoney(int value) { _p_status.money = value; }
	inline void setHP(int value) { _p_status.hp = value; }
	inline void setMaxHP(int value) { _p_status.maxHP = value; }
	inline void setEnergy(int value) { _p_status.energy = value; }
	inline void setPunch(int value) { _p_status.punch = value; }
	inline void setKick(int value) { _p_status.kick = value; }
	inline void setWeapon(int value) { _p_status.weapon = value; }
	inline void setPower(int value) { _p_status.power = value; }
	inline void setAgility(int value) { _p_status.agility = value; }
	inline void setGuard(int value) { _p_status.guard = value; }
	inline void setEndure(int value) { _p_status.endure = value; }

	inline void setPlayerChName(string name) { _p_character_set.chName = name; }
	inline string getPlayerChName() { return _p_character_set.chName; }

	void playerSetStatus();		//�÷��̾� ���� �ʱⰪ ���� �Լ�
	void playerImgFind();		//�÷��̾� �̹��� ���� �Լ�
	void playerSetAni();		//�÷��̾� �ִϸ��̼� ��� �Լ�
	void frameUp();				//�ִϸ��̼� ��� �Լ�

	/////////////map ���� �� ������ �ʿ��� �Լ���
	
	float getDeltaZ() { return _deltaZ; }
	bool getJump() { return _p_tagState.jump; }			//jump bool ������
	STATE getPlState() { return _p_state; }				//�÷��̾�� STATE ������
	
	void setPlWD(bool WD) { _WD = WD; }					//WD(�� �������� bool) ������
	void setJump(bool jump) { _p_tagState.jump = jump; }//jump bool ������
	void setPlState(STATE state) { _p_state = state; }//�÷��̾�� STATE ������

	void jumpSwitch();		//������ ����ġ
	
	bool jumpDown();		//�����ؼ� ������ �� true

	//////////////
	vector<item*> &getVItem() { return _vItem; }
};

