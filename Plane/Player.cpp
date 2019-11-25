#include "Player.h"
#include "DxLib.h"
#include <cmath>


Player::Player() {

	x = 5000;
	y = 500;
	z = 0;
	vel = VGet(0, 0, 0);
	pos = VGet(x, y, z);
	dir = VGet(0, 0, 1);
	rad = 0.0f;
	nor = VGet(0, -1, 0);
}

void Player::Draw() {
	DrawSphere3D(GetPos(), 80.0f, 32, GetColor(0, 0, 255), GetColor(255, 255, 255), 1);
}

void Player::Move(int input) {

	


	if ((input & PAD_INPUT_UP) != 0) {
		if ((input & PAD_INPUT_10) != 0) {
			if (VSize(vel) >= 500)  vel = VScale(dir, 500);
			else vel = VAdd(vel, VScale(dir, 60));
		}
		else {
			if (VSize(vel) >= 300)  vel = VScale(dir, 300);
			else vel = VAdd(vel, VScale(dir, 30));
		}
		if ((input & PAD_INPUT_LEFT) != 0) {


			rad -= DX_PI_F / 120.0f; vel = VTransform(vel, MGetRotY(-DX_PI_F / 120.0f));
			if (VSize(vel) != 0)dir = VNorm(vel);
		}

		if ((input & PAD_INPUT_RIGHT) != 0) {

			rad += DX_PI_F / 120.0f; vel = VTransform(vel, MGetRotY(DX_PI_F / 120.0f));
			if (VSize(vel) != 0)dir = VNorm(vel);
		}
	}
	if ((input & PAD_INPUT_UP) == 0 && (input & PAD_INPUT_DOWN) == 0) {
		if (VSize(vel) > 10) vel = VSub(vel, VScale(dir, 10));
		else vel = VGet(0, 0, 0);
	}
	if ((input & PAD_INPUT_DOWN) != 0) {


	}
	
	if ((input & PAD_INPUT_LEFT) == 0 && (input & PAD_INPUT_RIGHT) == 0) {

	}

	if (VSize(vel) != 0)dir = VNorm(vel);
	pos = VAdd(pos, vel);
}
void Player::Move(VECTOR v, VECTOR p) {

	
	pos = VAdd(p, v);
}

VECTOR Player::GetPos() {

	return pos;
}

VECTOR Player::GetDir() {

	return dir;
}
float Player::GetRad() {
	return rad;
}
VECTOR Player::GetNor() {
	return nor;

}
VECTOR  Player::GetVel() {
	return vel;
}
void Player::SetPos(float x, float y, float z) {
	Player::x = x;
	Player::y = y;
	Player::z = z;
}
void  Player::SetNor(VECTOR n) {
	nor =VScale( n,-1);
}
