#include "Enemy.h"
#include <cmath>
#include "Time.h"
#include "Sprite.h"

int Enemy::EnemyCounter = 0;

const float Enemy::BASEMOVESPEED = 200;
const float Enemy::SPEEDMULTIPLYERINCREASE = .2f;
float Enemy::speedMultiplyer = 1;

bool Enemy::AreAllEnemiesDestroyed()
{
	return EnemyCounter == 0;
}

Enemy::Enemy(Vec2 a_spawnPosition, float a_facingDirection, float a_moveSpeed)
{
	EnemyCounter++;
	transform = new Transform();
	collider = new Collider(Collider::ENEMY, this, transform, 55);

	//create sprite
	activeSprite = new Sprite("./images/img_Enemy_512x512.png", Vec2(64,64));

	//set position and rotation
	transform->SetPosition(a_spawnPosition);
	transform->SetRotation(a_facingDirection);
	moveSpeed = a_moveSpeed;
}

Enemy::Enemy()
{
	//stationary enemy in the middle of the screen

	//initialize components
	EnemyCounter++;
	transform = new Transform();
	collider = new Collider(Collider::ENEMY, this, transform, 55);

	//create sprite
	activeSprite = new Sprite("./images/img_Enemy_512x512.png", Vec2(64,64));
	
	//set position and rotation
	transform->SetPosition(Vec2(BoxTicker::WINDOWSIZE.x / 2, BoxTicker::WINDOWSIZE.y * .7f));
	transform->SetRotation(0);

	//dont' move
	moveSpeed = 0;
}

void Enemy::OncePerFrame()
{
	//move enemy
	transform->MoveLocal(Vec2(0, moveSpeed));

	// Draw Enemy //
	//apply transform information to sprite
	activeSprite->SetMatrix(transform->GetMatrix());
	//draw active sprite
	activeSprite->Draw();

	//destroy out of frame enemy
	if(transform->GoesOffScreen())
		delete this;
}

void Enemy::OnCollision(Collider* a_otherCol)
{
	switch (a_otherCol->GetColliderType())
	{
	case Collider::PLAYERBULLET:
		m_SpawnMore();
		speedMultiplyer += SPEEDMULTIPLYERINCREASE;
		delete this;
		break;
	}
}


void Enemy::m_SpawnMore()
{
	//spawns # new enemies at this pos.
	//randomise firsts direction then space
	//the rest out evenly

	const static int SPAWNAMOUNT = 7;
	int randSpawn = rand() % (SPAWNAMOUNT -3);
	randSpawn+=3;

	float m_startAngle = rand() % 360;

	for(int i = 0; i < randSpawn; i++)
	{
		new Enemy(transform->GetPosition(), m_startAngle + (i * (360/randSpawn)));	
	}
}

Enemy::~Enemy()
{
	EnemyCounter--;
	delete collider;
	delete activeSprite;
	delete transform;
}