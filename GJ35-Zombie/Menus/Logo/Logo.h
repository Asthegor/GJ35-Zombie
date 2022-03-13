#pragma once
#include <Dina.h>
using namespace Dina;

class Logo : public Component
{
	Texture* m_Texture = nullptr;
	double timer;
	double waitTime;
	double m_Alpha;
	bool fadeout;
	double step;

public:

	// Hérité via Component
	virtual void Load() override;
	virtual void Update(double deltatime) override;
	virtual void Draw() override;

	// Hérité via Component::Event::MouseEvent
	virtual void OnMousePressed(int button, int x, int y, int clicks);
private:

	void CenterTexture(float ratio);
};