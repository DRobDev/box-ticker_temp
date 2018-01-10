#include "Player.h"
#include "CustomCursor.h"
#include "Bullet.h"

const float Player::MOVESPEED = 500;

bool Player::IsButtonPressed()
{
	static bool m_pressed = false;
	static bool m_released = true;

	if(MoveButtonDown || FireButtonDown)
	{
		m_pressed = true;
		m_released = false;
	}
	if(MoveButtonUp && FireButtonUp)
		m_released = true;

	if(m_pressed && m_released)
	{
		m_pressed = false;
		return true;
	}

	return false;
}

Player::Player()
{
	transform = new Transform();
	collider = new Collider(Collider::PLAYER, this, transform, 55);

	//create player sprite
	activeSprite = new Sprite(
		"./images/img_Player_512x512.png",
		Vec2(64, 64));
	//set position to center-screen
	transform->SetPosition(Vec2(BoxTicker::WINDOWSIZE.x / 2, BoxTicker::WINDOWSIZE.y /6));

}

void Player::ResetPosition()
{
	transform->SetPosition(Vec2(BoxTicker::WINDOWSIZE.x / 2, BoxTicker::WINDOWSIZE.y /6));
};

void Player::m_LookAtCursor()
{
	transform->LookAt(CustomCursor::GetPosition());
}

void Player::m_MoveLocal()
{
	//move towards cursor along local 'y' axis a predetermined amount//
	transform->MoveLocal(Vec2(0, MOVESPEED));
}

Player::~Player()
{
	delete collider;
	delete activeSprite;
}

void Player::OncePerFrame()
{
	//rotate player to look at cursor
	m_LookAtCursor();

	//move on key press
	if(MoveButtonDown)
	{
		m_MoveLocal();
	}

	//fire on key press
	static bool hasFiredThisPress = false;
	if(FireButtonDown)
	{
		if(!hasFiredThisPress)
		{
			new Bullet(transform->GetMatrix());
			hasFiredThisPress = true;
		}
	}
	else
		hasFiredThisPress = false;


	// Draw Player //
	//apply transform information to sprite
	activeSprite->SetMatrix(transform->GetMatrix());
	//draw active sprite
	activeSprite->Draw();
}

void Player::OnCollision(Collider* a_otherCol)
{
	switch (a_otherCol->GetColliderType())
	{
	case Collider::ENEMY:
		transform->SetPosition(Vec2::MAX); //TODO: hide player
		break;
	}
}
