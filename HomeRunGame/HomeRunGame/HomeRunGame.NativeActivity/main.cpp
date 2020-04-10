#include "DxLib.h"
#include "SceneManager.hpp"
#include "Fps.hpp"

int android_main(void)
{
	SetGraphMode(720, 1280, 32);
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Fps *fps = new Fps();
	SceneManager *sceneManager = new SceneManager();

	while (ScreenFlip()      == 0 &&
		   ProcessMessage()  == 0 &&
		   ClearDrawScreen() == 0) 
	{
		fps->Update();

		sceneManager->Update();
		sceneManager->Draw();
		
		fps->Wait();
	}

	delete fps;
	delete sceneManager;

	DxLib_End();
	return 0;
}