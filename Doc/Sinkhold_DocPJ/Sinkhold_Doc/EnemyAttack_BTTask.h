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
	EventGraph ReceiveTick();
	EventGraph ReceiveExecute();

	BlackboardKeySelector targetToAttack;
private:
	Vector myLocation;
	Pawn myself;
};

