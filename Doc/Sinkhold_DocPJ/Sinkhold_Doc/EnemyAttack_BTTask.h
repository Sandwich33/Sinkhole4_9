#pragma once
#include "Enemy_Character.h"

/**
@brief �� AI �½�ũ
@details �⺻ ���� ���� ����� �Ѵ�.
*/
class EnemyAttack_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;
private:
	Vector myLocation;
	Pawn myself;
};

