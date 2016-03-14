#pragma once
#include "Weapons_Actor.h"
/**
@brief  샷건에 알맞게 세팅
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

