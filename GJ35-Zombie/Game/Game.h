#pragma once
#include <Dina.h>
#include "Player.h"

class Game : public Dina::Component
{
public:
	Game();
	~Game();

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

private:
	Player* m_Player = nullptr;
	Dina::Level* m_Level = nullptr;
	Dina::FPoint* m_Camera = nullptr;

};

