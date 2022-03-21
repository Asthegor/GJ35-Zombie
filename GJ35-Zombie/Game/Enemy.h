#pragma once
#include "Entity.h"
#include <Dina.h>

class Enemy : public Entity, Dina::Component
{

public:
	Enemy(Dina::FPoint position);

	
	void SetPosition(Dina::FPoint position);
	Dina::FPoint GetPosition() const;

	void SetDirection(Dina::FPoint direction);
	Dina::FPoint GetDirection() const;
	
	void SetAngle(double angle);
	double GetAngle() const;

	Dina::FPoint GetOrigin() const { return m_Origin; }
	Dina::Quad GetDimensions() const;

	void GetDamage(int damage);
	bool IsDead() const { return m_Life <= 0; }

public:
	void SetAnimation(std::string name);
	void SetCameraOffset(Dina::FPoint cameraOffset);
	
	// Hérité via Entity
	virtual std::string GetName() override;
	virtual void Load() override;
	virtual void Update(double deltatime);
	virtual void Draw() override;

	static const float DetectionDistance;
	static const float AttackDistance;

private:
	int m_Life = 100;
	int m_Speed = 35;

	std::map<std::string, Dina::Animation*> m_Animations;
	Dina::Animation* m_CurrentAnimation = nullptr;
	Dina::FPoint m_Position;
	Dina::FPoint m_Direction;
	Dina::FPoint m_Origin;
	Dina::FPoint m_CameraOffset;

	double m_Angle;
};

