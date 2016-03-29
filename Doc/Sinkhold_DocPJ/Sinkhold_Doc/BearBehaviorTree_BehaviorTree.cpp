#include "stdafx.h"
#include "BearBehaviorTree_BehaviorTree.h"
#include "ScanPersonCharacters_BTService.h"
#include "SetRandomDestination_BTService.h"
#include "CloseEnoughForMeleeAttack_BTDecorator.h"
#include "EnemyAttack_BTTask.h"
#include "Approach_BTTask.h"

void BearBehaviorTree_BehaviorTree::root(EnemyBlackboard_Blackboard blackboard) {
	selector();
}

void BearBehaviorTree_BehaviorTree::selector(Object targetToAttack, Vector destination) {
	ScanPersonCharacters_BTService::ReceiveActivation();
	ScanPersonCharacters_BTService::ReceiveTick();
	SetRandomDestination_BTService::ReceiveTick();
	idle();
	foundPerson();
}

void BearBehaviorTree_BehaviorTree::idle(Object targetToAttack) {
	wander();
}

void BearBehaviorTree_BehaviorTree::foundPerson(Object targetToAttack) {
	closeEnough();
	notClose();
}

void BearBehaviorTree_BehaviorTree::wander(Vector destination) {
	moveTo();
}

void BearBehaviorTree_BehaviorTree::closeEnough(Object targetToAttack) {
	CloseEnoughForMeleeAttack_BTDecorator::PerformConditionCheck();
	attack();
}

void BearBehaviorTree_BehaviorTree::notClose(Object targetToAttack) {
	CloseEnoughForMeleeAttack_BTDecorator::PerformConditionCheck();
	approach();
}

void BearBehaviorTree_BehaviorTree::moveTo(Vector destination) {

}

void BearBehaviorTree_BehaviorTree::attack(Object targetToAttack) {
	EnemyAttack_BTTask::ReceiveExecute();
	EnemyAttack_BTTask::ReceiveTick();
}

void BearBehaviorTree_BehaviorTree::approach(Object targetToAttack) {
	Approach_BTTask::ReceiveExecute();
}