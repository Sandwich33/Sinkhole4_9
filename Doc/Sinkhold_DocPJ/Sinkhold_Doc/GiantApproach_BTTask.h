#pragma once
#include "Giant_Enemy.h"

/**
@brief �� AI �½�ũ
@details ���̾�Ʈ ���� �뽬 ��ų.
*/
class GiantApproach_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;
};

