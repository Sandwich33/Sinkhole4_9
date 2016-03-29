#pragma once
#include "Giant_Enemy.h"

/**
@brief 적 AI 태스크
@details 자이언트 전용 대쉬 스킬.
*/
class GiantApproach_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief 태스크 실행 이벤트
	@details 자이언트가 공격할 대상에게 접근하게 한다.
	@details 쿨타임이 아니면 대쉬 스킬을 사용할 수 있다.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveExecute(Actor OwnerActor);

	/**
	@brief 태스크 중단 이벤트
	@details 제어 흐름이 끊어지면 대쉬를 끝낸다.
	*/
	EventGraph ReceiveAbort();
};

