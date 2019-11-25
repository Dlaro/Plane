#pragma once
#include"DxLib.h"
class Player
{
public:
	Player();
	void Move(int Input);
	void Move(VECTOR v, VECTOR p);
	void Draw();
	VECTOR GetPos();
	VECTOR GetDir();
	VECTOR GetNor();
	VECTOR GetVel();
	float GetRad();
	void SetPos(float x,float y,float z);
	void SetNor(VECTOR n);
private:
	float x, y, z;
	float velx, vely, velz;
	float rad;
	VECTOR vel,pos,dir,nor;

};

