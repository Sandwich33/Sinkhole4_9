#pragma once
#include "Weapons_Actor.h"
/**
@brief 스나이퍼(AWP)에 알맞게 세팅
@details
*/
class AWP_Weapons :
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

	/**
	@brief ////////
	@details ////////
	*/
	void playZoominSound();

	/**
	@brief ////////
	@details ////////
	@return --- ////////
	*/
	Vector getLookVector();
};

