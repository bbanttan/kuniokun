﻿#pragma once


#include "targetver.h"
#define WIN32_LEAN_AND_MEAN // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
#include <iostream>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


using namespace std;
#include <vector>

//==================================
#define WINNAME (LPCSTR)(TEXT("열혈 이야기"))
#define WINX 50 // 창 시작점 x 좌표
#define WINY 50 // 창 시작점 y 좌표
#define WINW 1024 // 창 너비
#define WINH 896 // 창 높이

#define RNG randomNumber::getSingleton()
#define KEY keyManager::getSingleton()
#define IMG imageManager::getSingleton()
#define FX effectManager::getSingleton()
#define SND soundManager::getSingleton()
#define TIME timeManager::getSingleton()
#define KAN keyAnimManager::getSingleton()
#define INI iniDataManager::getSingleton()
#define SC sceneManager::getSingleton()
#define L LineManager::getSingleton()

#define SAFE_DEL(p) {if (p) {delete(p); (p) = nullptr;}}
#define SAFE_REL(p) {if (p) {(p)->release(); (p) = nullptr;}}
//==================================

extern HINSTANCE	_hInst;
extern HWND			_hWnd;
extern POINT		_mouse, _currOrg, _newOrg;
extern RECT			_camMovLim, _totRegion;
extern BOOL			_moveKeyDisabled, _isInShop, _shouldBePaused, _shouldFadeOut, _shouldShowMenuScreen;
extern float		_currMasterVolume, _currBGMVolume, _currSFXVolume;
extern string		_playerChName;
extern int			_lineSpd;

#include "keyManager.h"
#include "randomNumber.h"
#include "imageManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "sceneManager.h"
#include "soundManager.h"
#include "keyAnimManager.h"
#include "iniDataManager.h"
#include "LineManager.h"
#include "utils.h"

using namespace utils;