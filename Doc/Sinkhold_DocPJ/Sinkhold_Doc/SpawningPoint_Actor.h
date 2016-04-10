#pragma once

/**
@brief 몬스터 스폰 지점
@details 몬스터 한 마리와 파티클 하나를 스폰하고 사라지는 액터.
*/
class SpawningPoint_Actor :
	public Actor
{
public:
	/**
	@brief 컨스트럭션 스크립트
	@details 소환할 적 캐릭터 클래스의 배열을 만든다.
	*/
	Construction Script();

	/**
	@brief 시작 이벤트
	@details 파티클 하나를 스폰하고, 배열에서 몬스터 클래스를 랜덤으로 가져와 스폰한다.
	*/
	EventGraph BeginPlay();
};

