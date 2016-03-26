#pragma once

/**
@brief 적 AI 블랙보드
@details 비헤이비어 트리의 흐름을 제어하기 위한 변수들을 모아두는 곳이다.
*/
class EnemyBlackboard_Blackboard :
	public Blackboard
{
public:
	Object targetToAttack;
	Vector destination;
};

