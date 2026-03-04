#include "stdafx.h"
#include "UI.h"

bool UI::Start()
{
	m_spriteRender.Init("Assets/sprite/distance.DDS", 0.0f, 0.0f);
	m_spriteRender2.Init("Assets/sprite/hpGaugeFrame.DDS", 0.0f, 0.0f);
	m_spriteRender3.Init("Assets/sprite/hpGauge.DDS", 0.0f, 0.0f);
	m_spriteRender4.Init("Assets/sprite/O2GaugeFrame.DDS", 0.0f, 0.0f);
	m_spriteRender5.Init("Assets/sprite/O2Gauge.dds", 0.0f, 0.0f);
}

void UI::Update()
{
	m_spriteRender.Update();
	m_spriteRender2.Update();
	m_spriteRender3.Update();
	m_spriteRender4.Update();
	m_spriteRender5.Update();
}

void UI::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
	m_spriteRender2.Draw(rc);
	m_spriteRender3.Draw(rc);
	m_spriteRender4.Draw(rc);
	m_spriteRender5.Draw(rc);
}
