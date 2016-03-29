#pragma once

/**
@brief �� AI ���ڷ�����
@details ���Ÿ� ������ �� �� �ִ��� �Ǵ��ϱ� ���� ���� ������ �Ÿ��� �˻��Ѵ�.
*/
class CloseEnoughForRangedAttack_BTDecorator :
	public BTDecorator
{
public:
	BlackboardKeySelector targetToAttack;
	float attackableDistance;

	/**
	@brief ���ڷ����� ���� �˻� �Լ�
	@details AI ��Ʈ�ѷ��� ��Ʈ���ϴ� ���� ������ ��� ������ �Ÿ��� �˻��Ѵ�.
	@details �Ÿ��� attackableDistance�� ������ ������ True�� �����Ѵ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);
};

