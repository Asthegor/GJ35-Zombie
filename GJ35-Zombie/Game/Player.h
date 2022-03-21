#pragma once
#include <Dina.h>
#include <map>
#include <vector>
#include "PlayerBullet.h"

enum Direction
{
	None = 0, Up = 1, Right = 2, UpperRight = 3, Down = 4, DownerRight = 6, Left = 8, UpperLeft = 9, DownerLeft = 12
};

class Player : public Dina::Component
{
public:
	Player();
	~Player();

	// Hérité via Component
	virtual void Load() override;
	virtual void Update(double deltatime) override;
	virtual void Draw() override;

	void SetLevelDimensions(Dina::Point const levelDimensions);

	// Hérité de Component::Event::KeyboardEvent
	virtual void OnKeyPressed(Dina::KeyCode key) override;
	virtual void OnKeyReleased(Dina::KeyCode key) override;
	virtual void OnKeyRepeat(Dina::KeyCode key) override;

	// Hérité de Component::Event::MouseEvent
	virtual void OnMouseMove(int x, int y);

	void SetPosition(Dina::FPoint point);
	void SetCameraPosition(Dina::FPoint point);
	Dina::Quad GetDimensions();
	Dina::Point GetOrigin();

	Dina::FPoint* GetPosition() { return m_Position; }
	Dina::FPoint GetOrientation() { return m_Orientation; }
	Dina::FPoint* GetCameraPosition() { return m_CameraPosition; }

	double GetAngle() { return m_Angle; }

	bool CanShoot() { return m_CanShoot; }
	void CanShoot(bool canShoot);

private:
	bool m_CanShoot = true;
	double m_ShootTimer = 0.0;
	double m_ShootDelay = 1.0;

	std::map<std::string, Dina::Animation*> m_Animations;
	Dina::Animation* m_CurrentAnimation = nullptr;

	Dina::Quad* m_Dimensions = nullptr;
	Dina::FPoint* m_Position = nullptr;
	Dina::FPoint* m_CameraPosition = nullptr;
	Dina::Point m_LevelDimensions;
	Dina::FPoint m_CameraOffset;
	Dina::FPoint m_Orientation;


	int m_Move = 0;

	int m_Speed = 0;

	std::string m_Weapon = "";
	std::string m_Action = "";

	double m_Angle = 0.0;

	std::vector<PlayerBullet*> m_Bullets;
};

