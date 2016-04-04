#pragma once

/**
@brief 팀원 AI 서비스
@details 명령을 받았을 때, 변경되어야 할 변수들을 Set해준다. 그리고 총알의 장전 수를 최신화한다.
*/

class Service_Destination :
	public BTService
{
public:
	BlackboardKeySelector Destination;
	BlackboardKeySelector myCharacter;
	BlackboardKeySelector bullet;
	BlackboardKeySelector SelectAI;
	BlackboardKeySelector Command;
	BlackboardKeySelector OriginalRotation;
	AI_Person AI_Person_Ref;
	Shotgun_AI_Person Storm_Ref;
	M4A1_AI_Person M4A1_Ref;
	AWP_AI_Person AWP_Ref;

	/**
	@brief 서비스 틱 이벤트
	@details 총알 수를 Set해주는 서비스
	@details 현재의 총알 수를 가저와 bullet 블랙보드 변수에 Set함
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

	/**
	@brief 서비스 활성화 이벤트
	@details 명령을 받았다면 moveToPointEvent를 활성화되어 Destination과 Command 변수가 Set되고, 아니라면 followOnEvent가 활성화되어 Command를 Set하고 Destination를 지운다. 
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph ReceiveActivation(Actor OwnerActor);

	/**
	@brief 커스텀 이벤트
	@details Destination과 Command 변수가 Set된다. (목적지가 Set된다)
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph moveToPointEvent(Vector Point);

	/**
	@brief 커스텀 이벤트
	@details Command를 Set하고 Destination를 지운다. (목적지를 지운다.)
	@param OwnerActor AI 컨트롤러.
	*/
	EventGraph followOnEvent();
};

