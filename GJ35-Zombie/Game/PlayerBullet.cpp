#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(Dina::FPoint position, Dina::FPoint direction, double angle) :
	m_Position(position), m_OriginPosition(position), m_Direction(direction)
{
	DINA_INFO("PlayerBullet constructor");
	m_Texture = new Dina::Texture("Datas/Images/Game/Bullet.png");
	m_Texture->SetPosition(static_cast<int>(m_Position.x), static_cast<int>(m_Position.y));
	m_Texture->SetAngle(angle);
}

PlayerBullet::~PlayerBullet()
{}

void PlayerBullet::Load()
{}

void PlayerBullet::Update(double deltatime)
{
	// Déplacement de la balle
	m_Position.x += static_cast<float>(m_Direction.x * m_Speed * deltatime);
	m_Position.y += static_cast<float>(m_Direction.y * m_Speed * deltatime);


	// Affichage de la balle selon la caméra du joueur
	Dina::Quad oldPos = *m_Texture->GetDimensions();

	float x = 0.0f;
	float y = 0.0f;

	x = m_Position.x - m_CameraOffset.x;
	y = m_Position.y - m_CameraOffset.y;

	m_Texture->SetPosition(static_cast<int>(x), static_cast<int>(y));

	m_Distance = static_cast<float>(std::sqrt(std::pow((m_Position.x - m_OriginPosition.x), 2) + std::pow((m_Position.y - m_OriginPosition.y), 2)));
}

void PlayerBullet::Draw()
{
	if (!IsAway())
		Dina::Graphic::DrawTexture(m_Texture);
}

bool PlayerBullet::IsAway()
{
	return m_Distance >= m_MaxLength;
}

//void PlayerBullet::SetLevelDimensions(Dina::Point levelDimensions)
//{
//	m_LevelDimensions = levelDimensions;
//}

void PlayerBullet::SetCameraOffset(Dina::FPoint cameraOffset)
{
	m_CameraOffset = cameraOffset;
}
