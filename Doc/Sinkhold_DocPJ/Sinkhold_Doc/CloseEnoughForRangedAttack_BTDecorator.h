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
};

