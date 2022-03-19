#include "Enemy.h"

const float Enemy::DectionDistance = 500.0f;

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
		m_CurrentAnimation = m_Animations.at(name);
}

void Enemy::SetPosition(Dina::FPoint position)
{
	m_Position = position;
	m_CurrentAnimation->SetPosition(static_cast<int>(m_Position.x), static_cast<int>(m_Position.y));
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
	if (m_CurrentAnimation)
		m_CurrentAnimation->Update(deltatime);
}

void Enemy::Draw()
{
	if (m_CurrentAnimation)
		m_CurrentAnimation->Draw();
}
