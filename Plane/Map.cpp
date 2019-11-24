#include "Map.h"
#include "DxLib.h"
#include <vector>
Map::Map() {

}

void Map::Initialize() {

	mapList = { 
		{5000.0f,0.0f,1000.0f},
		{5000.0f,0.0f,2000.0f},
		{5000.0f,0.0f,3000.0f},
		{5000.0f,0.0f,4000.0f},
		{5000.0f,0.0f,5000.0f},
		{5000.0f,0.0f,6000.0f},
		{5000.0f,0.0f,7000.0f},
		{5000.0f,0.0f,8000.0f},
		{5000.0f,0.0f,9000.0f},
		{5000.0f,0.0f,10000.0f},
		{5000.0f,0.0f,11000.0f},
		{5000.0f,0.0f,12000.0f},
		{5000.0f,0.0f,13000.0f},
		{5000.0f,0.0f,14000.0f},
		{5000.0f,0.0f,15000.0f},
		{5000.0f,0.0f,16000.0f},
		{5000.0f,0.0f,17000.0f},
		{5000.0f,0.0f,18000.0f},
		{5000.0f,0.0f,19000.0f},
		{5000.0f,0.0f,20000.0f},
	
	
	};
}

void Map::Draw() {
	//DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), 1);
	for (auto v : mapList) {
		DrawSphere3D(VAdd(v,VGet(1000.0f,0.0f,0.0f)), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), 1);
		DrawSphere3D(VAdd(v, VGet(-1000.0f, 0.0f, 0.0f)), 80.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), 1);
	}
}