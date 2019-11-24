#include "Core.h"
#include "DxLib.h"

Core::Core(long long time) {
	
	Core::time = time;
    
}

void Core::Run() {
	Update();
	Draw();
}

void Core::Initialize() {
	Muki = 0;
	CamPos = VGet(5000.0f, 500.0f,0.0f );
	CamTarg = VGet(5000.0f, 0.0f, 1000.0f);
	SetUseZBuffer3D(TRUE);
	map.Initialize();
	
	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);
	// ３Ｄ空間上に球を描画する
	DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
	DrawSphere3D(VGet(140.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
}
void Core::Update() {
	
	Input = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	player.Move(Input);

	CamTarg =VAdd( player.GetPos(),VGet(0,0,1000));
	CamPos = VAdd(player.GetPos(), VGet(0, 500, -1000));


	
	// カメラの位置と向きをセットする
	SetCameraPositionAndTarget_UpVecY(CamPos, CamTarg);

}


void Core::Draw() {
	ClearDrawScreen();
	map.Draw();
	player.Draw();
	//DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), 1);
	//DrawSphere3D(VGet(240.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), 1);
	ScreenFlip();
}
