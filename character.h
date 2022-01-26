#pragma once
#include "gameNode.h"

enum STATE
{
	IDLE,			//����
	WALK,
	RUN, 			//�޸���
	PUNCH,			//��ġ(run������ �� run+punch�� �� �� �ִ�)
	KICK,			//ű(run + jump ������ �� jump+kick�� �� �� �ִ�)
	ITEM_PICK,		//������ �ݱ�
	ITEM_ATTACK,	//������ ����
	ITEM_THROW,		//������ ������
	DEFEND,		//���
	HIT,			//�ǰ�
	JUMP, 			//����
	FALL,			//�� � �ε��� �� / ���ݹ޾Ƽ� �ھƿ��� �� / ������ó�� ������ �� ������
	DOWN,			//HP�� 0�� �ƴ� �� / ������� ��Ȱ�� �� ������
	KO			//������
};

struct tagCharacterSetting
{
	POINT3D CH;	//ĳ���� ��Ʈ �׷��� ����Ʈ
	RECT ch;		//ĳ���� ��Ʈ
	RECT atk;	//ĳ���� ���ݷ�Ʈ
	image* img;	//�̹���
	animation* ani;
	string chName;	//ĳ���� �̸�
	
};

//��ġ		- ��ġ �迭 ��� ���ݷ�
//ű		- ������ �迭 ��� ���ݷ�
//����		- ���� ���ݷ�
//��		- ������ ���ݷ�
//��ø		- ��ü�� ���� ��ø�� ����
//���	- ���忡 ���� ����, �������� ����� ������ �پ��
//����		- �ǰݽ� ������ ����
//���	- ü���� �� �������� �� ��ȰȮ�� ����, ���ӵ�, �ǰݸ�� ���ӽð� ���� / ������� ��Ȱ�� ��� 15�� �Ҹ��� 15�� ü������ ��Ȱ
//ü��(�ִ�ü��)		- ü��
//������			- ��
struct tagStatus
{
	int punch;	//��ġ	
	int kick;		//ű		
	int weapon;	//����	
	int power;	//��	    
	int agility;	//��ø	
	int guard;	//���	
	int endure;	//����	
	int energy;	//���	
	int hp;		//ü��	
	int maxHP;	//�ִ�ü��
	int money;	//������ / ������ ��
};

struct tagState
{
	bool run;		//�޸���
	bool jump;		//����
	int W;			//����(0�� ����, 1~8�� ���� �������)
};



class character : public gameNode
{
protected:
	POINT3D pos;

public:
	character() {};
	~character() override {};

	POINT3D& getPos() { return pos; }

	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;
};

