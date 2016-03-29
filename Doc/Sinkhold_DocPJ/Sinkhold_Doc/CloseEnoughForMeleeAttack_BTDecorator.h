#pragma once

/**
@brief 적 AI 데코레이터
@details 근접 공격을 할 수 있는지 판단하기 위해 공격 대상과의 거리를 검사한다.
*/
class CloseEnoughForMeleeAttack_BTDecorator :
	public BTDecorator
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief 데코레이터 조건 검사 함수
	@details AI 컨트롤러가 컨트롤하는 폰과 공격할 대상 사이의 거리를 검사한다.
	@details 거리가 ATTACKABLE_DISTANCE의 값보다 작으면 True를 리턴한다.
	@param OwnerActor AI 컨트롤러.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);
private:
	float ATTACKABLE_DISTANCE;
};

