#pragma once

/**
@brief 팀원 AI 태스크
@details 적을 발견하면 처다보며 공격을 한다.
*/

class Task_Attack :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;
	BlackboardKeySelector bullet;

	/**
	@brief 태스크 실행 이벤트
	@details targetToAttack에 Object가 설정되면 적을 처다보고,
	@details  ActionAIonFire를 호출하여 적을 공격을 한다.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController AI_Con_Ref;
	AIPerson AI_Person_Ref;
	Float Delta_Seconds;
	PersonCharacter Person_Char_Ref;

};

