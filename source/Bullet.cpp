#include "Bullet.h"
#include "Sprite.h"

const float Bullet::BULLETSPEED = 2000;

Bullet::Bullet(float* a_parentMatrix, Collider::ColliderTypes a_colType)
{
	transform = new Transform();
	collider = new Collider(a_colType, this, transform);

	if(a_colType == Collider::ColliderTypes::PLAYERBULLET)
		activeSprite = new Sprite("./images/img_Bullet_Player_512x512.png", Vec2(32,32));
	transform->SetMatrix(a_parentMatrix);
}

void Bullet::OncePerFrame()
{
	//moves bullet down local axis
	transform->MoveLocal(Vec2(0,BULLETSPEED));

	//draw bullet
	activeSprite->SetMatrix(transform->GetMatrix());
	activeSprite->Draw();

	//destroy bullet if it moves out of frame
	if(transform->GoesOffScreen())
	{delete this;}//delete
}

void Bullet::OnCollision(Collider* a_otherCol)
{
	if(a_otherCol->GetColliderType() != Collider::PLAYER)
	{
		bool blah = 0;
	}

	switch (a_otherCol->GetColliderType())
	{
	case Collider::ENEMY:
	case Collider::BUTTON:
		delete this;
		break;
	}
}




Bullet::~Bullet(void)
{
	delete collider;
	delete activeSprite;
	delete transform;
}
