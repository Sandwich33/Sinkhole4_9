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

	/**
	@brief �½�ũ ���� �̺�Ʈ
	@details ���̾�Ʈ�� ������ ��󿡰� �����ϰ� �Ѵ�.
	@details ��Ÿ���� �ƴϸ� �뽬 ��ų�� ����� �� �ִ�.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveExecute(Actor OwnerActor);

	/**
	@brief �½�ũ �ߴ� �̺�Ʈ
	@details ���� �帧�� �������� �뽬�� ������.
	*/
	EventGraph ReceiveAbort();
};

