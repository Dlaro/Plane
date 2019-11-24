#pragma once
#include"DxLib.h"
class Player
{
public:
	Player();
	void Move(int Input);
	void Draw();
	VECTOR GetPos();
private:
	float x, y, z;
	float velx, vely, velz;
};

