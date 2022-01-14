#include "stdafx.h"
#include "loadingScene.h"
#include "gameScene.h"
#include "MainScene.h"
#include "progressBar.h"
#include <process.h> // _beginthreadex

loadingScene::loadingScene(): _background(nullptr), _loadingBar(nullptr), _currentCount(0) {}

loadingScene::~loadingScene() {}

HRESULT loadingScene::init()
{
	_loadingBar = new progressBar;
	_loadingBar->init(0, WINH - 30, WINW, 30);
	_loadingBar->updateGauge(0, 0);

	hThread = (HANDLE)_beginthreadex(NULL, 0, threadFunc, this, CREATE_SUSPENDED, NULL);
	if (!hThread)
	{
		return E_FAIL;
	}
	ResumeThread(hThread);

	return S_OK;
}

void loadingScene::release()
{
	SAFE_DEL(_loadingBar);
}

void loadingScene::update()
{
	_loadingBar->update();
	_loadingBar->updateGauge(static_cast<float>(_currentCount), MAX_SLEEP_CALLS);
}

void loadingScene::render()
{
	_loadingBar->render();

	// �ε� �Ϸ� ��
	if (_currentCount == MAX_SLEEP_CALLS)
	{
		CloseHandle(hThread);
		SC->changeScene("����ȭ��");
	}
}

unsigned CALLBACK loadingScene::threadFunc(LPVOID params)
{
	loadingScene* loadingParams = (loadingScene*)params;

	SC->addScene("����ȭ��", new MainScene);
	++loadingParams->_currentCount;

	SC->addScene("���� ���", new gameScene);
	++loadingParams->_currentCount;

	// ���� ȭ�� �̹���
	IMG->add("���ۻ� �ΰ�", "images/preGame/logo.bmp", 714, 128, false, RGB(255, 0, 255));
	IMG->add("����", "images/preGame/title.bmp", 1024, 640, false, RGB(255, 0, 255));
	++loadingParams->_currentCount;

	// �� �̹���
	IMG->add("�� 1", "images/maps/1.bmp", 3036, 640, false, RGB(255, 0, 255));
	IMG->add("�� 2", "images/maps/2.bmp", 2012, 640, false, RGB(255, 0, 255));
	IMG->add("�� 3", "images/maps/3.bmp", 2012, 640, false, RGB(255, 0, 255));
	IMG->add("�� 4", "images/maps/4.bmp", 3040, 640, false, RGB(255, 0, 255));
	IMG->add("�� 4-2", "images/maps/4-2.bmp", 1884, 640, false, RGB(255, 0, 255));
	IMG->add("�� 5", "images/maps/5.bmp", 2012, 640, false, RGB(255, 0, 255));
	IMG->add("������", "images/maps/shopbasic.bmp", 1024, 640, false, RGB(255, 0, 255));
	++loadingParams->_currentCount;

	// ĳ���� �̹���
	loadingParams->playerImg(); ++loadingParams->_currentCount;
	loadingParams->enemyImgOne(); ++loadingParams->_currentCount;
	loadingParams->enemyImgTwo(); ++loadingParams->_currentCount;
	loadingParams->enemyImgThree(); ++loadingParams->_currentCount;
	loadingParams->enemyImgFour(); ++loadingParams->_currentCount;
	loadingParams->enemyImgFive(); ++loadingParams->_currentCount;
	loadingParams->enemyImgSix(); ++loadingParams->_currentCount;
	loadingParams->enemyImgSeven(); ++loadingParams->_currentCount;
	loadingParams->enemyImgEight(); ++loadingParams->_currentCount;
	loadingParams->enemyImgNine(); ++loadingParams->_currentCount;
	loadingParams->enemyImgBoss(); ++loadingParams->_currentCount;

	// ���� �̹���
	loadingParams->wpImg();	++loadingParams->_currentCount;

	// ���� �̹���
	IMG->addF("����", "images/coin.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	++loadingParams->_currentCount;

	// ȭ�� ��� �̹���
	IMG->add("�̸������Ķ�ȭ��", "images/NAMEblueScreen.bmp", WINW, 640, false, RGB(0, 0, 0));
	IMG->add("���� ȭ��", "images/blackScreen.bmp", WINW, WINH, false, RGB(0, 0, 0));
	IMG->add("�Ķ� ȭ��", "images/blueScreen.bmp", WINW, WINH, false, RGB(0, 0, 0));
	IMG->add("640�Ķ� ȭ��", "images/640blueScreen.bmp", WINW, 640, false, RGB(0, 0, 0));
	++loadingParams->_currentCount;

	//���� �̹���
	IMG->add("������", "images/maps/pointer.bmp", 40, 40, true, RGB(255, 0, 255));
	IMG->add("����", "images/maps/bakery.bmp", 265, 265, false, RGB(0, 0, 0));
	IMG->add("ī��", "images/maps/cafe.bmp", 265, 265, false, RGB(0, 0, 0));
	IMG->add("�ʹ���", "images/maps/sushishop.bmp", 265, 265, false, RGB(0, 0, 0));
	IMG->add("����", "images/maps/bookstore.bmp", 265, 265, false, RGB(0, 0, 0));



	ifstream file;
	string line;
	// �����
	file.open("sounds/bgm/fileList.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line == "3 - Title Screen.mp3")
			{
				SND->addSound(line, "sounds/bgm/3 - Title Screen.mp3", true, false);
			}
			else
			{
				SND->addSound(line, "sounds/bgm/" + line, true, true);
			}
		}
	}
	file.close();
	++loadingParams->_currentCount;

	// ȿ����
	file.open("sounds/fx/fileList.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			SND->addSound(line, "sounds/fx/" + line, false, false);
		}
	}
	file.close();
	++loadingParams->_currentCount;

	while (loadingParams->_currentCount != MAX_SLEEP_CALLS)
	{
		Sleep(1);
		++loadingParams->_currentCount;
	}
	return 0;
}

