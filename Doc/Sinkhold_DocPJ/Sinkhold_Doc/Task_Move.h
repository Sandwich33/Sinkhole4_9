#pragma once

/**
@brief ���� AI �½�ũ
@details ����� �޾Ƽ� �������� ����, 
@details ���� ����ð��� �����ϰ� �̵��Ѵ�. 
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
	@brief �½�ũ ���� �̺�Ʈ
	@details ����� ���ȴ����� Ȯ���ϰ�,
	@details ����� ���ȴٸ� Destination���� ��ġ�� �̵�.
	@details �ƴ϶�� myLocation ��ġ�� �����.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController AI_Con_Ref;
	Pawn AI_Char_Ref;
	PersonCharacter Person_Char_Ref;
};

