#pragma once
#include "gameNode.h"


constexpr int VIEWPORT_UPDATE_OFFSET = 2;

class player;
class map_;
class item;

class gameScene : public gameNode
{
private:
	static player* _p;

	static vector<map_*> _mapList;
	static map_* _currMap;

	static int _prevMapNum, _mapNum, _prevshopNum, _shopNum;

	static int _countForReEnablingKeyInput;

	int _topBoxAdjX; // ��� ���� �̵� �� ����ϴ� ����
	int _bottomBoxAdjX; // �ϴ� ���� �̵� �� ����ϴ� ����

	int _countForFading; // ���̵�ƿ�, ���̵��� ���� �� ����ϴ� ����

	// ���, �ϴ� ������ �۲� �ڵ�
	HFONT _hFont, _hOFont;

	// ���ϴ� ������ DC �ڵ�, ��Ʈ�� �ڵ�
	HDC _hBoxDC;
	HBITMAP _hBoxBitmap, _hOBoxBitmap;
	
	// ��� ���� ǥ�� ���� ��ȯ�� ����
	bool _shouldShowMoneyOnTop;
	RECT _topBoxTextArea;

	// �ϴ� ���� ȭ��ǥ ��¿� ����
	bool _shouldShowBottomBoxArrow;
	vector<POINT> _bottomBoxArrowPos;
	BYTE _bottomBoxArrowPosIdx;
	vector<RECT> _bottomBoxTextArea;

	// ��� ���� ���� ��¿� ����
	string _hPString;

	// �� ȭ�� ������ ����(�޴�)
	BYTE _currMenuIdx;
	vector<item*> _itemPtrList;
	vector<string> _itemList;
	vector<RECT> _itemNameTextArea;
	bool _shouldShowMainBoxArrow;
	vector<POINT> _mainBoxArrowPos;
	BYTE _mainBoxArrowPosIdx;

	// Ư�� �޴��� ����
	int _bottomBoxCountForBelongings;
	int _bottomBoxCountForVolume;
	RECT _volumeRct[6];
	HBRUSH _hBrush1, _hBrush2, _hOBrush;
	int _bottomBoxCountForLevels;
	int _prevYPosForLevels, _prevXPosForLevels, _yPosForLevels, _xPosForLevels;
	int _bottomBoxCountForStatus;
	int _bottomBoxCountForHelp;
public:
	gameScene();
	~gameScene() override;

	HRESULT init() override;
	void release() override;
	void update() override;
	void render() override;
	static void setMapNum(int num) { _mapNum = num; }
	static void setShopNum(int num) { _shopNum = num; }
	static int getShopNum() { return _shopNum; }
	static int getPrevMapNum() { return _prevMapNum; }
	static void goToMap(int num);
	void updateViewport(int x, int y);
	void setViewport(int x, int y);

	void drawTopSecondBox(); // ��� ������ ���� ��� �Լ�
	void drawBottomSecondBox(); // �ϴ� �޴� ���� ��� �Լ�

	void showBelongingsScr();
	void showVolumeScr();
	void showLevelsScr();
	void showStatusScr();
	void showHelpScr();
	void updateMenuScr(BYTE idx);
	void removeMenuScr(BYTE prevBottomBoxArrowPosIdx);
};

