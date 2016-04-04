#pragma once

/**
@brief 팀원 AI 데코레이터
@details myCharacter의 값에 따라 플레이어가 AI근처에 있는지 확인한다. 
*/

class Dec_PlayerCheck :
	public BTDecorator
{
public:
	BlackboardKeySelector myCharacter;
	BlackboardKeySelector targetToAttack;

	/**
	@brief 데코레이터 조건 검사 함수
	@details myCharacter변수가 true면 있다고 인식하고 False면 없다고 인식함.
	@param OwnerActor AI 컨트롤러.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);

};

