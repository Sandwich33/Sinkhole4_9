#pragma once
#include "EnemyBlackboard_Blackboard.h"

/**
@brief 곰의 비헤이비어 트리
@details 곰의 행동 방식을 컨트롤 한다.
*/
class BearBehaviorTree_BehaviorTree :
	public BehaviorTree
{
public:
	/**
	@brief 루트 노드
	@details 비헤이비어 트리의 루트 노드.
	@param blackboard 비헤이비어에서 사용하는 블랙보드.
	*/
	void root(EnemyBlackboard_Blackboard blackboard);

	/**
	@brief 서비스를 가지는 분기 노드
	@details ScanPersonCharacter와 SetRandomDestination 서비스를 가지고 있다.
	@param targetToAttack 인간 캐릭터를 발견하면 이 변수에 저장된다.
	@param destination 주위 -2000 ~ +2000 범위의 랜덤 위치가 저장된다.
	*/
	void selector(Object targetToAttack, Vector destination);

	/**
	@brief 대기 상태 데코레이터
	@details targetToAttack이 비어있을 경우 이쪽으로 분기된다.
	@param targetToAttack 공격할 대상.
	*/
	void idle(Object targetToAttack);

	/**
	@brief 전투 상태 데코레이터
	@details targetToAttack에 값이 있으면 이쪽으로 분기된다.
	@param targetToAttack 공격할 대상.
	*/
	void foundPerson(Object targetToAttack);

	/**
	@brief 어슬렁거리기 데코레이터
	@details 공격할 대상이 없고 destination에 값이 있으면 moveTo를 호출한다.
	@param destination 이동할 목적지.
	*/
	void wander(Vector destination);

	/**
	@brief 근접 상태 데코레이터
	@details 적을 근접 공격할 수 있을 정도로 충분히 가까우면 attack을 호출한다.
	@param targetToAttack 공격할 대상.
	*/
	void closeEnough(Object targetToAttack);

	/**
	@brief 멀리 떨어진 상태 데코레이터
	@details 적을 근접 공격할 수 있을 정도로 가깝지 않으면 approach를 호출한다.
	@param targetToAttack 공격할 대상.
	*/
	void notClose(Object targetToAttack);

	/**
	@brief 이동 태스크
	@details 언리얼에서 제공하는 기본 이동 태스크.
	@param destination 이동할 목적지.
	*/
	void moveTo(Vector destination);

	/**
	@brief 공격 태스크
	@details 대상에게 근접 공격 기능을 수행한다.
	@param targetToAttack 공격할 대상.
	*/
	void attack(Object targetToAttack);

	/**
	@brief 접근 태스크
	@details 공격할 대상에게 접근하는 기능을 수행한다.
	@param targetToAttack 공격할 대상.
	*/
	void approach(Object targetToAttack);

private:
	EnemyBlackboard_Blackboard blackboard;
};

