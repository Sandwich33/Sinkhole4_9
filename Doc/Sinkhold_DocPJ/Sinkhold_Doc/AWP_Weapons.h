#pragma once
#include "Weapons_Actor.h"
/**
@brief ��������(AWP)�� �˸°� ����
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

