#pragma once
#include "singleton.h"

struct tagIniDatum
{
	const char* subject;
	const char* title;
	const char* body;
};

class iniDataManager : public singleton<iniDataManager>
{
private:
	typedef vector<tagIniDatum>				iniDatum;
	typedef vector<tagIniDatum>::iterator	iniDatumIter;

	typedef vector<iniDatum>				iniData;
	typedef vector<iniDatum>::iterator	iniDataIter;

private:
	iniData _vIniData;


public:
	iniDataManager();
	~iniDataManager();

	HRESULT init();
	
	// ������ �߰� �Լ�
	void addData(const char* subject, const char* title, const char* body);

	// ini ���� ���� �Լ�
	void iniSave(const char* fileName);

	// �����͸� ���ڿ��� �ε��ϴ� �Լ�
	string loadDataString(const char* fileName, const char* subject, const char* title);

	// �����͸� ������ �ε��ϴ� �Լ�
	int loadDataInteger(const char* fileName, const char* subject, const char* title);

};

