
#pragma once
#include "EnemyBlackboard_Blackboard.h"
/**
@brief ���� �����̺�� Ʈ��
@details
@details ���� �ൿ ����� ��Ʈ�� �Ѵ�.
@details
*/
class BearBehaviorTree_BehaviorTree :
	public BehaviorTree
{
public:
	EnemyBlackboard_Blackboard blackboard;
	
	/**
	@brief ������ Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ������ �ִϸ��̼��� ��� �� reloadDispatcher_Event �� �����Ѵ�.
	@param _total_bullet �����ϰ� �ִ� ��ü �Ѿ��� ��.
	*/
	void Root();

	/**
	@brief ������ Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ������ �ִϸ��̼��� ��� �� reloadDispatcher_Event �� �����Ѵ�.
	@param _total_bullet �����ϰ� �ִ� ��ü �Ѿ��� ��.
	*/
	void Selector();

	/**
	@brief ������ Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ������ �ִϸ��̼��� ��� �� reloadDispatcher_Event �� �����Ѵ�.
	@param _total_bullet �����ϰ� �ִ� ��ü �Ѿ��� ��.
	*/
	void idle(BlackboardKey targetToAttack);

	/**
	@brief ������ Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ������ �ִϸ��̼��� ��� �� reloadDispatcher_Event �� �����Ѵ�.
	@param _total_bullet �����ϰ� �ִ� ��ü �Ѿ��� ��.
	*/
	void foundperson();
	void wander();
	void closeenough();
	void notclose();
	void moveto();
	void attack();
	void approach();
};

