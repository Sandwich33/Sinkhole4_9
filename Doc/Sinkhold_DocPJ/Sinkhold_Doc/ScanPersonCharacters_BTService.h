#pragma once

/**
@brief 적 AI 서비스
@details 매 틱마다 공격 대상을 찾는다. 발견하면 대상을 블랙보드의 targetToAttack에 set한다.
*/
class ScanPersonCharacters_BTService :
	public BTService
{
public:
	BlackboardKeySelector targetToAttack;
private:
	Vector myLocation;
	Actor allTheSameActors[];
	float closest;
	Actor closestActor;
};

