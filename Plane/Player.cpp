#include "Player.h"
#include "DxLib.h"


Player::Player() {
	x = 5000;
	y = 0;
	z = 0;
	velx = 0;
	vely = 0;
	velz = 0;
}

void Player::Draw() {
	DrawSphere3D(GetPos(), 80.0f, 32, GetColor(0, 0, 255), GetColor(255, 255, 255), 1);
}
void Player::Move(int input) {
	if ((input & PAD_INPUT_UP) != 0) velz = (velz+10)>200?200:velz+10;
	if((input & PAD_INPUT_UP) == 0 &&(input & PAD_INPUT_DOWN) == 0)velz = (velz - 10) < 0 ? 0 : velz - 10;
	if ((input & PAD_INPUT_DOWN) != 0) velz = (velz -10) <- 100 ? -100 : velz - 10;
	if ((input & PAD_INPUT_LEFT) != 0) velx = (velx - 5) < -50 ? -50 : velx - 5;
	if ((input & PAD_INPUT_LEFT) == 0 && (input & PAD_INPUT_RIGHT) == 0) velx = (velx + 5) > 0 ? 0 : velx + 5;
	if ((input & PAD_INPUT_RIGHT) != 0) velx = (velx + 5) >50 ? 50 : velx +5;

	x += velx;
	y += vely;
	z += velz;
}

VECTOR Player::GetPos() {
	return VGet(x, y, z);
}

