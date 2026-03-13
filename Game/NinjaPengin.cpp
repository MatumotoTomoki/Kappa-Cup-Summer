#include "stdafx.h"
#include "NinjaPengin.h"
#include "Player.h"

bool NinjaPengin::Start() {
	m_characterController.Init(25.0f, 75.0f, m_pos);
	m_animationClips[enAnimClip_Walk].Load("Assets/animData/pengin_walk.tka");
	m_animationClips[enAnimClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimClip_Chase].Load("Assets/animData/pengin_chase.tka");
	m_animationClips[enAnimClip_Chase].SetLoopFlag(false);
	m_modelRender.Init("Assets/modelData/pengin.tkm", m_animationClips, enAnimClip_Num, enModelUpAxisZ);
	m_pos = { 0.0f,0.0f,1000.0f };
	m_modelRender.SetScale(10.0f, 10.0f, 10.0f);
	m_modelRender.SetRotation(m_rot);
	m_modelRender.SetPosition(m_pos);

	m_modelRender.Update();
	return true;
}

void NinjaPengin::Update() {
	if (m_player == nullptr) {
		m_player = FindGO<Player>("Player");
		return;
	}

	Vector3 diff = m_player->m_position - m_pos;
	if (diff.Length() <= 1000.0f and m_player->m_swim == false) {
		m_modelRender.PlayAnimation(enAnimClip_Chase);
		float distToPlayer = diff.Length();

		Vector3 toPlayerDir = diff;
		toPlayerDir.Normalize();

		m_pos += toPlayerDir * 8.0f;

		float angleY = atan2f(toPlayerDir.x, toPlayerDir.z);

		// ラジアンを度数に変換し、回転行列を作成
		m_rot.SetRotationY(angleY);

		m_stealth = false;

	}
	else if (m_player->m_swim == true) {
		Vector3 diff = m_pos - m_player->m_position;
		float distToPlayer = diff.Length();

		Vector3 toPlayerDir = diff;
		toPlayerDir.Normalize();

		m_pos += toPlayerDir * 5.0f;

		float angleY = atan2f(toPlayerDir.x, toPlayerDir.z);
		m_rot.SetRotationY(-angleY);

		m_stealth = true;
	}
	else {
		m_stealth = true;
		m_rot.SetRotationDegY(180.0f);
	}

	m_pos.y = 0.0f;
	m_pos.z -= 1.0f;

	m_modelRender.SetRotation(m_rot);
	m_modelRender.SetPosition(m_pos);
	m_modelRender.Update();
}

void NinjaPengin::Render(RenderContext& rc) {
	if (m_stealth == false) {
		m_modelRender.Draw(rc);
	}
}
