#pragma once
#include "Engine/GameObject.h"
class CDTimer :
    public GameObject
{
private:
	double CountDownTimer_;
	double TIMER_INIT_TIME_;
	bool isTimerRun_;
	DWORD oldTime_;
public:
	CDTimer(GameObject* parent);
	CDTimer(GameObject* parent, double _initTime);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
public:
    bool IsTimeOver();
    void ResetTimer();
    void StartTimer();
    void StopTimer();
	bool IsTimeRun() { return (isTimerRun_); }
	void SetInitTime(double cdTime) { TIMER_INIT_TIME_; }
	double GetTime() { return(CountDownTimer_); }
};

