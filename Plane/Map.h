#pragma once
#include "DxLib.h"
#include <vector>

class Map
{
public:
	Map();
	void Initialize();
	void Draw();

private:
	std::vector<VECTOR> mapList;

	
};

