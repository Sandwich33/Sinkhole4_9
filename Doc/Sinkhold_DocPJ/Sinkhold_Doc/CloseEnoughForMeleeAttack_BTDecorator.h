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
private:
	float ATTACKABLE_DISTANCE;
};

