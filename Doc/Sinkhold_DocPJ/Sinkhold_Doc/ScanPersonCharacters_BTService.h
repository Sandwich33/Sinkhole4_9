#pragma once

/**
@brief �� AI ����
@details �� ƽ���� ���� ����� ã�´�. �߰��ϸ� ����� �������� targetToAttack�� set�Ѵ�.
*/
class ScanPersonCharacters_BTService :
	public BTService
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief ���� Ȱ��ȭ �̺�Ʈ
	@details allTheSameActors�� �ʱ�ȭ�Ѵ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveActivation(Actor OwnerActor);

	/**
	@brief ���� ƽ �̺�Ʈ
	@details ĳ���� �ֺ� ���� ���� ���� �ΰ� ĳ���͸� ã�´�.
	@details ã�� ĳ���͵� �� ���� ����� ���͸� �������� targetToAttack�� �����Ѵ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);
private:
	Vector myLocation;
	Actor allTheSameActors[];
	float closest;
	Actor closestActor;
};

