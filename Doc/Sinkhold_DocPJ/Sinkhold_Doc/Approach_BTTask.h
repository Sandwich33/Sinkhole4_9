#pragma once

/**
@brief 적 AI 태스크
@details 공격하려는 대상에게 접근하는 기능을 한다.
*/
class Approach_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;
};

