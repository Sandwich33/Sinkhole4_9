#pragma once

/**
@brief ���� AI ����
@details �� ƽ���� ���� ������� �÷��̾��� ��ġ�� ������������ ������ġ�� Set�Ѵ�.
*/

class Service_updateMyLocation :
	public BTService
{
public:
	BlackboardKeySelector myCharacter;
	BlackboardKeySelector myLocation;
	BlackboardKeySelector destination;
	BlackboardKeySelector distance_Check;
	/**
	@brief ���� ƽ �̺�Ʈ
	@details �÷��̾� �ֺ��� ������������ ������ġ�� Set��.
	@details ã�� ĳ���͵� �� ���� ����� ���͸� �������� targetToAttack�� �����Ѵ�.
	@details �÷��̾�� AI�� �ָ� �������� ���󰡵��� myCharacter Set.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController AI_Con_Ref;
	Pawn AI_Char_Ref;
	Pawn My_Char_Ref;
	EObjectTypeQuery EObject_Arr;
	NavigationEvent Nav_Value;
};

