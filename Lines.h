
#pragma once
#include "gameNode.h"
#include <vector>

//class Lines : public gameNode
//{
	/*private:
		int
			CNT,		//���ڰ� ������ �ӵ������� ���͹�
			STR_IDX,	//������� ��µ� ���ڿ��� ����, ��ȣ , �ε���
			FONT_SIZE
			;

		float
			CLOCK,		//������� �ʴ��� ���͹�
			CLOCK_1
			;

		bool
			APPROACH,			//�� ��µ������� �ȵ����� �������� �̰� ������ ����
			ALIVE,
			LAUNCH_COMPLETE,	//�ؽ�Ʈ�� ��� ����ٴ� Ʈ���� bool ����
			KILL_COMPLETE		//�ؽ�Ʈ�� ��� �׿��ٴ� Ʈ���� bool ����
			;

		char OUTPUT_LINE[256];	//������ ��µǴ� ��縦 �������ִ� ���ڿ�

		string SUBSTR_LINE;		//�Է� ��縦 �ε��� 0~n ������ ���ڸ� ��Ƶδ� ���ڿ�
		string C_STR_LINE;		//SUBSTR_LINE�� �������ִ� string�� ���ڿ��� char������ �ٲ������ϴ� ���ڿ� ������ �ܰ���

		RECT LINE_RECT;			//����� ������ �������ִ� ��Ʈ

		void launcher_Line();
		void kill_Line();

	public:
		Lines();
		~Lines();

		virtual HRESULT init(RECT _rect, int _fontsize, bool _alive, int _time, string _Lines);
		virtual void release();
		virtual void update();
		virtual void render();

		bool getDeadTrigger() { return KILL_COMPLETE; }*/

		/*private:

			//������ �ѱ����ѱ��ڿ� ���� ��ǥ�� ����
			struct oneChar
			{
				float _x, _y;
				char oChar[32];
			};

			int
				CNT,				//���¼ӵ������� ���͹�
				FONT_SIZE,			//��Ʈ ������
				CURRENT_LEN,		//���簡��Ű���ִ� �迭��ȣ
				I					//�̰Ǳ׳� ���ﶧ �ʿ��� ����
				;

			bool
				APPROACH,			//��������, ���ڰ� ������ �Ϸ�ɶ� true�� �ȴ�.
				IMDEAD
				;

			float
				CLOCK,				//init���� ���� �޾ƿ� �ʴ����ð�
				CURRENT_CLOCK		//���� �����ӿ� ���� 1�ʸ� ī��Ʈ���ִ� ����
				;

			string SUBSTR_LINE;		//init���� ���� �޾ƿ� ��� ���ڿ�

			POINT LINE_POS;			//init���� ���� �޾ƿ� ������ġ

			vector<oneChar> _vChar;	//�ѱ����ѱ��ڿ��� ����Ǿ��ִ� ����

			void newLine();			//���ڸ� �ѱ����ѱ��� ����ֱ����� �Լ�
			void deleteLine();		//���ڸ� �ѱ����ѱ��� �����ֱ����� �Լ�

		public:
			Lines();
			~Lines();

			virtual HRESULT init(POINT _pos, int _fontsize, int _time, string _Lines);
			virtual void release();
			virtual void update();
			virtual void render();

			bool getDead() { return IMDEAD; }

		};
		*/

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

	char WORD_CLIST[256];
	int WORD_ILIST[256];

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