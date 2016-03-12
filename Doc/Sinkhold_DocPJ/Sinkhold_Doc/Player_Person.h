#pragma once
#include "Person_Character.h"
class Player_Person :
	public Person_Character
{
public:
	Player_Person();
	~Player_Person();

	void setViewTarget(bool _me);
	void getAimInfo(float *_recoil, Vector2D *_screen_point, bool *_show_aim);
	void getBulletInfo(int *_bullet, int *_have_bullet);

	bool fire_input_tag;
	bool jumping;
};

