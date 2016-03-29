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

	/**
	@brief �½�ũ ƽ �̺�Ʈ
	@details ĳ���Ͱ� ������ ����� �ٶ󺸰� �ϰ� onAttack�� ȣ���Ѵ�.
	*/
	EventGraph ReceiveTick();

	/**
	@brief �½�ũ ���� �̺�Ʈ
	@details myself�� myLocation�� �ʱ�ȭ�Ѵ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveExecute(Actor OwnerActor);
private:
	Vector myLocation;
	Pawn myself;
};

