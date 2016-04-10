#pragma once

/**
@brief 탄창 픽업 아이템
@details 플레이어가 먹으면 탄창을 채워주는 액터.
*/
class PickupAmmo_Actor :
	public Actor
{
public:
	/**
	@brief 오버랩 이벤트
	@details 오버랩한 플레이어 캐릭터의 탄창을 채워준다.
	@param OtherActor 이 액터와 오버랩한 액터.
	*/
	EventGraph OnComponentBeginOverlap(Actor OtherActor);
};

