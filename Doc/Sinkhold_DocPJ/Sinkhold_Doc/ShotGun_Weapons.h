#pragma once
#include "Weapons_Actor.h"
/**
@brief  ���ǿ� �˸°� ����
@details
*/
class ShotGun_Weapons :
	public Weapons_Actor
{
public:
	/**
	@brief ////////
	@details ////////
	*/
	void playFireSound();

	/**
	@brief ////////
	@details ////////
	*/
	void playReloadSound();

	/**
	@brief ////////
	@details ////////
	*/
	void createParticle();
};

