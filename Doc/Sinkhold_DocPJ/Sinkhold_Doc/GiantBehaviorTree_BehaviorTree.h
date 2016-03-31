#pragma once

/**
@brief ���̾�Ʈ�� �����̺�� Ʈ��
@details ���̾�Ʈ�� �ൿ ����� ��Ʈ�� �Ѵ�.
*/
class GiantBehaviorTree_BehaviorTree :
	public BehaviorTree
{
public:
	/**
	@brief ��Ʈ ���
	@details �����̺�� Ʈ���� ��Ʈ ���.
	@param blackboard �����̺�� Ʈ������ ����ϴ� ������.
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
	@details ���� ���� ������ �� ���� ������ ����� ������ giantMeleeAttack�� ȣ���Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void adjacent(Object targetToAttack);

	/**
	@brief ����� ���� ���ڷ�����
	@details ���� ���Ÿ� ������ �� ���� ������ ����� ������ giantRangedAttack�� ȣ���Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void near(Object targetToAttack);

	/**
	@brief �ָ� ������ ���� ���ڷ�����
	@details ���� ���� ������ �� ���� ������ ������ ������ giantApproach�� ȣ���Ѵ�.
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
	@brief ���� ���� �½�ũ
	@details ��󿡰� ���� ���� ����� �����Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void giantMeleeAttack(Object targetToAttack);

	/**
	@brief ���Ÿ� ���� �½�ũ
	@details ��󿡰� ���Ÿ� ���� ����� �����Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void giantRangedAttack(Object targetToAttack);

	/**
	@brief ���� �½�ũ
	@details ������ ��󿡰� �����ϴ� ����� �����Ѵ�.
	@param targetToAttack ������ ���.
	*/
	void giantApproach(Object targetToAttack);

private:
	EnemyBlackboard_Blackboard blackboard;
};

