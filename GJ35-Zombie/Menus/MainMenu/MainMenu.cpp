#include "MainMenu.h"

MainMenu::MainMenu()
{
	m_MenuManager = new Dina::MenuManager;
}
MainMenu::~MainMenu()
{
	delete m_MenuManager;
}

void MainMenu::Load()
{
	m_MenuManager->SetBackground("Datas/Images/Menu/Background.png");

	// Ajout des titres
	m_MenuManager->AddTitle("Zombies", 100, "Datas/Fonts/Audiowide/Audiowide-Regular.ttf", 72, { 255,255,255,255 }, true, 2);
	m_MenuManager->AddTitle("GameJam Gamecodeur 35", 200, "Datas/Fonts/Audiowide/Audiowide-Regular.ttf", 25, { 255,255,255,255 }, true, 2);

	// Ajout des items du menu
	m_MenuManager->AddItem("Jouer", "Datas/Fonts/Audiowide/Audiowide-Regular.ttf", 48,
						   [this]() { OnPlayPressed(); },											// Action
						   nullptr,																	// action on Hover
						   { 255,255,255 }, { 0,255,0 });										    // Couleur de base, couleur en surbrillance
	m_MenuManager->AddItem("Crédits", "Datas/Fonts/Audiowide/Audiowide-Regular.ttf", 48,
						   [this]() { OnCreditsPressed(); },										// Action
						   nullptr,																	// action on Hover
						   { 255,255,255 }, { 0,255,0 });											// Couleur de base, couleur en surbrillance
	m_MenuManager->AddItem("Quitter", "Datas/Fonts/Audiowide/Audiowide-Regular.ttf", 48,
						   [this]() { OnQuitGame(); },												// Action
						   nullptr,																	// action on Hover
						   { 255,255,255 }, { 0,255,0 });											// Couleur de base, couleur en surbrillance

	Dina::Quad* screen = Dina::Graphic::GetDimensions();
	m_MenuManager->SetItemsStartHeight(screen->height / 2);
	m_MenuManager->SetItemsPadding(20);


	//Images lors du survol des items

}
void MainMenu::Update(double deltatime)
{
	if (m_MenuManager)
		m_MenuManager->Update(deltatime);
}
void MainMenu::Draw()
{
	if (m_MenuManager)
		m_MenuManager->Draw();
}

void MainMenu::OnKeyPressed(Dina::KeyCode key)
{
	if (key == Dina::KeyCode::Escape)
	{
		OnQuitGame();
	}
	if (m_MenuManager)
		m_MenuManager->OnKeyPressed(key);
}
void MainMenu::OnKeyReleased(Dina::KeyCode key)
{
	if (m_MenuManager)
		m_MenuManager->OnKeyReleased(key);
}

void MainMenu::OnMouseMove(int x, int y)
{
	if (m_MenuManager)
		m_MenuManager->OnMouseMove(x, y);
}
void MainMenu::OnMousePressed(int button, int x, int y, int clicks)
{
	if (m_MenuManager)
		m_MenuManager->OnMousePressed(button, x, y, clicks);
}
void MainMenu::OnMouseReleased(int button, int x, int y)
{
	if (m_MenuManager)
		m_MenuManager->OnMouseReleased(button, x, y);
}

void MainMenu::OnPlayPressed()
{
	Dina::GameState::SetCurrentState("Game");
}

void MainMenu::OnCreditsPressed()
{
	Dina::GameState::SetCurrentState("Credits");
}

void MainMenu::OnQuitGame()
{
	Dina::EventManager::QuitGame();
}