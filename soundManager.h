#pragma once
#include "singleton.h"
#include <map>
#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex64_vc.lib")

using namespace FMOD;

constexpr size_t SOUNDBUFFER = 60; // �����δ�: �߰��� ���� ���� �������� Ŀ�� �Ѵ�.
constexpr size_t EXTRACHANNELBUFFER = 6;
#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER

class soundManager : public singleton<soundManager>
{
private:
	typedef map<string, Sound**>			soundList;
	typedef map<string, Sound**>::iterator	soundListIter;

	typedef map<string, Channel**>				channelList;
	typedef map<string, Channel**>::iterator	channelListIter;

	typedef map<string, bool>				bgmOrNotList;
	//typedef map<string, bool>::iterator		bgmOrNotListIter;

private:
	System*			_system;
	Sound**			_sound;
	Channel**		_channel;

	soundList		_soundList;
	soundListIter   _soundListIter;
	bgmOrNotList	_bgmOrNotList;

public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();

	Sound** findSound(string strKey);

	Channel* findChannel(string strKey);

	// ���� ���� �߰� �Լ�(Ű ��, ���ϸ�, ��������� ����, �ݺ� ��� ����)
	void addSound(string strKey, string soundFileName, bool isBGM, bool isLoop);

	// �߰��� ���� ������ ����ϴ� �Լ� (����: 0.0f���� 1.0f����)
	void play(string strKey, float volume = 1.0f);
	
	// Ư�� ���� ����� ������ ���ߴ� �Լ�
	void stop(string strKey);
	
	// Ư�� ���� ����� �Ͻ� ���� �ϴ� �Լ�
	void pause(string strKey);
	
	// Ư�� ���� ����� �簳�ϴ� �Լ�
	void resume(string strKey);
	
	// Ư�� ������ ��� ������ �˻��ϴ� �Լ�
	bool isPlaying(string strKey);
	
	// Ư�� ���� ����� �Ͻ� ���� �� �������� �˻��ϴ� �Լ�
	bool isPaused(string strKey);

	// ���� ��� ���� ������ ���� �Ͻ� ���� �ϴ� �Լ�
	void pauseAll();

	// ���� �Ͻ� ���� ���� ������ ���� ����ϴ� �Լ�
	void resumeAll();

	// ���� ��� ���� ������ ���� �����ϴ� �Լ�
	void stopAll();

	// ������ ���� ������ ��� �ݿ��� �� ���� �Լ�
	void updateMasterVolume();

	// ����� ���� ������ ��� �ݿ��� �� ���� �Լ�
	void updateBGMVolume();

	// ȿ���� ���� ������ ��� �ݿ��� �� ���� �Լ�
	void updateSFXVolume();
};

