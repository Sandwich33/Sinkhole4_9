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

	/**
	@brief �½�ũ ƽ �̺�Ʈ
	@details ���̾�Ʈ�� ������ ����� �ٶ󺸰� �ϰ� onAttack�� ȣ���Ѵ�.
	@details ��Ÿ���� �ƴϸ� ���� ���� ��ų�� ����� �� �ִ�.
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

