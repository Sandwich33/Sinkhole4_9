#pragma once

/**
@brief 팀원 AI 서비스
@details 매 틱마다 공격 대상을 찾는다. 발견하면 대상을 블랙보드의 targetToAttack에 set한다.
*/

class Service_ScanEnemyCharacter :
	public BTService
{
public:
	BlackboardKeySelector targetToAttack;
	BlackboardKeySelector attackRange;

	/**
	@brief 서비스 틱 이벤트
	@details 캐릭터 주변 일정 범위 안의 적 캐릭터를 찾는다.
	@details 찾은 캐릭터들 중 가장 가까운 액터를 블랙보드의 targetToAttack에 저장한다.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController All_AI_Ref;
	Pawn AI_Char_Ref;
	EObjectTypeQuery EObject_Arr;
	Vector AI_Location;
	Float F_AttackRange;
};

