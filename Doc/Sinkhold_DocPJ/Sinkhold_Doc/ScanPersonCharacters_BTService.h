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

	/**
	@brief 서비스 활성화 이벤트
	@details allTheSameActors를 초기화한다.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveActivation(Actor OwnerActor);

	/**
	@brief 서비스 틱 이벤트
	@details 캐릭터 주변 일정 범위 안의 인간 캐릭터를 찾는다.
	@details 찾은 캐릭터들 중 가장 가까운 액터를 블랙보드의 targetToAttack에 저장한다.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);
private:
	Vector myLocation;
	Actor allTheSameActors[];
	float closest;
	Actor closestActor;
};

