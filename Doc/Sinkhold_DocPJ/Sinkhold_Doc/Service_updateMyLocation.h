#pragma once

/**
@brief 팀원 AI 서비스
@details 매 틱마다 나를 따라오는 플레이어의 위치를 일정범위안의 랜덤위치를 Set한다.
*/

class Service_updateMyLocation :
	public BTService
{
public:
	BlackboardKeySelector myCharacter;
	BlackboardKeySelector myLocation;
	BlackboardKeySelector destination;
	BlackboardKeySelector distance_Check;
	/**
	@brief 서비스 틱 이벤트
	@details 플레이어 주변에 일정범위안의 랜덤위치를 Set함.
	@details 찾은 캐릭터들 중 가장 가까운 액터를 블랙보드의 targetToAttack에 저장한다.
	@details 플레이어와 AI가 멀리 떨어지면 따라가도록 myCharacter Set.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController AI_Con_Ref;
	Pawn AI_Char_Ref;
	Pawn My_Char_Ref;
	EObjectTypeQuery EObject_Arr;
	NavigationEvent Nav_Value;
};

