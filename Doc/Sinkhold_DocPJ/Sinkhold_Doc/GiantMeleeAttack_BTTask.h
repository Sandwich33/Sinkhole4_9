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
private:
	Vector myLocation;
	Pawn myself;
};

