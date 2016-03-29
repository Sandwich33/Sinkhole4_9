#pragma once
#include "Enemy_Character.h"

/**
@brief 적 AI 태스크
@details 기본 근접 공격 기능을 한다.
*/
class EnemyAttack_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief 태스크 틱 이벤트
	@details 캐릭터가 공격할 대상을 바라보게 하고 onAttack을 호출한다.
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

