#include "Game.h"

Game::Game()
{
	m_Player = new Player;
	m_Level = new Dina::Level;
	m_Camera = new Dina::FPoint;
}
Game::~Game()
{
	delete m_Player;
	delete m_Level;
	delete m_Camera;
}

// Hérité de Component
void Game::Load()
{
	if (m_Player)
		m_Player->Load();
	if (m_Level)
		m_Level->Load("Datas/Maps/Level01.tmx");
}
void Game::Update(double deltatime)
{
	Dina::Quad playerOriDim = m_Player->GetDimensions();
	if (m_Player)
		m_Player->Update(deltatime);
	Dina::Quad playerDimensions = m_Player->GetDimensions();
	Dina::Quad* screen = Dina::Graphic::GetDimensions();
	Dina::Point levelDimensions = m_Level->GetDimensions();

	float pX = 0.0f;
	float pY = 0.0f;


	if (playerDimensions.x < screen->width / 2)
	{
		m_Camera->x = 0.0f;
		pX = playerDimensions.x;
	}
	else if (playerDimensions.x > levelDimensions.x - screen->width / 2)
	{
		m_Camera->x = levelDimensions.x - screen->width;
		pX = playerDimensions.x - levelDimensions.x + screen->width;
	}
	else
	{
		m_Camera->x = playerDimensions.x - screen->width / 2;
		pX = screen->width / 2;
	}


	if (playerDimensions.y < screen->height / 2)
	{
		m_Camera->y = 0.0f;
		pY = playerDimensions.y;
	}
	else if (playerDimensions.y > levelDimensions.y - screen->height / 2)
	{
		m_Camera->y = levelDimensions.y - screen->height;
		pY = playerDimensions.y - levelDimensions.y + screen->height;
	}
	else
	{
		m_Camera->y = playerDimensions.y - screen->height / 2;
		pY = screen->height / 2;
	}



	Dina::FPoint* playerCamPos = new Dina::FPoint { pX, pY };
	m_Player->SetCameraPosition(playerCamPos);
}
void Game::Draw()
{
	if (m_Level)
		m_Level->Draw(static_cast<int>(m_Camera->x), static_cast<int>(m_Camera->y));

	if (m_Player)
		m_Player->Draw();

}

// Hérité de Component::Event::KeyboardEvent
void Game::OnKeyPressed(Dina::KeyCode key)
{
	if (m_Player)
		m_Player->OnKeyPressed(key);
}
void Game::OnKeyReleased(Dina::KeyCode key)
{
	if (m_Player)
		m_Player->OnKeyReleased(key);
}
void Game::OnKeyRepeat(Dina::KeyCode key)
{
	if (m_Player)
		m_Player->OnKeyRepeat(key);
}

// Hérité de Component::Event::MouseEvent
void Game::OnMouseMove(int x, int y)
{
	if (m_Player)
		m_Player->OnMouseMove(x, y);
}
void Game::OnMousePressed(int button, int x, int y, int clicks)
{
	if (m_Player)
		m_Player->OnMousePressed(button, x, y, clicks);
}
void Game::OnMouseReleased(int button, int x, int y)
{
	if (m_Player)
		m_Player->OnMouseReleased(button, x, y);
}