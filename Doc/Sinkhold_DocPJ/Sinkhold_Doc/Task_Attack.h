#pragma once

/**
@brief ���� AI �½�ũ
@details ���� �߰��ϸ� ó�ٺ��� ������ �Ѵ�.
*/

class Task_Attack :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;
	BlackboardKeySelector bullet;

	/**
	@brief �½�ũ ���� �̺�Ʈ
	@details targetToAttack�� Object�� �����Ǹ� ���� ó�ٺ���,
	@details  ActionAIonFire�� ȣ���Ͽ� ���� ������ �Ѵ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController AI_Con_Ref;
	AIPerson AI_Person_Ref;
	Float Delta_Seconds;
	PersonCharacter Person_Char_Ref;

};

