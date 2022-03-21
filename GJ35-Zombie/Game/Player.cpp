#include "Player.h"
#include <Dina.h>

Player::Player()
{
	m_Dimensions = new Dina::Quad;
	m_Position = new Dina::FPoint;
	m_CameraPosition = new Dina::FPoint;
}

Player::~Player()
{
	delete m_Position;
	delete m_CameraPosition;
	delete m_Dimensions;
	delete m_CurrentAnimation;
	m_Animations.clear();
}

// Hérité via Component
void Player::Load()
{

	std::string path = "Datas/Images/Game/Top_Down_Survivor";
	std::string extension = ".png";
	Dina::Animation* animation = nullptr;
	// flashlight - idle
	{
		std::string weapon = "flashlight";
		std::string action = "idle";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		animation->SetOrigin(new Dina::Point { 39,46 });
		m_Animations[weapon + "_" + action] = animation;

	}
	// flashlight - meleeattack
	{
		std::string weapon = "flashlight";
		std::string action = "meleeattack";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 15, 0.125);
		animation->SetOrigin(new Dina::Point { 39, 51 });
		m_Animations[weapon + "_" + action] = animation;
	}
	// flashlight - move
	{
		std::string weapon = "flashlight";
		std::string action = "move";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		animation->SetOrigin(new Dina::Point { 37, 45 });
		m_Animations[weapon + "_" + action] = animation;
	}
	// handgun - idle
	{
		std::string weapon = "handgun";
		std::string action = "idle";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		animation->SetOrigin(new Dina::Point { 38, 48 });
		m_Animations[weapon + "_" + action] = animation;
	}
	// handgun - meleeattack
	{
		std::string weapon = "handgun";
		std::string action = "meleeattack";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 15, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// handgun - move
	{
		std::string weapon = "handgun";
		std::string action = "move";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// handgun - reload
	{
		std::string weapon = "handgun";
		std::string action = "reload";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 15, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// handgun - shoot
	{
		std::string weapon = "handgun";
		std::string action = "shoot";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 3, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// knife - idle
	{
		std::string weapon = "knife";
		std::string action = "idle";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// knife - meleeattack
	{
		std::string weapon = "knife";
		std::string action = "meleeattack";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 15, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// knife - move
	{
		std::string weapon = "knife";
		std::string action = "move";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// rifle - idle
	{
		std::string weapon = "rifle";
		std::string action = "idle";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// rifle - meleeattack
	{
		std::string weapon = "rifle";
		std::string action = "meleeattack";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 15, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// rifle - move
	{
		std::string weapon = "rifle";
		std::string action = "move";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// rifle - reload
	{
		std::string weapon = "rifle";
		std::string action = "reload";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// rifle - shoot
	{
		std::string weapon = "rifle";
		std::string action = "shoot";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 3, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// shotgun - idle
	{
		std::string weapon = "shotgun";
		std::string action = "idle";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// shotgun - meleeattack
	{
		std::string weapon = "shotgun";
		std::string action = "meleeattack";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 15, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// shotgun - move
	{
		std::string weapon = "shotgun";
		std::string action = "move";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// shotgun - reload
	{
		std::string weapon = "shotgun";
		std::string action = "reload";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 20, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	// shotgun - shoot
	{
		std::string weapon = "shotgun";
		std::string action = "shoot";
		std::string prefix = path + "/" + weapon + "/" + action + "/survivor-" + action + "_" + weapon + "_";
		animation = new Dina::Animation(prefix.c_str(), extension.c_str(), 3, 0.125);
		m_Animations[weapon + "_" + action] = animation;
	}
	m_Weapon = "handgun";
	m_Action = "idle";
	m_CurrentAnimation = m_Animations[m_Weapon + "_" + m_Action];
	m_Speed = 100;

	m_Dimensions = m_CurrentAnimation->GetDimensions();

	m_Position->x = 300;
	m_Position->y = 200;
}
void Player::Update(double deltatime)
{
	// Calcul de l'angle en degrés
	float angle_deg = 0.0f;

	switch (m_Move)
	{
		case Direction::Down:
			angle_deg = 0.0f;
			break;
		case Direction::DownerRight:
			angle_deg = 45.0f;
			break;
		case Direction::Right:
			angle_deg = 90.0f;
			break;
		case Direction::UpperRight:
			angle_deg = 135.0f;
			break;
		case Direction::Up:
			angle_deg = 180.0f;
			break;
		case Direction::UpperLeft:
			angle_deg = 225.0f;
			break;
		case Direction::Left:
			angle_deg = 270.0f;
			break;
		case Direction::DownerLeft:
			angle_deg = 315.0f;
			break;
		default:
			angle_deg = -1.0f;
			break;
	}

	float vx = 0.0f;
	float vy = 0.0f;
	if (m_Move > 0 && angle_deg >= 0.0f)
	{
		float angle_rad = static_cast<float>(angle_deg * M_PI / 180.0f);
		vx = static_cast<float>(std::sin(angle_rad) * m_Speed * deltatime);
		if (std::abs(vx) < 0.0001f)
			vx = 0.0f;

		vy = static_cast<float>(std::cos(angle_rad) * m_Speed * deltatime);
		if (std::abs(vy) < 0.0001f)
			vy = 0.0f;
	}
	m_Position->x += vx;
	m_Position->y += vy;

	if (m_CurrentAnimation)
	{
		m_CurrentAnimation->SetPosition(static_cast<int>(m_Position->x), static_cast<int>(m_Position->y));
		m_CurrentAnimation->Update(deltatime);
	}

	if (!m_CanShoot)
	{
		m_ShootTimer -= deltatime;
		if (m_ShootTimer <= 0.0)
		{
			m_CanShoot = true;
			m_ShootTimer = m_ShootDelay;
		}
	}
	
}
void Player::Draw()
{
	if (m_CurrentAnimation)
		m_CurrentAnimation->Draw();
}

void Player::SetLevelDimensions(Dina::Point const levelDimensions)
{
	m_LevelDimensions = levelDimensions;
}


// Hérité de Component::Event::KeyboardEvent
void Player::OnKeyPressed(Dina::KeyCode key)
{
	if (key == Dina::KeyCode::Left)
		m_Move |= Direction::Left;
	if (key == Dina::KeyCode::Right)
		m_Move |= Direction::Right;
	if (key == Dina::KeyCode::Up)
		m_Move |= Direction::Up;
	if (key == Dina::KeyCode::Down)
		m_Move |= Direction::Down;
}
void Player::OnKeyReleased(Dina::KeyCode key)
{
	switch (key)
	{
		case Dina::KeyCode::Left:
			{
				if(m_Move & Direction::Left)
					m_Move -= Direction::Left;
			}
			break;
		case Dina::KeyCode::Right:
			{
				if (m_Move & Direction::Right)
					m_Move -= Direction::Right;
			}
			break;
		case Dina::KeyCode::Up:
			{
				if (m_Move & Direction::Up)
					m_Move -= Direction::Up;
			}
			break;
		case Dina::KeyCode::Down:
			{
				if (m_Move & Direction::Down)
					m_Move -= Direction::Down;
			}
			break;

		// Changement d'armes
		case Dina::KeyCode::Key_1:
			m_Weapon = "flashlight";
			break;
		case Dina::KeyCode::Key_2:
			m_Weapon = "handgun";
			break;
		case Dina::KeyCode::Key_3:
			m_Weapon = "knife";
			break;
		case Dina::KeyCode::Key_4:
			m_Weapon = "rifle";
			break;
		case Dina::KeyCode::Key_5:
			m_Weapon = "shotgun";
			break;
		case Dina::KeyCode::Key_E:
			if (m_Action == "" || m_Action == "shoot" || m_Action == "move" && (m_Weapon == "flashlight" || m_Weapon == "knife"))
				m_Action = "idle";
			else if (m_Action == "idle")
				m_Action = "meleeattack";
			else if (m_Action == "meleeattack")
				m_Action = "move";
			else if (m_Action == "move")
				m_Action = "reload";
			else if (m_Action == "reload")
				m_Action = "shoot";
	}
	m_CurrentAnimation = m_Animations[m_Weapon + "_" + m_Action];
}
void Player::OnKeyRepeat(Dina::KeyCode key)
{
}

// Hérité de Component::Event::MouseEvent
void Player::OnMouseMove(int x, int y)
{
	//Changement d'orientation du joueur
	Dina::Point* origin = m_CurrentAnimation->GetOrigin();
	double rad_angle = std::atan2(y - m_CameraPosition->y - origin->y, x - m_CameraPosition->x - origin->x);
	m_Angle = rad_angle * 180 / M_PI;

	float px = static_cast<float>(x);
	float py = static_cast<float>(y);
	float cx = m_CameraPosition->x;// +static_cast<float>(origin->x);
	float cy = m_CameraPosition->y;// +static_cast<float>(origin->y);
	float dx = px - cx;
	float dy = py - cy;
	float d = std::sqrt(dx * dx + dy * dy);
	m_Orientation = { dx / d, dy / d };

	m_CurrentAnimation->SetRotation(m_Angle);
}

void Player::SetPosition(Dina::FPoint point)
{
	m_Position->x = point.x;
	m_Position->y = point.y;
}

void Player::SetCameraPosition(Dina::FPoint point)
{
	m_CameraPosition->x = point.x;
	m_CameraPosition->y = point.y;
	m_CurrentAnimation->SetPosition(static_cast<int>(m_CameraPosition->x), static_cast<int>(m_CameraPosition->y));
}

Dina::Quad Player::GetDimensions()
{
	Dina::Quad* dim = m_CurrentAnimation->GetDimensions();
	return Dina::Quad(static_cast<int>(m_Position->x), static_cast<int>(m_Position->y), dim->width, dim->height);
}

Dina::Point Player::GetOrigin()
{
	return *m_CurrentAnimation->GetOrigin();
}

void Player::CanShoot(bool canShoot)
{
	m_CanShoot = canShoot;
}
