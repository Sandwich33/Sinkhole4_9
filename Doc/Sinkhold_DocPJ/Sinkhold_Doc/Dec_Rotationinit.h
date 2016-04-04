#pragma once

/**
@brief 팀원 AI 데코레이터
@details AI의 초기 Rotation을 초기화를 위한 데코레이터
*/

class Dec_Rotationinit :
	public BTDecorator
{
public:
	BlackboardKeySelector OriginalRotation;
	
	/**
	@brief 초기화를 위한 데코레이터
	@details 단순히 AI들의 초기 Rotation을 Set함
	@param OwnerActor AI 컨트롤러.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);
};

