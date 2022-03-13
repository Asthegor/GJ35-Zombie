#pragma once
#include <Dina.h>
#include <map>

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

	// Hérité de Component::Event::KeyboardEvent
	virtual void OnKeyPressed(Dina::KeyCode key) override;
	virtual void OnKeyReleased(Dina::KeyCode key) override;
	virtual void OnKeyRepeat(Dina::KeyCode key) override;

	// Hérité de Component::Event::MouseEvent
	virtual void OnMouseMove(int x, int y);
	virtual void OnMousePressed(int button, int x, int y, int clicks);
	virtual void OnMouseReleased(int button, int x, int y);

	Dina::FPoint* GetPosition();
	void SetPosition(Dina::FPoint* point);
	Dina::FPoint* GetCameraPosition();
	void SetCameraPosition(Dina::FPoint* point);
	Dina::Quad GetDimensions();

private:
	bool m_CanShootPrincipal = true;
	bool m_CanShootSecondary = true;

	std::map<std::string, Dina::Animation*> m_Animations;
	Dina::Animation* m_CurrentAnimation = nullptr;

	Dina::Quad* m_Dimensions = nullptr;
	Dina::FPoint* m_Position = nullptr;
	Dina::FPoint* m_CameraPosition = nullptr;

	int m_Direction = 0;

	int m_Speed = 0;

	std::string m_Weapon = "";
	std::string m_Action = "";

	double m_Angle = 0.0;
};

