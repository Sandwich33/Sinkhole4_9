#pragma once
#include "Giant_Enemy.h"

/**
@brief �� AI ���ڷ�����
@details ���̾�Ʈ ���� ���Ÿ� ������ �� �� �ִ��� �Ǵ��ϱ� ���� ���� ������ �Ÿ��� �˻��Ѵ�.
*/
class GiantCloseEnoughForRangedAttack_BTDecorator :
	public BTDecorator
{
public:
	BlackboardKeySelector targetToAttack;
	float attackableDistance;
};

