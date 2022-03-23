#include "Bullet.h"

Bullet::Bullet(Dina::FPoint position, Dina::FPoint direction, double angle) :
    m_Position(position), m_OriginPosition(position), m_Direction(direction)
{
	DINA_INFO("Bullet constructor");
    m_Texture = new Dina::Texture("Datas/Images/Game/Bullet.png");
    m_Texture->SetPosition(static_cast<int>(m_Position.x), static_cast<int>(m_Position.y));
    m_Texture->SetAngle(angle);
}

std::string Bullet::GetName()
{
    return "Bullet";
}

void Bullet::Load()
{}

void Bullet::ToDelete(bool toDelete)
{
	m_ToDelete = toDelete;
}

bool Bullet::ToDelete()
{
	return m_ToDelete;
}

void Bullet::Update(double deltatime)
{
	// Déplacement de la balle
	m_Position.x += static_cast<float>(m_Direction.x * m_Speed * deltatime);
	m_Position.y += static_cast<float>(m_Direction.y * m_Speed * deltatime);

	float x = 0.0f;
	float y = 0.0f;

	x = m_Position.x - m_CameraOffset.x;
	y = m_Position.y - m_CameraOffset.y;

	m_Texture->SetPosition(static_cast<int>(x), static_cast<int>(y));

	m_Distance = static_cast<float>(std::sqrt(std::pow((m_Position.x - m_OriginPosition.x), 2) + std::pow((m_Position.y - m_OriginPosition.y), 2)));
	if (m_Distance > m_MaxLength)
		m_ToDelete = true;
}

void Bullet::Draw()
{
	if (!ToDelete())
		Dina::Graphic::DrawTexture(m_Texture);
	
	Dina::Graphic::DrawPoint({ static_cast<int>(m_Position.x), static_cast<int>(m_Position.y) }, { 255,0,0,255 });

	
}

void Bullet::SetCameraOffset(Dina::FPoint cameraOffset)
{
	m_CameraOffset = cameraOffset;
}