void loadingScene::playerImg()
{
	IMG->addF("p-�޸���", "images/player/p-1_run.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("p-�ȱ�", "images/player/p-2_walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-��ġ", "images/player/p-3_punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-ű", "images/player/p-4_kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-������", "images/player/p-5_upperCut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-����ű", "images/player/p-6_highKick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("p-�޸�����ġ", "images/player/p-7_run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-����", "images/player/p-8_jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("p-����ű", "images/player/p-9_jump+kick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("p-���", "images/player/p-10_defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("p-�ǰ�", "images/player/p-11_beatUp.bmp", 2212, 408, 7, 2, true, RGB(255, 0, 255));
	IMG->addF("p-KO", "images/player/p-12_ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("p-��ƽ", "images/player/p-13_stick.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("p-ü��", "images/player/p-14_chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("p-��Ŭ", "images/player/p-15_knuckle.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("p-��", "images/player/p-16_rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("p-������", "images/player/p-17_trash.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-�ڽ�", "images/player/p-18_box.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-Ÿ�̾�", "images/player/p-19_tire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-���", "images/player/p-20_human.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("p-��ƽ������", "images/player/p-21_throw-stick.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-ü�δ�����", "images/player/p-22_throw-chain.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-��Ŭ������", "images/player/p-23_throw-knucle.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-��������", "images/player/p-24_throw-rock.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-�����������", "images/player/p-25_throw-trash.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-�ڽ�������", "images/player/p-26_throw-box.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-Ÿ�̾������", "images/player/p-27_throw-tire.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-���������", "images/player/p-28_throw-human.bmp", 2212, 408, 8, 2, true, RGB(255, 0, 255));
	IMG->addF("p-������", "images/player/p-29_roll.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("p-�����ֹ�1", "images/player/p-30_shop_stand_orderl.bmp", 676, 144, 8, 1, true, RGB(255, 0, 255));
	IMG->addF("p-�������1", "images/player/p-31_shop_sit_order.bmp", 648, 136, 8, 1, true, RGB(255, 0, 255));
	IMG->addF("p-�����ֹ�2", "images/player/p-32_shop_stand_eat.bmp", 576, 160, 7, 1, true, RGB(255, 0, 255));
	IMG->addF("p-�������2", "images/player/p-33_shop_sit_eat.bmp", 548, 152, 7, 1, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgOne()
{
	IMG->addF("1-�޸���", "image/enemy/type1/02walk.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("1-�ȱ�", "image/enemy/type1/02walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��ġ", "image/enemy/type1/03punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-ű", "image/enemy/type1/04kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-������", "image/enemy/type1/05uppercut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-����ű", "image/enemy/type1/06highkick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("1-�޸�����ġ", "image/enemy/type1/07run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-����", "image/enemy/type1/08jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("1-����ű", "image/enemy/type1/09jumpkick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("1-���", "image/enemy/type1/10defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("1-�ǰ�", "image/enemy/type1/11beatup.bmp", 2212, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("1-KO", "image/enemy/type1/12ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��ƽ", "image/enemy/type1/13stick+pipe.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("1-ü��", "image/enemy/type1/14chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��Ŭ", "image/enemy/type1/15knuckles.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��", "image/enemy/type1/16rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("1-������", "image/enemy/type1/17throwtrashcan.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-�ڽ�", "image/enemy/type1/18throwcrate.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-Ÿ�̾�", "image/enemy/type1/19throwtire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-���", "image/enemy/type1/20throwhuman.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��ƽ������", "image/enemy/type1/21throw+stick+pipe.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("1-ü�δ�����", "image/enemy/type1/22throw+chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��Ŭ������", "image/enemy/type1/23throw+knuckles.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��������", "image/enemy/type1/24throw+rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("1-�����������", "image/enemy/type1/25throw+trashcan.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("1-�ڽ�������", "image/enemy/type1/26throw+crate.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("1-Ÿ�̾������", "image/enemy/type1/27throw+tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("1-��������� ", "image/enemy/type1/28throw+human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgTwo()
{
	IMG->addF("2-�޸���", "image/enemy/type2/02walk.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("2-�ȱ�", "image/enemy/type2/02walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��ġ", "image/enemy/type2/03punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-ű", "image/enemy/type2/04kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-������", "image/enemy/type2/05uppercut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-����ű", "image/enemy/type2/06highkick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("2-�޸�����ġ", "image/enemy/type2/07run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-����", "image/enemy/type2/08jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("2-����ű", "image/enemy/type2/09jumpkick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("2-���", "image/enemy/type2/10defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("2-�ǰ�", "image/enemy/type2/11beatup.bmp", 2212, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("2-KO", "image/enemy/type2/12ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��ƽ", "image/enemy/type2/13stick+pipe.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("2-ü��", "image/enemy/type2/14chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��Ŭ", "image/enemy/type2/15knuckles.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��", "image/enemy/type2/16rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("2-������", "image/enemy/type2/17throwtrashcan.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-�ڽ�", "image/enemy/type2/18throwcrate.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-Ÿ�̾�", "image/enemy/type2/19throwtire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-���", "image/enemy/type2/20throwhuman.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��ƽ������", "image/enemy/type2/21throw+stick+pipe.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("2-ü�δ�����", "image/enemy/type2/22throw+chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��Ŭ������", "image/enemy/type2/23throw+knuckles.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��������", "image/enemy/type2/24throw+rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("2-�����������", "image/enemy/type2/25throw+trashcan.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("2-�ڽ�������", "image/enemy/type2/26throw+crate.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("2-Ÿ�̾������", "image/enemy/type2/27throw+tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("2-��������� ", "image/enemy/type2/28throw+human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgThree()
{
	IMG->addF("3-�޸���", "image/enemy/type3/02walk.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("3-�ȱ�", "image/enemy/type3/02walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��ġ", "image/enemy/type3/03punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-ű", "image/enemy/type3/04kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-������", "image/enemy/type3/05uppercut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-����ű", "image/enemy/type3/06highkick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("3-�޸�����ġ", "image/enemy/type3/07run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-����", "image/enemy/type3/08jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("3-����ű", "image/enemy/type3/09jumpkick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("3-���", "image/enemy/type3/10defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("3-�ǰ�", "image/enemy/type3/11beatup.bmp", 2212, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("3-KO", "image/enemy/type3/12ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��ƽ", "image/enemy/type3/13stick+pipe.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("3-ü��", "image/enemy/type3/14chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��Ŭ", "image/enemy/type3/15knuckles.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��", "image/enemy/type3/16rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("3-������", "image/enemy/type3/17throwtrashcan.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-�ڽ�", "image/enemy/type3/18throwcrate.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-Ÿ�̾�", "image/enemy/type3/19throwtire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-���", "image/enemy/type3/20throwhuman.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��ƽ������", "image/enemy/type3/21throw+stick+pipe.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("3-ü�δ�����", "image/enemy/type3/22throw+chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��Ŭ������", "image/enemy/type3/23throw+knuckles.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��������", "image/enemy/type3/24throw+rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("3-�����������", "image/enemy/type3/25throw+trashcan.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("3-�ڽ�������", "image/enemy/type3/26throw+crate.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("3-Ÿ�̾������", "image/enemy/type3/27throw+tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("3-��������� ", "image/enemy/type3/28throw+human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgFour()
{
	IMG->addF("4-�޸���", "image/enemy/type4/02walk.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("4-�ȱ�", "image/enemy/type4/02walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��ġ", "image/enemy/type4/03punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-ű", "image/enemy/type4/04kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-������", "image/enemy/type4/05uppercut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-����ű", "image/enemy/type4/06highkick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("4-�޸�����ġ", "image/enemy/type4/07run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-����", "image/enemy/type4/08jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("4-����ű", "image/enemy/type4/09jumpkick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("4-���", "image/enemy/type4/10defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("4-�ǰ�", "image/enemy/type4/11beatup.bmp", 2212, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("4-KO", "image/enemy/type4/12ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��ƽ", "image/enemy/type4/13stick+pipe.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("4-ü��", "image/enemy/type4/14chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��Ŭ", "image/enemy/type4/15knuckles.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��", "image/enemy/type4/16rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("4-������", "image/enemy/type4/17throwtrashcan.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-�ڽ�", "image/enemy/type4/18throwcrate.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-Ÿ�̾�", "image/enemy/type4/19throwtire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-���", "image/enemy/type4/20throwhuman.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��ƽ������", "image/enemy/type4/21throw+stick+pipe.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("4-ü�δ�����", "image/enemy/type4/22throw+chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��Ŭ������", "image/enemy/type4/23throw+knuckles.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��������", "image/enemy/type4/24throw+rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("4-�����������", "image/enemy/type4/25throw+trashcan.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("4-�ڽ�������", "image/enemy/type4/26throw+crate.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("4-Ÿ�̾������", "image/enemy/type4/27throw+tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("4-��������� ", "image/enemy/type4/28throw+human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgFive()
{
	IMG->addF("5-�޸���", "image/enemy/type5/02walk.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("5-�ȱ�", "image/enemy/type5/02walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��ġ", "image/enemy/type5/03punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-ű", "image/enemy/type5/04kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-������", "image/enemy/type5/05uppercut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-����ű", "image/enemy/type5/06highkick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("5-�޸�����ġ", "image/enemy/type5/07run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-����", "image/enemy/type5/08jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("5-����ű", "image/enemy/type5/09jumpkick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("5-���", "image/enemy/type5/10defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("5-�ǰ�", "image/enemy/type5/11beatup.bmp", 2212, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("5-KO", "image/enemy/type5/12ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��ƽ", "image/enemy/type5/13stick+pipe.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("5-ü��", "image/enemy/type5/14chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��Ŭ", "image/enemy/type5/15knuckles.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��", "image/enemy/type5/16rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("5-������", "image/enemy/type5/17throwtrashcan.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-�ڽ�", "image/enemy/type5/18throwcrate.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-Ÿ�̾�", "image/enemy/type5/19throwtire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-���", "image/enemy/type5/20throwhuman.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��ƽ������", "image/enemy/type5/21throw+stick+pipe.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("5-ü�δ�����", "image/enemy/type5/22throw+chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��Ŭ������", "image/enemy/type5/23throw+knuckles.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��������", "image/enemy/type5/24throw+rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("5-�����������", "image/enemy/type5/25throw+trashcan.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("5-�ڽ�������", "image/enemy/type5/26throw+crate.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("5-Ÿ�̾������", "image/enemy/type5/27throw+tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("5-��������� ", "image/enemy/type5/28throw+human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgSix()
{
	IMG->addF("6-�޸���", "images/enemy/type_6/type6-1_run.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("6-�ȱ�", "images/enemy/type_6/type6-2_walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-��ġ", "images/enemy/type_6/type6-3_punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-ű", "images/enemy/type_6/type6-4_kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-������", "images/enemy/type_6/type6-5_upperCut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-����ű", "images/enemy/type_6/type6-6_highKick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("6-�޸�����ġ", "images/enemy/type_6/type6-7_run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-����", "images/enemy/type_6/type6-8_jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("6-����ű", "images/enemy/type_6/type6-9_jump+kick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("6-���", "images/enemy/type_6/type6-10_defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("6-�ǰ�", "images/enemy/type_6/type6-11_beatUp.bmp", 2212, 408, 7, 2, true, RGB(255, 0, 255));
	IMG->addF("6-KO", "images/enemy/type_6/type6-12_ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("6-��ƽ", "images/enemy/type_6/type6-13_stick.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("6-ü��", "images/enemy/type_6/type6-14_chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("6-��Ŭ", "images/enemy/type_6/type6-15_knuckle.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("6-��", "images/enemy/type_6/type6-16_rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("6-������", "images/enemy/type_6/type6-17_trash.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-�ڽ�", "images/enemy/type_6/type6-18_box.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-Ÿ�̾�", "images/enemy/type_6/type6-19_tire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-���", "images/enemy/type_6/type6-20_human.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("6-��ƽ������", "images/enemy/type_6/type6-21_throw-knuckle.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("6-ü�δ�����", "images/enemy/type_6/type6-21_throw-stick.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("6-��Ŭ������", "images/enemy/type_6/type6-22_throw-chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("6-��������", "images/enemy/type_6/type6-24_throw-rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("6-�����������", "images/enemy/type_6/type6-25_throw-trash.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("6-�ڽ�������", "images/enemy/type_6/type6-26_throw-box.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("6-Ÿ�̾������", "images/enemy/type_6/type6-27_throw-tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("6-���������", "images/enemy/type_6/type6-28_throw-human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));

}

void loadingScene::enemyImgSeven()
{

	{IMG->addF("7-�޸���", "images/enemy/type_7/type7-1_run.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("7-�ȱ�", "images/enemy/type_7/type7-2_walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-��ġ", "images/enemy/type_7/type7-3_punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-ű", "images/enemy/type_7/type7-4_kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-������", "images/enemy/type_7/type7-5_upperCut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-����ű", "images/enemy/type_7/type7-6_highKick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("7-�޸�����ġ", "images/enemy/type_7/type7-7_run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-����", "images/enemy/type_7/type7-8_jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("7-����ű", "images/enemy/type_7/type7-9_jump+kick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("7-���", "images/enemy/type_7/type7-10_defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("7-�ǰ�", "images/enemy/type_7/type7-11_beatUp.bmp", 2212, 408, 7, 2, true, RGB(255, 0, 255));
	IMG->addF("7-KO", "images/enemy/type_7/type7-12_ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("7-��ƽ", "images/enemy/type_7/type7-13_stick.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("7-ü��", "images/enemy/type_7/type7-14_chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("7-��Ŭ", "images/enemy/type_7/type7-15_knuckle.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("7-��", "images/enemy/type_7/type7-16_rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("7-������", "images/enemy/type_7/type7-17_trash.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-�ڽ�", "images/enemy/type_7/type7-18_box.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-Ÿ�̾�", "images/enemy/type_7/type7-19_tire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-���", "images/enemy/type_7/type7-20_human.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("7-��ƽ������", "images/enemy/type_7/type7-21_throw-stick.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("7-ü�δ�����", "images/enemy/type_7/type7-22_throw-chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("7-��Ŭ������", "images/enemy/type_7/type7-23_throw-knucle.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("7-��������", "images/enemy/type_7/type7-24_throw-rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("7-�����������", "images/enemy/type_7/type7-25_throw-trash.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("7-�ڽ�������", "images/enemy/type_7/type7-26_throw-box.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("7-Ÿ�̾������", "images/enemy/type_7/type7-27_throw-tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("7-���������", "images/enemy/type_7/type7-28_throw-human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255)); }
}

void loadingScene::enemyImgEight()
{

	IMG->addF("8-�޸���", "images/enemy/type_8/type8-1_run.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("8-�ȱ�", "images/enemy/type_8/type8-2_walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-��ġ", "images/enemy/type_8/type8-3_punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-ű", "images/enemy/type_8/type8-4_kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-������", "images/enemy/type_8/type8-5_upperCut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-����ű", "images/enemy/type_8/type8-6_highKick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("8-�޸�����ġ", "images/enemy/type_8/type8-7_run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-����", "images/enemy/type_8/type8-8_jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("8-����ű", "images/enemy/type_8/type8-9_jump+kick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("8-���", "images/enemy/type_8/type8-10_defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("8-�ǰ�", "images/enemy/type_8/type8-11_beatUp.bmp", 2212, 408, 7, 2, true, RGB(255, 0, 255));
	IMG->addF("8-KO", "images/enemy/type_8/type8-12_ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("8-��ƽ", "images/enemy/type_8/type8-13_stick.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("8-ü��", "images/enemy/type_8/type8-14_chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("8-��Ŭ", "images/enemy/type_8/type8-15_knuckle.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("8-��", "images/enemy/type_8/type8-16_rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("8-������", "images/enemy/type_8/type8-17_trash.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-�ڽ�", "images/enemy/type_8/type8-18_box.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-Ÿ�̾�", "images/enemy/type_8/type8-19_tire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-���", "images/enemy/type_8/type8-20_human.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("8-��ƽ������", "images/enemy/type_8/type8-21_throw-knuckle.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("8-ü�δ�����", "images/enemy/type_8/type8-21_throw-stick.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("8-��Ŭ������", "images/enemy/type_8/type8-22_throw-chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("8-��������", "images/enemy/type_8/type8-24_throw-rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("8-�����������", "images/enemy/type_8/type8-25_throw-trash.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("8-�ڽ�������", "images/enemy/type_8/type8-26_throw-box.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("8-Ÿ�̾������", "images/enemy/type_8/type8-27_throw-tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("8-���������", "images/enemy/type_8/type8-28_throw-human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgNine()
{
	IMG->addF("9-�޸���", "images/enemy/type_9/type9-1_run.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("9-�ȱ�", "images/enemy/type_9/type9-2_walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-��ġ", "images/enemy/type_9/type9-3_punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-ű", "images/enemy/type_9/type9-4_kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-������", "images/enemy/type_9/type9-5_upperCut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-����ű", "images/enemy/type_9/type9-6_highKick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("9-�޸�����ġ", "images/enemy/type_9/type9-7_run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-����", "images/enemy/type_9/type9-8_jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("9-����ű", "images/enemy/type_9/type9-9_jump+kick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("9-���", "images/enemy/type_9/type9-10_defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("9-�ǰ�", "images/enemy/type_9/type9-11_beatUp.bmp", 2212, 408, 7, 2, true, RGB(255, 0, 255));
	IMG->addF("9-KO", "images/enemy/type_9/type9-12_ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("9-��ƽ", "images/enemy/type_9/type9-13_stick.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("9-ü��", "images/enemy/type_9/type9-14_chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("9-��Ŭ", "images/enemy/type_9/type9-15_knuckle.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("9-��", "images/enemy/type_9/type9-16_rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("9-������", "images/enemy/type_9/type9-17_trash.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-�ڽ�", "images/enemy/type_9/type9-18_box.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-Ÿ�̾�", "images/enemy/type_9/type9-19_tire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-���", "images/enemy/type_9/type9-20_human.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("9-��ƽ������", "images/enemy/type_9/type9-21_throw-stick.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("9-ü�δ�����", "images/enemy/type_9/type9-22_throw-chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("9-��Ŭ������", "images/enemy/type_9/type9-23_throw-knucle.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("9-��������", "images/enemy/type_9/type9-24_throw-rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("9-�����������", "images/enemy/type_9/type9-25_throw-trash.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("9-�ڽ�������", "images/enemy/type_9/type9-26_throw-box.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("9-Ÿ�̾������", "images/enemy/type_9/type9-27_throw-tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("9-���������", "images/enemy/type_9/type9-28_throw-human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::enemyImgBoss()
{
	IMG->addF("����-�޸���", "images/enemy/type_boss/boss-1_run.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("����-�ȱ�", "images/enemy/type_boss/boss-2_walk.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-��ġ", "images/enemy/type_boss/boss-3_punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-ű", "images/enemy/type_boss/boss-4_kick.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-������", "images/enemy/type_boss/boss-5_upperCut.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-����ű", "images/enemy/type_boss/boss-6_highKick.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("����-�޸�����ġ", "images/enemy/type_boss/boss-7_run+punch.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-����", "images/enemy/type_boss/boss-8_jump.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("����-����ű", "images/enemy/type_boss/boss-9_jump+kick.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("����-���", "images/enemy/type_boss/boss-10_defend.bmp", 316, 408, 1, 2, true, RGB(255, 0, 255));
	IMG->addF("����-�ǰ�", "images/enemy/type_boss/boss-11_beatUp.bmp", 2212, 408, 7, 2, true, RGB(255, 0, 255));
	IMG->addF("����-KO", "images/enemy/type_boss/boss-12_ko.bmp", 632, 408, 2, 2, true, RGB(255, 0, 255));
	IMG->addF("����-��ƽ", "images/enemy/type_boss/boss-13_stick.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("����-ü��", "images/enemy/type_boss/boss-14_chain.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("����-��Ŭ", "images/enemy/type_boss/boss-15_knuckle.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("����-��", "images/enemy/type_boss/boss-16_rock.bmp", 1264, 408, 4, 2, true, RGB(255, 0, 255));
	IMG->addF("����-������", "images/enemy/type_boss/boss-17_trash.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-�ڽ�", "images/enemy/type_boss/boss-18_box.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-Ÿ�̾�", "images/enemy/type_boss/boss-19_tire.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-���", "images/enemy/type_boss/boss-20_human.bmp", 948, 408, 3, 2, true, RGB(255, 0, 255));
	IMG->addF("����-��ƽ������", "images/enemy/type_boss/boss-21_throw-stick.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("����-ü�δ�����", "images/enemy/type_boss/boss-22_throw-chain.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("����-��Ŭ������", "images/enemy/type_boss/boss-23_throw-knucle.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("����-��������", "images/enemy/type_boss/boss-24_throw-rock.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("����-�����������", "images/enemy/type_boss/boss-25_throw-trash.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("����-�ڽ�������", "images/enemy/type_boss/boss-26_throw-box.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("����-Ÿ�̾������", "images/enemy/type_boss/boss-27_throw-tire.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
	IMG->addF("����-���������", "images/enemy/type_boss/boss-28_throw-human.bmp", 1896, 408, 6, 2, true, RGB(255, 0, 255));
}

void loadingScene::wpImg()
{
	IMG->addF("��������", "images/weapon/can.bmp", 256, 64, 4, 1, true, RGB(255, 0, 255));
	IMG->addF("ü��", "images/weapon/chain.bmp", 432, 72, 6, 1, true, RGB(255, 0, 255));
	IMG->addF("�ڽ�", "images/weapon/crate.bmp", 480, 64, 6, 1, true, RGB(255, 0, 255));
	IMG->addF("��Ŭ", "images/weapon/knuckles.bmp", 56, 32, 2, 1, true, RGB(255, 0, 255));
	IMG->addF("������", "images/weapon/pipe.bmp", 256, 64, 4, 1, true, RGB(255, 0, 255));
	IMG->addF("��", "images/weapon/rock.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMG->addF("��ƽ", "images/weapon/stick.bmp", 256, 64, 4, 1, true, RGB(255, 0, 255));
	IMG->addF("Ÿ�̾�", "images/weapon/tire.bmp", 384, 64, 6, 1, true, RGB(255, 0, 255));
}
