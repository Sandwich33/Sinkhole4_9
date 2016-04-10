#pragma once

/**
@brief 몬스터 스폰 지역
@details 볼륨 안의 지역에 무작위로 SpawningPoint 를 스폰한다.
*/
class SpawningVloume_Actor :
	public Actor
{
public:
	/**
	@brief 틱 이벤트
	@details 볼륨 안의 지역에 무작위로 SpawningPoint 를 스폰한다.
	@details 볼륨 안의 적 캐릭터 수를 조사해서 지정된 수 이상이면 스폰을 막는다.
	*/
	EventGraph Tick();
};

