#include "Enemy.h"

const float Enemy::DetectionDistance = 500.0f;
const float Enemy::AttackDistance = 50.0f;

Enemy::Enemy(Dina::FPoint position)
{
	std::string path = "Datas/Images/Game/Zombie";
	std::string prefixFile = "zombie-";
	std::string extension = ".png";
	Dina::Animation* animation = nullptr;
	// idle
	{
		std::string action = "idle";
		Dina::Point* origin = new Dina::Point { 29,46 };

		std::string prefix = path + "/" + action + "/" + prefixFile + action + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 16, 0.2);
		animation->SetOrigin(origin);
		m_Animations[action] = animation;
	}
	// attack
	{
		std::string action = "attack";
		Dina::Point* origin = new Dina::Point { 29,46 };

		std::string prefix = path + "/" + action + "/" + prefixFile + action + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 9, 0.2);
		animation->SetOrigin(origin);
		m_Animations[action] = animation;
	}
	// move
	{
		std::string action = "move";
		Dina::Point* origin = new Dina::Point { 29,46 };

		std::string prefix = path + "/" + action + "/" + prefixFile + action + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 17, 0.2);
		animation->SetOrigin(origin);
		m_Animations[action] = animation;
	}

	SetAnimation("idle");
	SetPosition(position);
	float rndDirX = static_cast<float>(Dina::Random::GetValue(0.0, 2.0) - 1.0);
	float rndDirY = static_cast<float>(Dina::Random::GetValue(0.0, 2.0) - 1.0);
	DINA_INFO("Enemy direction : {0}, {1}", rndDirX, rndDirY);
	SetDirection({ rndDirX, rndDirY });

}

void Enemy::SetDirection(Dina::FPoint direction)
{
	m_Direction = direction;
}

Dina::FPoint Enemy::GetDirection() const
{
	return m_Direction;
}

void Enemy::SetAngle(double angle)
{
	m_Angle = angle;
}

double Enemy::GetAngle() const
{
	return m_Angle;
}

Dina::Quad Enemy::GetDimensions() const
{
	return *m_CurrentAnimation->GetDimensions();
}

void Enemy::GetDamage(int damage)
{
	m_Life -= damage;
}

void Enemy::SetAnimation(std::string name)
{
	if (m_Animations.at(name))
	{
		m_CurrentAnimation = m_Animations.at(name);
		float x = m_Position.x - m_CameraOffset.x;
		float y = m_Position.y - m_CameraOffset.y;
		m_CurrentAnimation->SetPosition(static_cast<int>(x), static_cast<int>(y));
		m_CurrentAnimation->SetRotation(m_Angle);
	}
}

void Enemy::SetPosition(Dina::FPoint position)
{
	m_Position = position;
}

Dina::FPoint Enemy::GetPosition() const
{
	return m_Position;
}


std::string Enemy::GetName()
{
    return "Enemy";
}

void Enemy::Load()
{}

void Enemy::Update(double deltatime)
{
	m_Position.x += static_cast<float>(m_Direction.x * deltatime * m_Speed);
	m_Position.y += static_cast<float>(m_Direction.y * deltatime * m_Speed);
	float x = m_Position.x - m_CameraOffset.x;
	float y = m_Position.y - m_CameraOffset.y;
	m_CurrentAnimation->SetPosition(static_cast<int>(x), static_cast<int>(y));
	m_CurrentAnimation->Update(deltatime);
}

void Enemy::Draw()
{
	Dina::Quad* dimensions = m_CurrentAnimation->GetDimensions();
	Dina::Quad* screen = Dina::Graphic::GetDimensions();
	if (dimensions->x >= 0 - dimensions->width * 2 && dimensions->x <= screen->width + dimensions->width * 2 &&
		dimensions->y >= 0 - dimensions->height * 2 && dimensions->y <= screen->height + dimensions->height * 2)
		m_CurrentAnimation->Draw();
}

void Enemy::SetCameraOffset(Dina::FPoint cameraOffset)
{
	m_CameraOffset = cameraOffset;
}