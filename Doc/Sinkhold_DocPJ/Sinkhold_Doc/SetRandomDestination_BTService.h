#pragma once

/**
@brief �� AI ����
@details �������� 0 ~ 10���� �ð��� ���� ������ ĳ������ �ֺ� -2000 ~ +2000 ���� ���� ���� ��ġ�� ã��
@details �������� destination�� set�ϰų� set���� �ʴ´�.
*/
class SetRandomDestination_BTService :
	public BTService
{
public:
	BlackboardKeySelector destination;
	BlackboardKeySelector targetToAttack;
};

