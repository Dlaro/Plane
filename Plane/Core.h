#pragma once
#include<math.h>
#include"DxLib.h"
#include"Map.h"
#include"Player.h"
class Core
{

public:
	Core(long long time);
	void Run();
	void Initialize();

private:
	long long time;
	   	 
	void Update();
	void Draw();


	VECTOR CamPos;		// カメラの座標
	VECTOR CamTarg;	// カメラの注視点
	int Muki;
	int Input;
	Map map;
	Player player;
	int playerMHandle;
	int mapMHandle;

	VECTOR	SlideVec;
};

