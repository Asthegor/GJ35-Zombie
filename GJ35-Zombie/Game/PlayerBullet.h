#pragma once
#include <Dina.h>
class PlayerBullet : public Dina::Component
{
public:
	PlayerBullet(Dina::FPoint position, Dina::FPoint direction, double angle);
	~PlayerBullet();

	// Hérité via Component
	virtual void Load() override;
	virtual void Update(double deltatime) override;
	virtual void Draw() override;

	bool IsAway();
	//void SetLevelDimensions(Dina::Point levelDimensions);
	void SetCameraOffset(Dina::FPoint cameraOffset);

private:
	Dina::Texture* m_Texture = nullptr;
	Dina::FPoint m_Position;
	Dina::FPoint m_OriginPosition;
	Dina::FPoint m_Direction;

	Dina::FPoint m_CameraOffset;
	
	float m_Speed = 600.0;
	float m_MaxLength = 400.0;
	float m_Distance = 0.0;
};

