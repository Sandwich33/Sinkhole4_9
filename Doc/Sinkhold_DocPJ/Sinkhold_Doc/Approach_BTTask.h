#pragma once

/**
@brief �� AI �½�ũ
@details �����Ϸ��� ��󿡰� �����ϴ� ����� �Ѵ�.
*/
class Approach_BTTask :
	public BTTask
{
public:
	BlackboardKeySelector targetToAttack;

	/**
	@brief �½�ũ ���� �̺�Ʈ
	@details AI ��Ʈ�ѷ��� ��Ʈ���ϴ� ���� ������ ����� ��ġ�� �̵���Ų��.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveExecute(Actor OwnerActor);
};

