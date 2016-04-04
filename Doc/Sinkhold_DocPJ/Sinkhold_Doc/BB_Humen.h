#pragma once

/**
@brief 팀원 AI 블랙보드
@details 비헤이비어 트리의 흐름을 제어하기 위한 변수들을 모아두는 곳이다.
*/

class BB_Humen :
	public Blackboard
{
public:
	Object myCharacter;
	Object targetToAttack;
	Object SelectAI;
	Vector Destination;
	Vector myLocation;
	Integer bullet;
	Rotator OriginalRotation;
	Float attackRange;
	Bool Command;
	Bool distanceCheck;
};

