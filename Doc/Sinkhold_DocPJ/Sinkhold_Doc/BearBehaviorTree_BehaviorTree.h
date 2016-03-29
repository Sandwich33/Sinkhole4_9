#pragma once
#include "EnemyBlackboard_Blackboard.h"

/**
@brief ���� �����̺�� Ʈ��
@details ���� �ൿ ����� ��Ʈ�� �Ѵ�.
*/
class BearBehaviorTree_BehaviorTree :
	public BehaviorTree
{
public:
	/**
	@brief ��Ʈ ���
	@details �����̺�� Ʈ���� ��Ʈ ���.
	@param blackboard �����̺��� ����ϴ� ������.
	*/
	void root(EnemyBlackboard_Blackboard blackboard);

	/**
	@brief ���񽺸� ������ �б� ���
	@details ScanPersonCharacter�� SetRandomDestination ���񽺸� ������ �ִ�.
	@param targetToAttack �ΰ� ĳ���͸� �߰��ϸ� �� ������ ����ȴ�.
	@param destination ���� -2000 ~ +2000 ������ ���� ��ġ�� ����ȴ�.
	*/
	void selector(Object targetToAttack, Vector destination);

	/**
	@brief ��� ���� ���ڷ�����
	@details targetToAttack�� ������� ��� �������� �б�ȴ�.
	@param targetToAttack ������ ���.
	*/
	void idle(Object targetToAttack);

	/**
	@brief ���� ���� ���ڷ�����
	@details targetToAttack�� ���� ������ �������� �б�ȴ�.
	@param targetToAttack ������ ���.
	*/
	void foundPerson(Object targetToAttack);

	/**
	@brief ����Ÿ��� ���ڷ�����
	@details ������ ����� ���� destination�� ���� ������ moveTo�� ȣ���Ѵ�.
	@param destination �̵��� ������.
	*/
	void wander(Vector destination);

	/**
	@brief ���� ���� ���ڷ�����
	@details ���� ���� ������ �� ���� ������ ����� ������ attack�� ȣ���Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void closeEnough(Object targetToAttack);

	/**
	@brief �ָ� ������ ���� ���ڷ�����
	@details ���� ���� ������ �� ���� ������ ������ ������ approach�� ȣ���Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void notClose(Object targetToAttack);

	/**
	@brief �̵� �½�ũ
	@details �𸮾󿡼� �����ϴ� �⺻ �̵� �½�ũ.
	@param destination �̵��� ������.
	*/
	void moveTo(Vector destination);

	/**
	@brief ���� �½�ũ
	@details ��󿡰� ���� ���� ����� �����Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void attack(Object targetToAttack);

	/**
	@brief ���� �½�ũ
	@details ������ ��󿡰� �����ϴ� ����� �����Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void approach(Object targetToAttack);

private:
	EnemyBlackboard_Blackboard blackboard;
};

