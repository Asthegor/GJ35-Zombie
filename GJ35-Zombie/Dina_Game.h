#pragma once
#include <Dina.h>

class Dina_Game : public Dina::DinaGame
{
public:
	Dina_Game();

	void Load() override;
	void Update(double deltatime) override;
	void Draw() override;
};
