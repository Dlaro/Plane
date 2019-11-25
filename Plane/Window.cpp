#include "DxLib.h"
#include "Core.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	
	LONGLONG Time=0;
	Core core(Time) ;
	ChangeWindowMode(1);
	SetBackgroundColor(0, 128, 128);
	// 画面モードの設定
	SetGraphMode(640, 480, 16);
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}

	// 描画先を裏画面にセット
    SetDrawScreen(DX_SCREEN_BACK);
	core.Initialize();
	ScreenFlip();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		core.Run();
	}
}
