#pragma once

/**
@brief �� AI ������
@details �����̺�� Ʈ���� �帧�� �����ϱ� ���� �������� ��Ƶδ� ���̴�.
*/
class EnemyBlackboard_Blackboard :
	public Blackboard
{
public:
	Object targetToAttack;
	Vector destination;
};

