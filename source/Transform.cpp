#include "Transform.h"
#include "Time.h"
#include <cmath>

Transform::Transform()
{
	//set start matrix as Identity matrix
	//	1	0	0	0
	//	0	1	0	0
	//	0	0	1	0
	//	0	0	0	1
	for(int i = 0; i < MATRIXSIZE; i++)
		if(i % 5 == 0) transformMatrix[i] = 1; else transformMatrix[i] = 0;
}

void Transform::SetPosition(Vec2 a_pos)
{
	//apply position to matrix
	transformMatrix[MAT_POSX] = a_pos.x;
	transformMatrix[MAT_POSY] = a_pos.y;
}

void Transform::SetRotation(float a_degrees)
{
#define radian 57.2957795f

	//translate into radians
	float m_angle = a_degrees / radian;
	//translate into matrix
	transformMatrix[0] = cosf(m_angle);		transformMatrix[1] = sinf(m_angle);
	transformMatrix[4] = -sinf(m_angle);	transformMatrix[5] = cosf(m_angle); 
}

void Transform::MoveLocal(Vec2 a_moveAmount)
{
	//make movement amount frame and mass consistent
	a_moveAmount *= Time::GetDelta();

	Vec2 m_desired;

	//tralslate move around local axis
	m_desired.x = (-((-a_moveAmount.x) * transformMatrix[0]) + (a_moveAmount.y * transformMatrix[4]));
	m_desired.y = -(((-a_moveAmount.x) * transformMatrix[1]) - (a_moveAmount.y *transformMatrix[5]));

	SetPosition(m_desired + GetPosition());
}

float* Transform::GetMatrix()
 {
	return transformMatrix;
}

void Transform::SetMatrix(float* a_matrix)
{
	for(int i = 0; i < MATRIXSIZE; i++)
		transformMatrix[i] = a_matrix[i];
}

Vec2 Transform::GetPosition()
{
	return Vec2(transformMatrix[MAT_POSX], transformMatrix[MAT_POSY]);
}

void Transform::LookAt(Vec2 a_screenPos)
{
	//Rotates this transform to look face argument//
	//offset local position
	a_screenPos = a_screenPos - GetPosition();

	//get angle from position
	float m_angle = atan2f(a_screenPos.x, a_screenPos.y);

	//update rotation matrix
	transformMatrix[0] = cosf(m_angle);		transformMatrix[1] = -sinf(m_angle);
	transformMatrix[4] = sinf(m_angle);		transformMatrix[5] = cosf(m_angle);
}

bool Transform::GoesOffScreen()
{
#define posX transformMatrix[MAT_POSX]
#define posY transformMatrix[MAT_POSY]
#define isOffToTheLeft < 0
#define isOffToTheRight > BoxTicker::WINDOWSIZE.x
#define isOffToTheTop > BoxTicker::WINDOWSIZE.y
#define isOffToTheBottom < 0

	if(posX isOffToTheRight
		|| posX isOffToTheLeft
		|| posY isOffToTheTop
		|| posY isOffToTheBottom)
		return true;
	else return false;
}