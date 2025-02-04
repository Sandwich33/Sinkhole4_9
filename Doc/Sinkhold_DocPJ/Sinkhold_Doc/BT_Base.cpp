#include "stdafx.h"
#include "BT_Base.h"
#include "Dec_PlayerCheck.h"
#include "Dec_Rotationinit.h"
#include "Service_Destination.h"
#include "Service_ScanEnemyCharacter.h"
#include "Service_updateMyLocation.h"
#include "Task_Attack.h"
#include "Task_Move.h"

void BT_Base::root(BB_Humen blackboard){
	selector();
}

void BT_Base::selector(Object myCharacter, Vector myLocation, Vector Destination, Bool distanceCheck, Object targetToAttack, Float attackRange, Integer bullet, Object SelectAI, Bool Command, Rotator OriginalRotation){
	Service_Destination::ReceiveActivation();
	Service_Destination::ReceiveTick();
	Service_updateMyLocation::ReceiveTick();
	Service_ScanEnemyCharacter::ReceiveTick();
	Idle();
	FindPlayer();
	FindEnemy3();
	FindEnemy();
	FindEnemy2();
}

void BT_Base::Idle(Bool Command){
	FindEnemy3();
}

void BT_Base::FindEnemy3(Object targetToAttack, Integer bullet){
	Dec_PlayerCheck::PerformConditionCheck();
	AttackAndReload();
}

void BT_Base::FindEnemy(Object myCharacyer, Bool Command, Object targetToAttack){
	Task_Move::ReceiveTick();
}

void BT_Base::FindEnemy2(Object myCharacyer, Bool Command, Object targetToAttack){
	Task_Attack::ReceiveTick();
}

void BT_Base::FindPlayer(Bool Command, Object myCharacter, Rotator OriginalRotation){
	Dec_Rotationinit::PerformConditionCheck();
	Task_Move::ReceiveTick();
}

void BT_Base::AttackAndReload(Object targetToAttack, Integer bullet){
	Task_Attack::ReceiveTick();
}

void BT_Base::MoveDestination(Bool Command, Vector Destination, Vector myLocation, Bool distanceCheck){
	Task_Move::ReceiveTick();
}