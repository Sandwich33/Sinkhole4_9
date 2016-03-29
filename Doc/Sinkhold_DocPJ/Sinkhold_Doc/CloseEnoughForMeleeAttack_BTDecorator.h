#pragma once

/**
@brief �� AI ���ڷ�����
@details ���� ������ �� �� �ִ��� �Ǵ��ϱ� ���� ���� ������ �Ÿ��� �˻��Ѵ�.
*/
class CloseEnoughForMeleeAttack_BTDecorator :
	public BTDecorator
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief ���ڷ����� ���� �˻� �Լ�
	@details AI ��Ʈ�ѷ��� ��Ʈ���ϴ� ���� ������ ��� ������ �Ÿ��� �˻��Ѵ�.
	@details �Ÿ��� ATTACKABLE_DISTANCE�� ������ ������ True�� �����Ѵ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);
private:
	float ATTACKABLE_DISTANCE;
};

