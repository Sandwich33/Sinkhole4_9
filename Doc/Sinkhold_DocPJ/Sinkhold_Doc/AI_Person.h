#pragma once
#include "Person_Character.h"
class AI_Person :
	public Person_Character
{
public:

	/**
	@brief 대 제목???
	@details 내용
	@details 줄바꿔 내용
	@param _delta_seconds 는 어쩌구다
	*/
	void actionAI_OnFile(float _delta_seconds, Vector _end_location, Object _get_object);
};

