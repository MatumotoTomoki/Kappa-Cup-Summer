#pragma once

#include "Level3DRender/LevelRender.h"

class GameCamera;
class Player;
class UI;
class Game : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	PhysicsStaticObject m_physicsStaticObject;
	ModelRender m_modelRender;
	Vector3 m_pos;
	ModelRender m_stageRender;
	LevelRender m_stageLevelRnder;
	SkyCube* m_skyCube;
	SoundSource* m_gameBGM = nullptr;
	UI* m_ui;
	int m_skyCubeType = enSkyCubeType_Day;
	
};

