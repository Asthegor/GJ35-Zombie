#include "Game.h"
#include <vector>

Game::Game()
{
	m_Factory = new Factory;

	m_Player = new Player;
	m_Level = new Dina::Level;
	m_Camera = new Dina::FPoint;
}
Game::~Game()
{
	delete m_Factory;

	delete m_Player;
	delete m_Level;
	delete m_Camera;
}

// Hérité de Component
void Game::Load()
{
	m_Player->Load();
	m_Level->Load("Datas/Maps/Level01.tmx");
	m_Player->SetLevelDimensions(m_Level->GetDimensions());


	m_Enemies.push_back(static_cast<Enemy*>(m_Factory->CreateEntity(EntityType::Enemy, { 200.0f, 200.0f })));
}
void Game::Update(double deltatime)
{
	UpdatePlayer(deltatime);


	for (auto& bullet : m_Bullets)
	{
		bullet->SetCameraOffset(*m_Camera);
		bullet->Update(deltatime);
		Dina::FPoint bulletFloatPosition = bullet->GetPosition();
		Dina::Point bulletPosition { static_cast<int>(bulletFloatPosition.x), static_cast<int>(bulletFloatPosition.y) };
		for (auto& enemy : m_Enemies)
		{
			Dina::Quad enemyDimensions = enemy->GetDimensions();
			int x = enemyDimensions.x + enemyDimensions.width / 4;
			int y = enemyDimensions.y + enemyDimensions.height / 4;
			int w = enemyDimensions.width / 2;
			int h = enemyDimensions.height / 2;
			Dina::Quad collidebox { x, y, w, h };

			if (Dina::Collisions::Collide(bulletPosition, collidebox))
				enemy->GetDamage(bullet->GetDamagePoints());
		}
	}

	for (auto it = m_Enemies.begin(); it != m_Enemies.end();)
	{
		if ((*it)->IsDead())
			it = m_Enemies.erase(it);
		else
			it++;
	}

	for (auto& enemy : m_Enemies)
	{
		// Mise à jour des animations
		enemy->SetCameraOffset(*m_Camera);
		enemy->Update(deltatime);

		// Vérification des actions
		Dina::FPoint enemyPosition = enemy->GetPosition();
		Dina::FPoint playerPosition = *m_Player->GetPosition();
		float distance = Dina::Maths::Distance(enemyPosition.x, enemyPosition.y, playerPosition.x, playerPosition.y);
		if (distance <= Enemy::DetectionDistance)
		{
			double rad_angle = std::atan2(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x);
			enemy->SetAngle(rad_angle * 180 / M_PI);

			if (distance <= Enemy::AttackDistance)
			{
				enemy->SetDirection({ 0,0 });
				enemy->SetAnimation("attack");
			}
			else
			{
				Dina::FPoint direction;
				float px = playerPosition.x;
				float py = playerPosition.y;
				float cx = enemyPosition.x;
				float cy = enemyPosition.y;
				float dx = px - cx;
				float dy = py - cy;
				float d = std::sqrt(dx * dx + dy * dy);
				direction = { dx / d, dy / d };
				enemy->SetDirection(direction);
				enemy->SetAnimation("move");
			}
		}
		else
		{
			enemy->SetDirection({ 0,0 });
			enemy->SetAnimation("idle");
		}
		enemy->SetPosition(enemyPosition);
	}



}
void Game::Draw()
{
	m_Level->Draw(static_cast<int>(m_Camera->x), static_cast<int>(m_Camera->y));


	for (auto& bullet : m_Bullets)
		bullet->Draw();

	for (auto& enemy : m_Enemies)
		enemy->Draw();

	m_Player->Draw();
}

void Game::UpdatePlayer(double deltatime)
{
	Dina::Quad playerOriDim = m_Player->GetDimensions();
	Dina::FPoint playerOriCam = *m_Player->GetCameraPosition();
	Dina::Point playerOrigin = m_Player->GetOrigin();
	
	m_Player->Update(deltatime);

	Dina::Quad playerDimensions = m_Player->GetDimensions();
	Dina::Quad* screen = Dina::Graphic::GetDimensions();
	Dina::Point levelDimensions = m_Level->GetDimensions();

	float pX = 0.0f;
	float pY = 0.0f;
	if (playerDimensions.x + playerOrigin.x < screen->width / 2)
	{
		m_Camera->x = 0.0f;
		pX = playerDimensions.x * 1.0f;
	}
	else if (playerDimensions.x + playerOrigin.x > levelDimensions.x - screen->width / 2)
	{
		m_Camera->x = (levelDimensions.x - screen->width) * 1.0f;
		pX = (playerDimensions.x - levelDimensions.x + screen->width) * 1.0f;
	}
	else
	{
		m_Camera->x = (playerDimensions.x + playerOrigin.x - screen->width / 2) * 1.0f;
		pX = (screen->width / 2 - playerOrigin.x) * 1.0f;
	}


	if (playerDimensions.y + playerOrigin.y < screen->height / 2)
	{
		m_Camera->y = 0.0f;
		pY = playerDimensions.y * 1.0f;
	}
	else if (playerDimensions.y + playerOrigin.y > levelDimensions.y - screen->height / 2)
	{
		m_Camera->y = (levelDimensions.y - screen->height) * 1.0f;
		pY = (playerDimensions.y - levelDimensions.y + screen->height) * 1.0f;
	}
	else
	{
		m_Camera->y = (playerDimensions.y + playerOrigin.y - screen->height / 2) * 1.0f;
		pY = (screen->height / 2 - playerOrigin.y) * 1.0f;
	}

	Dina::Point coord = m_Level->ConvertCoordToRowCol({ static_cast<int>(playerDimensions.x + playerOrigin.x), static_cast<int>(playerDimensions.y + playerOrigin.y) });
	if (m_Level->HasId(coord.x, coord.y))
	{
		m_Player->SetCameraPosition({ playerOriCam });
		m_Player->SetPosition({ static_cast<float>(playerOriDim.x), static_cast<float>(playerOriDim.y) });
	}
	//m_Player->SetCameraOffset(*m_Camera);
	m_Player->SetCameraPosition({ pX, pY });
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
	//Tirs du joueur
	switch (button)
	{
		case 1: //Tir principal
			{
				if (m_Player->CanShoot())
				{
					Dina::Point origin = m_Player->GetOrigin();
					Dina::FPoint playerPosition = *m_Player->GetPosition();
					Dina::FPoint bulletPosition { playerPosition.x + origin.x, playerPosition.y + origin.y };
					Dina::FPoint playerOrientation = m_Player->GetOrientation();
					Bullet* bullet = new Bullet(bulletPosition, playerOrientation, m_Player->GetAngle());
					m_Bullets.push_back(bullet);
					m_Player->CanShoot(false);
				}
			}
			break;
	}
}
void Game::OnMouseReleased(int button, int x, int y)
{
}
