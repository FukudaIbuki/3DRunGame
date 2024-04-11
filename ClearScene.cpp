#include "ClearScene.h"
#include "ClearImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene")
{
}

void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void ClearScene::Draw()
{
}

void ClearScene::Release()
{
}
