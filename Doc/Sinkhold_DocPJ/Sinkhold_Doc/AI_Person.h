#pragma once
#include "Person_Character.h"
/**
@brief  AI 팀원 클래스.
@details
@details ....
@details
*/
class AI_Person :
	public Person_Character
{
public:

	/**
	@brief Tick 이벤트.
	@details 매 프레임마다 실행되는 이벤트.
	@details 총을 쏘고 있는 중인지 체크한다.
	@details 디버깅용 Hp Bar를 표시한다.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventtick'
	*/
	EventGraph Tick(float DeltaSeconds);

	/**
	@brief 사격 명령이 들어옴.
	@details AI 처리 블루프린트에서 사격 명령(이벤트)를 실행.
	@param _delta_seconds 프레임간 시간 간격
	@param _end_location 사격 포인트
	@param _get_object 사격대상
	*/
	void actionAI_OnFile(float _delta_seconds, Vector _end_location, Object _get_object);

	/**
	@brief 재장전
	*/
	void actionAI_Reload();
};

