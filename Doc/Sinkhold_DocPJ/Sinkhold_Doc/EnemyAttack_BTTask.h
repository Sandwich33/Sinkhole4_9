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
	EventGraph ReceiveTick();
	EventGraph ReceiveExecute();

	BlackboardKeySelector targetToAttack;
private:
	Vector myLocation;
	Pawn myself;
};

