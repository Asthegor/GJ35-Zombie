#pragma once
#include <Dina.h>
#include <string>

enum class EntityType
{
	Bullet, Enemy
};

class Factory
{
public:
	static void* CreateEntity(EntityType entityType, Dina::FPoint point);


private:
};

