#pragma once
#include "gameNode.h"

class progressBar: public gameNode
{
private:
	RECT _rctProgress;
	float _x, _y, _width;

	image* _progressBarFront;
	image* _progressBarBack;

public:
	progressBar() {};
	~progressBar() override {};

	HRESULT init(int x, int y, int width, int height);
	void release() override;
	void update() override;
	void render() override;

	// ���� ���� �ﰢ �ݿ��Ͽ� ������ �׸� �ʺ� �����ϴ� �Լ�
	void setGauge(float currVal, float maxVal);

	// ���� ���� �ð��� �ΰ� �ݿ��Ͽ� ������ �׸� �ʺ� �����ϴ� �Լ�
	void updateGauge(float currVal, float maxVal);

	void setX(float x) { _x = x; }
	void setY(float y) { _y = y; }
};

