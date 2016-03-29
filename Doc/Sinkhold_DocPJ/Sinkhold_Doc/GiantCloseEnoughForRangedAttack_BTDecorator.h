#pragma once
#include "Giant_Enemy.h"

/**
@brief 적 AI 데코레이터
@details 자이언트 전용 원거리 공격을 할 수 있는지 판단하기 위해 공격 대상과의 거리를 검사한다.
*/
class GiantCloseEnoughForRangedAttack_BTDecorator :
	public BTDecorator
{
public:
	BlackboardKeySelector targetToAttack;
	float attackableDistance;

	/**
	@brief 데코레이터 조건 검사 함수
	@details 자이언트와 공격할 대상 사이의 거리를 검사한다.
	@details 거리가 attackableDistance의 값보다 작으면 True를 리턴한다.
	@param OwnerActor AI 컨트롤러.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);
};

