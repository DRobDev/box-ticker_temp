#include "Menu.h"

Menu::Menu()
{
	spalshScreen = new Sprite("./images/img_Splash_1024x1024.png", Vec2(512,512));
	menuBackground = new Sprite("./images/img_Menu_1024x1024.png", Vec2(512,512));
	middleScreenTran = new Transform();
	middleScreenTran->SetPosition(Vec2(BoxTicker::WINDOWSIZE.x / 2, BoxTicker::WINDOWSIZE.y / 2));
	spalshScreen->SetMatrix(middleScreenTran->GetMatrix());
	menuBackground->SetMatrix(middleScreenTran->GetMatrix());
	buttonStartGame = nullptr;
	buttonExit = nullptr;
}

void Menu::OncePerFrame()
{

}


bool Menu::IsButtonPressed(Buttons a_checkButton)
{
	switch (a_checkButton)
	{
	case Menu::EXITBUTTON:
		return buttonExit->hasBeenPressed;
		break;
	case Menu::STARTGAMEBUTTON:
		return buttonStartGame->hasBeenPressed;
		break;
	}
}


void Menu::ClearButtons()
{
	if(buttonExit != nullptr)
	{
		delete buttonExit;
		buttonExit = nullptr;
	}
	if(buttonStartGame != nullptr)
	{
		delete buttonStartGame;
		buttonStartGame = nullptr;
	}
}

void Menu::StartStartMenu()
{
	buttonExit = new Button("./images/img_Button_Exit_512x512.png", Vec2(BoxTicker::WINDOWSIZE.x/3, BoxTicker::WINDOWSIZE.y / 2));
	buttonStartGame = new Button("./images/img_Button_StartGame_512x512.png", Vec2(BoxTicker::WINDOWSIZE.x/2, BoxTicker::WINDOWSIZE.y / 2));
}

void Menu::UpdateStartMenu()
{
	menuBackground->Draw();
	buttonStartGame->sprite->Draw();
	buttonExit->sprite->Draw();
}

void Menu::UpdateSplash()
{
	//draw screen
	spalshScreen->Draw();
}


Menu::~Menu()
{
	delete spalshScreen;
	delete menuBackground;
	delete middleScreenTran;
}



Button::Button(const char* a_imgDir, Vec2 a_screenPos)
{
	sprite = new Sprite(a_imgDir, Vec2(BUTTONSIZE,BUTTONSIZE));
	transform = new Transform();
	collider = new Collider(Collider::BUTTON, this, transform, BUTTONSIZE/2);	

	transform->SetPosition(a_screenPos);
	sprite->SetMatrix(transform->GetMatrix());
	hasBeenPressed = false;
}

void Button::OnCollision(Collider* a_otherCol)
{
	hasBeenPressed = true;
}

Button::~Button()
{
	delete sprite;
	delete transform;
	delete collider;
}

