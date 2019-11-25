#include "Core.h"
#include "DxLib.h"
#include<iostream>

MV1_COLL_RESULT_POLY_DIM HitPolyDim;
MV1_COLL_RESULT_POLY HitPoly;

Core::Core(long long time) {

	Core::time = time;
	CamPos = VGet(5000.0f, 500.0f, 0.0f);
	CamTarg = VGet(5000.0f, 0.0f, 1000.0f);

}

void Core::Run() {
	Update();
	Draw();
}

void Core::Initialize() {
	Muki = 0;
	
	SetUseZBuffer3D(TRUE);
	map.Initialize();
	playerMHandle = MV1LoadModel("123.mv1");
	MV1SetScale(playerMHandle, VGet(100.0f, 100.0f, 100.0f));
	MV1SetRotationXYZ(playerMHandle, VGet(0.0f, DX_PI_F / 2.0f, 0.0f));

	mapMHandle = MV1LoadModel("road1.mv1");
	MV1SetScale(mapMHandle, VGet(300.0f, 300.0f, 300.0f));
	MV1SetRotationXYZ(mapMHandle, VGet(0.0f, DX_PI_F / 2.0f, 0.0f));
	MV1SetPosition(mapMHandle, VGet(5000.0f, 0.0f, 4000.0f));
	MV1SetupCollInfo(mapMHandle, 1, 8, 8, 8);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);
	//MV1SetUseZBuffer(playerMHandle, TRUE);
	//MV1SetWriteZBuffer(playerMHandle, TRUE);

}
void Core::Update() {
	VECTOR pos_pre = player.GetPos();
	Input = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	player.Move(Input);

	HitPolyDim = MV1CollCheck_Sphere(mapMHandle, 1, player.GetPos(), 200.0f);
	
	if (HitPolyDim.HitNum >= 1)
	{
		VECTOR a = HitPolyDim.Dim->Normal;
		a.y = 0;
		// 進行方向ベクトルと壁ポリゴンの法線ベクトルに垂直なベクトルを算出
		SlideVec = VCross(player.GetDir(),a);

		// 算出したベクトルと壁ポリゴンの法線ベクトルに垂直なベクトルを算出、これが
		// 元の移動成分から壁方向の移動成分を抜いたベクトル
		SlideVec = VCross( a, SlideVec);
		

		player.Move(VScale( SlideVec,100), pos_pre);
		
	}
	HitPoly = MV1CollCheck_Line(mapMHandle, 1, player.GetPos(), VAdd(player.GetPos(), VScale(player.GetNor(), 500)));
	if (HitPoly.HitFlag) {

		player.SetNor(HitPoly.Normal);
			
	}

	CamTarg = player.GetPos();
	CamPos =VAdd( VAdd(player.GetPos(), VScale(player.GetDir(),-1000)),VGet(0,500,0));

	MV1SetPosition(playerMHandle, player.GetPos());
	MV1SetRotationXYZ(playerMHandle, VGet(0.0f, player.GetRad()+ DX_PI_F / 2.0f, 0.0f));

	
	
	// カメラの位置と向きをセットする
	SetCameraPositionAndTarget_UpVecY(CamPos, CamTarg);

}


void Core::Draw() {
	ClearDrawScreen();
	//map.Draw();
	//player.Draw();

	MV1DrawFrame(playerMHandle, 0);
	DrawSphere3D(player.GetPos(), 200.0f, 8, GetColor(255, 255, 0), GetColor(255, 255, 255), FALSE);
	MV1DrawFrame(mapMHandle, 1);
	DrawLine3D(player.GetPos(),VAdd(player.GetPos(), VScale(player.GetNor(),500)), GetColor(255, 0, 255));

	if (HitPolyDim.HitNum >= 1)
	{
		// 当たった場合は衝突の情報を描画する
		
		// 当たったポリゴンの数を描画
		DrawFormatString(0, 0, GetColor(255, 255, 255), "Hit Poly Num   %d", HitPolyDim.HitNum);
		DrawFormatString(0, 50, GetColor(255, 255, 255), "SlideVec   %d,%d,%d", SlideVec.x
			, SlideVec.y, SlideVec.z);
		DrawFormatString(0, 100, GetColor(255, 255, 255), "dir   %d,%d,%d", player.GetDir().x
			, player.GetDir().y, player.GetDir().z);

		// 当たったポリゴンの数だけ繰り返し
		for (int i = 0; i < HitPolyDim.HitNum; i++)
		{
			// 当たったポリゴンを描画
			DrawTriangle3D(
				HitPolyDim.Dim[i].Position[0],
				HitPolyDim.Dim[i].Position[1],
				HitPolyDim.Dim[i].Position[2], GetColor(0, 255, 255), TRUE);
		}
	}

	//DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), 1);
	//DrawSphere3D(VGet(240.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), 1);
	ScreenFlip();
	Sleep(10);
}
