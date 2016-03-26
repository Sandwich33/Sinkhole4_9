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
};

