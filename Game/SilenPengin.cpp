#include "stdafx.h"
#include "Player.h"
#include "SilenPengin.h"

bool SilenPengin::Start() {
	g_soundEngine->ResistWaveFileBank(1, "Assets/Sound/silen.wav");
	m_animationClips[enAnimClip_Chase].Load("Assets/animData/pengin_chase.tka");
	m_animationClips[enAnimClip_Chase].SetLoopFlag(false);
	m_modelRender.Init("Assets/modelData/silenPengin.tkm", m_animationClips, enAnimClip_Num, enModelUpAxisZ);
	m_pos = { 0.0f,0.0f,500.0f };
	m_modelRender.SetScale(10.0f, 10.0f, 10.0f);

	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
	}

	m_pos.x = m_player->m_position.x += 3000.0f;
	m_rot.SetRotationDegY(-90.0f);
	m_modelRender.SetRotation(m_rot);
	m_modelRender.SetPosition(m_pos);
	m_modelRender.Update();
	return true;
}

void SilenPengin::Update() {
	m_coolTime -= 0.1f;
	if (m_coolTime > 0.0f) {
		m_pos = { m_player->m_position.x,0.0f,m_player->m_position.z };
		m_pos.x += 3000.0f;
	}
	if (m_coolTime <= 35.0f) {
		for (; m_silen < 1; m_silen++) {
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(1);
			se->Play(false);
			se->SetVolume(2.5f);
		}
	}
	if (m_coolTime <= 0.0f) {
		m_pos.x -= 50.0f;
	}
	if (m_coolTime <= -1000.0f) {
		m_coolTime = 100.0f;
	}
	m_modelRender.SetPosition(m_pos);
	m_modelRender.Update();
}

void SilenPengin::Render(RenderContext& rc) {
	if (m_coolTime <= 0.0f and m_coolTime >= -100.0f) {
		m_modelRender.Draw(rc);
	}
}
