#pragma once

/**
@brief ����AI���� �⺻���� �����̺�� Ʈ��
@details ��� �������� �ൿ ����� ��Ʈ�� �Ѵ�.
*/

class BT_Base :
	public BehaviorTree
{
public:
	/**
	@brief ��Ʈ ���
	@details �����̺�� Ʈ���� ��Ʈ ���.
	@param blackboard �����̺�� Ʈ������ ����ϴ� ������.
	*/
	void root(BB_Humen blackboard);

	/**
	@brief ���񽺸� ������ �б� ���
	@details Service_updateMyLocaion�� Service_ScanEnemyCharacter, Service_Destination ���񽺸� ������ �ִ�.
	@param myCharacter�� �ֺ��� ���� �߰ߵȴٸ� on, �ƴϸ� flase�� ��
	@param myLocation�� �÷��̾��� ��ġ�� �ǽð����� ������Ʈ��
	@param Destination�� ����̵��ÿ� �ش� ������ ��ġ�� �����Ѵ�.
	@param distanceCheck�� �÷��̾�� AI�� �Ÿ��� �ָ� true, �ƴϸ� false�� ���õȴ�.
	@param targetToAttack�� �ѵ� AI��Ÿ��� ���� �߰��ϴ� �����ȿ� ���� �ִٸ� �ش� ���� Object�� ����
	@param attackRange�� AI�� ����ִ� ���⸦ �˻��ؼ�, ���⿡ ���� ��Ÿ� �����ִ� �ʱⰪ.
	@param bullet�� ���� �����Ǿ� �ִ� ź ���� ������Ʈ��.
	@param SelectAI�� �÷��̾ ����AI �� �ϳ��� �����ϸ� ���õ� ����AI�� Object�� ������.
	@param Command�� ����� ���ȴٸ� True, �ƴϸ� False�� ������.
	@param OriginaRotation�� ���� �� �̻����� Rotation�� �����ϱ� ���� �ӽ÷� ���� AI���� ó�� Rotation �ʱⰪ.
	*/
	void selector(Object myCharacter, Vector myLocation, Vector Destination, Bool distanceCheck, Object targetToAttack, Float attackRange, Integer bullet, Object SelectAI, Bool Command, Rotator OriginalRotation);

	/**
	@brief ��� ���� ���ڷ�����
	@details Command�� false��� Find�� ����.
	@param Command�� ����� �������� ������ üũ�ϱ� ����.
	*/
	void Idle(Bool Command);

	/**
	@brief �� �߰� ���� ���ڷ�����
	@details Idle�� ���� Find�� ����Ǹ� targetToAttack = true, bullet > 0, �÷��̾ ��ó�� �ִٸ� AttackAndReload�� ����ȴ�.
	@param targetToAttack�� ������ ���.
	@param bullet�� ���� �Ѿ��� ������ ��
	@param Dec_PlayerCheck�� ������ �����ȿ� �÷��̾ �ִ��� üũ. �ش� ������ ���� ������� ���ڷ����� ���Ϸ� ���� ��ȯ�ȴ�.
	*/
	void Find(Object targetToAttack, Integer bullet, Bool Dec_PlayerCheck);

	/**
	@brief ���� �����ϴ� �½�ũ
	@details Find�� ���� AttackAndReload�� ����Ǹ� ������ targetToAttack�� ��ġ�� ������ ������.
	@param targetToAttack�� ������ ���.
	@param bullet�� ���� �Ѿ��� ������ ��
	*/
	void AttackAndReload(Object targetToAttack, Integer bullet);
	
	/**
	@brief �÷��̾ ������ �ִ��� Ȯ���ϴ� ���ڷ�����
	@details Command == False, myCharacter == True�� �����ϸ� FollowMe�� ������.
	@param commnad�� ����� ���ȴ��� Ȯ���ϴ� ����
	@param myCharacter�� �÷��̾� Object
	@param Dec_Rotaioninit�� �߰��Ǿ� �ִµ�, �ʱ� Rotation ������ ���� ���ڷ�������. (FindPlayer�� �б�������� �ƹ��� ������ ��������.)
	*/
	void FindPlayer(Bool Command, Object myCharacter, Rotator OriginalRotation);

	/**
	@brief ���� ������� �ϴ� �½�ũ
	@details FindPlayer�� ������ �����Ѵٸ� ���� �����.
	@param Command�� ����� ���ȴ����� ���� ����
	@param Destination�� ����̵��� �������� ��ġ
	@param myLocation�� ���� �÷��̾��� ��ġ
	@param distanceCheck�� �÷��̾�� AI�� �Ÿ��� üũ�ϴ� �κ�
	*/
	void FollowMe(Bool Command, Vector Destination, Vector myLocation, Bool distanceCheck);

	/**
	@brief ���� ������ �ִ��� Ȯ���ϴ� ���ڷ�����
	@details Command == True, targetToAttack == False�� �����ϸ� myCharacter�� ���� MoveDestination�� AttackAndReload�� ������.
	@param commnad�� ����� ���ȴ��� Ȯ���ϴ� ����
	@param myCharacter�� �÷��̾� Object
	@param targetToAttack�� ������ �� Object
	*/
	void FindEnemy(Object myCharacyer, Bool Command, Object targetToAttack);

	/**
	@brief ����� �޾Ƽ� �������� �̵��ϴ� �½�ũ
	@details FindEnemy�� ������ �����Ѵٸ� ���� �����.
	@param Command�� ����� ���ȴ����� ���� ����
	@param Destination�� ����̵��� �������� ��ġ
	@param myLocation�� ���� �÷��̾��� ��ġ
	@param distanceCheck�� �÷��̾�� AI�� �Ÿ��� üũ�ϴ� �κ�
	*/
	void MoveDestination(Bool Command, Vector Destination, Vector, myLocation, Bool distanceCheck);

};

