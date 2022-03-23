#pragma once
#include "Entity.h"
#include <Dina.h>

class Bullet : public Entity, Dina::Component
{
public:
	Bullet(Dina::FPoint position, Dina::FPoint direction, double angle);

	void SetCameraOffset(Dina::FPoint cameraOffset);
	bool IsAway();

public:

	// Hérité via Entity
	virtual std::string GetName() override;
	// Hérité via Component
	virtual void Draw();
	virtual void Update(double deltatime);
	virtual void Load();

	Dina::FPoint GetPosition() { return m_Position; }
	int GetDamagePoints() const {return m_DamagePoints; }

	void ToDelete(bool toDelete);
	bool ToDelete();
private:

	Dina::Texture* m_Texture = nullptr;
	Dina::FPoint m_Position;
	Dina::FPoint m_OriginPosition;
	Dina::FPoint m_Direction;

	Dina::FPoint m_CameraOffset;

	bool m_ToDelete = false;
	float m_Speed = 600.0;
	float m_MaxLength = 400.0;
	float m_Distance = 0.0;

	int m_DamagePoints = 50;
};

