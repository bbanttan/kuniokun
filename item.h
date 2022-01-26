#pragma once
#include "gameScene.h"

class item : public gameScene
{
private:
string _iName;
int _price;			//��Ʈ ���� ���� �� ǥ��� �޷� �׷��Ƿ� 100 ��Ʈ�� 1�޷� 200��Ʈ�� ���� �������� $ 2.00
int _plusPunch;		//��ġ	
int _plusKick;		//ű		
int _plusWeapon;	//����	
int _plusPower;		//��	    
int _plusAgility;	//��ø	
int _plusGuard;		//���	
int _plusEndure;	//����	
int _plusEnergy;	//���	
int _recoveryHp;	//ü��	
int _plusMaxHp;		//�ִ�ü��
public:
	
	HRESULT init(string _name);
	void release() override;
	void update() override;
	void render() override;
	void itemList(string _name);
	
	string getName() { return _iName; }
	int getPrice() { return _price; }
	int getPlusPunch() { return _plusPunch; }
	int getPlusKick(){ return _plusKick; }
	int getPlusWeapon() { return _plusWeapon; }
	int getPlusPower() { return _plusPower; }
	int getPlusAgility() { return _plusAgility; }
	int getPlusGuard() { return _plusGuard; }
	int getPlusEndure() { return _plusEndure; }
	int getPlusEnergy() { return _plusEnergy; }
	int getRecoveryHp() { return _recoveryHp; }
	int getPlusMaxHp() { return _plusMaxHp; }
	
};