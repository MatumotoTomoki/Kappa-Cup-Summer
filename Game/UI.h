#pragma once
class UI : public IGameObject
{
public:
	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	SpriteRender m_spriteRender;
};

