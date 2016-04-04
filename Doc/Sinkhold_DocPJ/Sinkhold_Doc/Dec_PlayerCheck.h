#pragma once

/**
@brief ���� AI ���ڷ�����
@details myCharacter�� ���� ���� �÷��̾ AI��ó�� �ִ��� Ȯ���Ѵ�. 
*/

class Dec_PlayerCheck :
	public BTDecorator
{
public:
	BlackboardKeySelector myCharacter;
	BlackboardKeySelector targetToAttack;

	/**
	@brief ���ڷ����� ���� �˻� �Լ�
	@details myCharacter������ true�� �ִٰ� �ν��ϰ� False�� ���ٰ� �ν���.
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	Boolean PerformConditionCheck(Actor OwnerActor);

};

