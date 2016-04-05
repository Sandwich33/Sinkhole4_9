#pragma once

/**
@brief ���� AI ����
@details �� ƽ���� ���� ����� ã�´�. �߰��ϸ� ����� �������� targetToAttack�� set�Ѵ�.
*/

class Service_ScanEnemyCharacter :
	public BTService
{
public:
	BlackboardKeySelector targetToAttack;
	BlackboardKeySelector attackRange;

	/**
	@brief ���� ƽ �̺�Ʈ
	@details ĳ���� �ֺ� ���� ���� ���� �� ĳ���͸� ã�´�.
	@details ã�� ĳ���͵� �� ���� ����� ���͸� �������� targetToAttack�� �����Ѵ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

private:
	AllAIController All_AI_Ref;
	Pawn AI_Char_Ref;
	EObjectTypeQuery EObject_Arr;
	Vector AI_Location;
	Float F_AttackRange;
};

