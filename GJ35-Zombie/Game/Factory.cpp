#include "Factory.h"
#include "Bullet.h"
#include "Enemy.h"

void* Factory::CreateEntity(EntityType entityType, Dina::FPoint point)
{
	switch (entityType)
	{
		case EntityType::Bullet:
			{
				return new Bullet(point, point, 0.0);
			}
			break;
		case EntityType::Enemy:
			{
				return new Enemy(point);
			}
			break;
		default:
			break;
	}
	return nullptr;
}
