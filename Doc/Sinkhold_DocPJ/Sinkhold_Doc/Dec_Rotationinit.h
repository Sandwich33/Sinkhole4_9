#pragma once

/**
@brief ���� AI ���ڷ�����
@details AI�� �ʱ� Rotation�� �ʱ�ȭ�� ���� ���ڷ�����
*/

class Dec_Rotationinit :
	public BTDecorator
{
public:
	BlackboardKeySelector OriginalRotation;
	
	/**
	@brief �ʱ�ȭ�� ���� ���ڷ�����
	@details �ܼ��� AI���� �ʱ� Rotation�� Set��
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);
};

