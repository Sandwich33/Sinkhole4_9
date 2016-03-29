#pragma once

/**
@brief 적 AI 태스크
@details 공격하려는 대상에게 접근하는 기능을 한다.
*/
class Approach_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief 태스크 실행 이벤트
	@details AI 컨트롤러가 컨트롤하는 폰을 공격할 대상의 위치로 이동시킨다.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveExecute(Actor OwnerActor);
};

