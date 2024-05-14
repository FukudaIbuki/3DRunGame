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

	//èâä˙âª
	void Initialize() override;

	//çXêV
	void Update() override;

	//ï`âÊ
	void Draw() override;

	//äJï˙
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

