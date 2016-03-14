#pragma once
#include "Weapons_Actor.h"
/**
@brief 서브머신건(M4A1)에 알맞게 세팅
@details
*/
class M4A1_Weapons :
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
	@param _in_aim_data ////////
	@param _start_location ////////
	@param _end_location ////////
	@return _out_hit ////////
	@return _return_value ////////
	*/
	void getDemageActor(bool _in_aim_data, Vector _start_location, Vector _end_location, HitResult[] * _out_hit, bool *_return_value);
};

