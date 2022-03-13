#include "Logo.h"
#include <Dina.h>
using namespace Dina;

// Hérité via Component
void Logo::Load()
{
	m_Texture = new Texture("Datas/Images/Logo/Logo.png");
	CenterTexture(0.75f);
	waitTime = 1.5;
	timer = 0.0;
	m_Alpha = 255.0f;
	step = 80.0;
}
void Logo::Update(double deltatime)
{
	if (!fadeout)
	{
		timer += deltatime;
		if (timer >= waitTime)
		{
			timer = 0.0;
			fadeout = true;
		}
	}
	else
	{
		m_Alpha -= step * deltatime;
		if (m_Alpha <= 0)
		{
			m_Alpha = 255.0f;
			fadeout = false;
			GameState::SetCurrentState("Menu");
		}
	}
}
void Logo::Draw()
{
	Dina::Graphic::DrawTexture(m_Texture, { 255,255,255,static_cast<unsigned char>(m_Alpha) });
}

// Hérité via Component::Event
void Logo::OnMousePressed(int button, int x, int y, int clicks)
{
	if(fadeout)
		GameState::SetCurrentState("Menu");
}

void Logo::CenterTexture(float ratio)
{
	Quad* textureDimensions = m_Texture->GetDimensions();

	Quad* screen_dim = Graphic::GetDimensions();
	int max_width = static_cast<int>(screen_dim->width * ratio);
	int max_height = static_cast<int>(screen_dim->height * ratio);
	if (textureDimensions->width > max_width || textureDimensions->height > max_height)
	{
		float ratio_w = static_cast<float>(max_width) / textureDimensions->width;
		float ratio_h = static_cast<float>(max_height) / textureDimensions->height;
		float ratio = ratio_w < ratio_h ? ratio_w : ratio_h;

		textureDimensions->width = static_cast<int>(textureDimensions->width * ratio);
		textureDimensions->height = static_cast<int>(textureDimensions->height * ratio);
	}

	textureDimensions->x = (screen_dim->width - textureDimensions->width) / 2;
	textureDimensions->y = (screen_dim->height - textureDimensions->height) / 2;
}
