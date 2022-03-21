#include "Factory.h"
#include "Bullet.h"
#include "Enemy.h"

void* Factory::CreateEntity(EntityType entityType, Dina::FPoint point)
{
	switch (entityType)
	{
		case EntityType::Bullet:
			{
				DINA_INFO("Bullet created at [{0},{1}]", point.x, point.y);
				return new Bullet(point, point, 0.0);
			}
			break;
		case EntityType::Enemy:
			{
				DINA_INFO("Enemy created at [{0},{1}]", point.x, point.y);
				return new Enemy(point);
			}
			break;
		default:
			break;
	}
	return nullptr;
}
