#pragma once

/**
@brief źâ �Ⱦ� ������
@details �÷��̾ ������ źâ�� ä���ִ� ����.
*/
class PickupAmmo_Actor :
	public Actor
{
public:
	/**
	@brief ������ �̺�Ʈ
	@details �������� �÷��̾� ĳ������ źâ�� ä���ش�.
	@param OtherActor �� ���Ϳ� �������� ����.
	*/
	EventGraph OnComponentBeginOverlap(Actor OtherActor);
};

