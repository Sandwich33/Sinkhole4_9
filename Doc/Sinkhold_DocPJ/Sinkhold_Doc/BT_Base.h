#pragma once

/**
@brief 팀원AI들의 기본적인 비헤이비어 트리
@details 모든 팀원들의 행동 방식을 컨트롤 한다.
*/

class BT_Base :
	public BehaviorTree
{
public:
	/**
	@brief 루트 노드
	@details 비헤이비어 트리의 루트 노드.
	@param blackboard 비헤이비어 트리에서 사용하는 블랙보드.
	*/
	void root(BB_Humen blackboard);

	/**
	@brief 서비스를 가지는 분기 노드
	@details Service_updateMyLocaion과 Service_ScanEnemyCharacter, Service_Destination 서비스를 가지고 있다.
	@param myCharacter는 주변에 적이 발견된다면 on, 아니면 flase로 됨
	@param myLocation은 플레이어의 위치를 실시간으로 업데이트함
	@param Destination은 명령이동시에 해당 목적지 위치를 저장한다.
	@param distanceCheck는 플레이어와 AI의 거리가 멀면 true, 아니면 false로 세팅된다.
	@param targetToAttack은 총든 AI사거리에 따라 발견하는 범위안에 적이 있다면 해당 적의 Object를 세팅
	@param attackRange는 AI가 들고있는 무기를 검색해서, 무기에 따라 사거리 정해주는 초기값.
	@param bullet은 현재 장전되어 있는 탄 수를 업데이트함.
	@param SelectAI는 플레이어가 팀원AI 중 하나를 선택하면 선택된 팀원AI의 Object를 세팅함.
	@param Command는 명령을 내렸다면 True, 아니면 False를 세팅함.
	@param OriginaRotation은 공격 후 이상해진 Rotation을 복구하기 위해 임시로 만든 AI들의 처음 Rotation 초기값.
	*/
	void selector(Object myCharacter, Vector myLocation, Vector Destination, Bool distanceCheck, Object targetToAttack, Float attackRange, Integer bullet, Object SelectAI, Bool Command, Rotator OriginalRotation);

	/**
	@brief 대기 상태 데코레이터
	@details Command가 false라면 Find로 간다.
	@param Command는 명령이 내려지지 않음을 체크하기 위함.
	*/
	void Idle(Bool Command);

	/**
	@brief 적 발견 상태 데코레이터
	@details Idle에 의해 Find가 실행되면 targetToAttack = true, bullet > 0, 플레이어가 근처에 있다면 AttackAndReload가 실행된다.
	@param targetToAttack은 공격할 대상.
	@param bullet은 현재 총알이 장전된 수
	@param Dec_PlayerCheck는 설정된 범위안에 플레이어가 있는지 체크. 해당 변수는 따로 만들어진 데코레이터 파일로 인해 반환된다.
	*/
	void Find(Object targetToAttack, Integer bullet, Bool Dec_PlayerCheck);

	/**
	@brief 적을 공격하는 태스크
	@details Find에 의해 AttackAndReload가 실행되면 설정된 targetToAttack의 위치로 공격을 시작함.
	@param targetToAttack은 공격할 대상.
	@param bullet은 현재 총알이 장전된 수
	*/
	void AttackAndReload(Object targetToAttack, Integer bullet);
	
	/**
	@brief 플레이어가 범위에 있는지 확인하는 데코레이터
	@details Command == False, myCharacter == True이 만족하면 FollowMe를 실행함.
	@param commnad는 명령을 내렸는지 확인하는 변수
	@param myCharacter는 플레이어 Object
	@param Dec_Rotaioninit가 추가되어 있는데, 초기 Rotation 저장을 위한 데코레이터임. (FindPlayer의 분기과정에서 아무런 영향을 주지않음.)
	*/
	void FindPlayer(Bool Command, Object myCharacter, Rotator OriginalRotation);

	/**
	@brief 나를 따라오게 하는 태스크
	@details FindPlayer가 조건을 만족한다면 나를 따라옴.
	@param Command는 명령을 내렸는지에 따른 변수
	@param Destination은 명령이동시 목적지의 위치
	@param myLocation은 현재 플레이어의 위치
	@param distanceCheck는 플레이어와 AI의 거리를 체크하는 부분
	*/
	void FollowMe(Bool Command, Vector Destination, Vector myLocation, Bool distanceCheck);

	/**
	@brief 적이 범위에 있는지 확인하는 데코레이터
	@details Command == True, targetToAttack == False가 만족하면 myCharacter에 따라 MoveDestination과 AttackAndReload를 실행함.
	@param commnad는 명령을 내렸는지 확인하는 변수
	@param myCharacter는 플레이어 Object
	@param targetToAttack은 공격할 적 Object
	*/
	void FindEnemy(Object myCharacyer, Bool Command, Object targetToAttack);

	/**
	@brief 명령을 받아서 목적지로 이동하는 태스크
	@details FindEnemy가 조건을 만족한다면 나를 따라옴.
	@param Command는 명령을 내렸는지에 따른 변수
	@param Destination은 명령이동시 목적지의 위치
	@param myLocation은 현재 플레이어의 위치
	@param distanceCheck는 플레이어와 AI의 거리를 체크하는 부분
	*/
	void MoveDestination(Bool Command, Vector Destination, Vector, myLocation, Bool distanceCheck);

};

