#pragma once

/**
@brief 적 AI 서비스
@details 무작위로 0 ~ 10초의 시간이 지날 때마다 캐릭터의 주변 -2000 ~ +2000 범위 내의 랜덤 위치를 찾아
@details 블랙보드의 destination에 set하거나 set하지 않는다.
*/
class SetRandomDestination_BTService :
	public BTService
{
public:
	BlackboardKeySelector destination;
	BlackboardKeySelector targetToAttack;
};

