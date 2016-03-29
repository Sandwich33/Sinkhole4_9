
#pragma once
#include "EnemyBlackboard_Blackboard.h"
/**
@brief 곰의 비헤이비어 트리
@details
@details 곰의 행동 방식을 컨트롤 한다.
@details
*/
class BearBehaviorTree_BehaviorTree :
	public BehaviorTree
{
public:
	EnemyBlackboard_Blackboard blackboard;
	
	/**
	@brief 재장전 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 재장전 애니메이션을 재생 후 reloadDispatcher_Event 를 실행한다.
	@param _total_bullet 소유하고 있는 전체 총알의 수.
	*/
	void Root();

	/**
	@brief 재장전 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 재장전 애니메이션을 재생 후 reloadDispatcher_Event 를 실행한다.
	@param _total_bullet 소유하고 있는 전체 총알의 수.
	*/
	void Selector();

	/**
	@brief 재장전 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 재장전 애니메이션을 재생 후 reloadDispatcher_Event 를 실행한다.
	@param _total_bullet 소유하고 있는 전체 총알의 수.
	*/
	void idle(BlackboardKey targetToAttack);

	/**
	@brief 재장전 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 재장전 애니메이션을 재생 후 reloadDispatcher_Event 를 실행한다.
	@param _total_bullet 소유하고 있는 전체 총알의 수.
	*/
	void foundperson();
	void wander();
	void closeenough();
	void notclose();
	void moveto();
	void attack();
	void approach();
};

