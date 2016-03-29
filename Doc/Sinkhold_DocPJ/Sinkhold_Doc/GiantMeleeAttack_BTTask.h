#pragma once
#include "Giant_Enemy.h"

/**
@brief 적 AI 태스크
@details 자이언트 전용 근접 공격 기능과 범위 공격 스킬.
*/
class GiantMeleeAttack_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief 태스크 틱 이벤트
	@details 자이언트가 공격할 대상을 바라보게 하고 onAttack을 호출한다.
	@details 쿨타임이 아니면 범위 공격 스킬을 사용할 수 있다.
	*/
	EventGraph ReceiveTick();

	/**
	@brief 태스크 실행 이벤트
	@details myself와 myLocation을 초기화한다.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveExecute(Actor OwnerActor);
private:
	Vector myLocation;
	Pawn myself;
};

