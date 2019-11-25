#pragma once
#include <map>
#include <string>
#include "Map.h"
#include "Player.h"
#include "DxLib.h"
class Manager
{
public:

	void Initialize();
	void Update();
	

protected:
	
};

class PhysicsManager :Manager
{
public:

	void Initialize();
	void Update();
	

private:
	Map map;
	Player player;

};

class ModelManager :Manager
{
public:

	void Initialize();
	void Update();
	void LoadModel(std::string file, std::string name);
	//void DrawModel(std::string name,)


private:
	std::map<std::string, int> modelList;
};


