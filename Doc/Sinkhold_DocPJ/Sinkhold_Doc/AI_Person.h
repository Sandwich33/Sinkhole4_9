#pragma once
#include "Person_Character.h"
class AI_Person :
	public Person_Character
{
public:

	/**
	@brief �� ����???
	@details ����
	@details �ٹٲ� ����
	@param _delta_seconds �� ��¼����
	*/
	void actionAI_OnFile(float _delta_seconds, Vector _end_location, Object _get_object);
};

