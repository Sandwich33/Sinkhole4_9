#pragma once

/**
@brief 팀원 AI 태스크
@details 명령을 받아서 목적지로 갈지, 
@details 나를 따라올건지 결정하고 이동한다. 
*/

class Task_Move :
	public BTTask
{
public:
	BlackboardKeySelector Command;
	BlackboardKeySelector Destination;
	BlackboardKeySelector myLocation;
	BlackboardKeySelector distanceCheck;

	/**
	@brief 태스크 실행 이벤트
	@details 명령을 내렸는지를 확인하고,
	@details 명령을 내렸다면 Destination으로 위치로 이동.
	@details 아니라면 myLocation 위치로 따라옴.
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController AI_Con_Ref;
	Pawn AI_Char_Ref;
	PersonCharacter Person_Char_Ref;
};

