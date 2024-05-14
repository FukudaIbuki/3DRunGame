#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/Debug.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), moveDir_(MNONE), cdtimer_(nullptr)
{
}

void Player::Initialize()
{
	cdtimer_ = new CDTimer(this, DTIME);
	cdtimer_->StopTimer();
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);

}

void Player::GetInputData()
{
	//moveDir_ = MNONE;

	if (Input::IsKeyDown(DIK_LEFT) || Input::IsKeyDown(DIK_D))
	{

		moveDir_ = MLEFT;
		cdtimer_->ResetTimer();
		cdtimer_->StartTimer();
		V[0] = XMLoadFloat3(&transform_.position_);
		V[1] = moveVec[moveDir_];
	}
	if (Input::IsKeyDown(DIK_RIGHT) || Input::IsKeyDown(DIK_A))
	{
		moveDir_ = MRIGHT;
		cdtimer_->ResetTimer();
		cdtimer_->StartTimer();
		V[0] = XMLoadFloat3(&transform_.position_);
		V[1] = moveVec[moveDir_];
	}
}

void Player::Update()
{
	cdtimer_->Update();//カウントダウン

	float lerpRate = 1.0f - cdtimer_->GetTime() / DTIME;
	Debug::Log(cdtimer_->IsTimeRun(), true);
	GetInputData();
	if (moveDir_ == MNONE)
		return;

	if (cdtimer_->IsTimeRun())
	{
		float lerpRate = 1.0f - cdtimer_->GetTime() / DTIME;
		XMVECTOR pos = XMVectorLerp(V[0], V[1], lerpRate);
		XMStoreFloat3(&transform_.position_, pos);

		float rotAngle = 90.0 * sin(lerpRate * XM_PIDIV2);

		if (XMVectorGetX(V[1]) < XMVectorGetX(V[0]))
		{
			rotAngle = -rotAngle;
		}
		transform_.rotate_.y = rotAngle;
	}

	if (cdtimer_->GetTime() <= 0)
	{
		//XMVECTOR pos = XMLoadFloat3(&transform_.position_);
		//pos = pos + moveVec[moveDir_];
		//XMStoreFloat3(&transform_.position_, pos);
		moveDir_ = MNONE;
		cdtimer_->StopTimer();
	}
	//左右キー(A,D)で左右（x座標で）5.0移動する
}

void Player::Draw()
{
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
