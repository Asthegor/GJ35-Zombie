#pragma once
#include <Dina.h>

class MainMenu : public Dina::Component
{
public:
	MainMenu();
	~MainMenu();

	// H�rit� via Component
	virtual void Update(double deltatime) override;
	virtual void Draw() override;
	virtual void Load() override;

	// H�rit� via Component::Event
	virtual void OnKeyPressed(Dina::KeyCode key) override;
	virtual void OnKeyReleased(Dina::KeyCode key) override;
	
	virtual void OnMouseMove(int x, int y);
	virtual void OnMousePressed(int button, int x, int y, int clicks);
	virtual void OnMouseReleased(int button, int x, int y);


private:
	void OnPlayPressed();
	void OnCreditsPressed();
	void OnQuitGame();
	void OnHover(Dina::MenuItem* menuItem, bool state);

	Dina::MenuManager* m_MenuManager = nullptr;
};

