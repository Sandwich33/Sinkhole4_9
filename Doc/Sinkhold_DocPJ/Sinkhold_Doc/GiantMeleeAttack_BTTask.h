#pragma once
#include "Giant_Enemy.h"

/**
@brief �� AI �½�ũ
@details ���̾�Ʈ ���� ���� ���� ��ɰ� ���� ���� ��ų.
*/
class GiantMeleeAttack_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;
private:
	Vector myLocation;
	Pawn myself;
};

