#pragma once
#include "Giant_Enemy.h"

/**
@brief 적 AI 태스크
@details 자이언트 전용 원거리 공격 스킬.
*/
class GiantRangedAttack_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;
private:
	Vector myLocation;
	Pawn myself;
};

