#include "stdafx.h"
#include "GiantBehaviorTree_BehaviorTree.h"
#include "ScanPersonCharacters_BTService.h"
#include "SetRandomDestination_BTService.h"
#include "CloseEnoughForMeleeAttack_BTDecorator.h"
#include "GiantCloseEnoughForRangedAttack_BTDecorator.h"
#include "GiantMeleeAttack_BTTask.h"
#include "GiantRangedAttack_BTTask.h"
#include "GiantApproach_BTTask.h"

void GiantBehaviorTree_BehaviorTree::root(EnemyBlackboard_Blackboard blackboard) {
	selector();
}

void GiantBehaviorTree_BehaviorTree::selector(Object targetToAttack, Vector destination) {
	ScanPersonCharacters_BTService::ReceiveActivation();
	ScanPersonCharacters_BTService::ReceiveTick();
	SetRandomDestination_BTService::ReceiveTick();
	idle();
	foundPerson();
}

void GiantBehaviorTree_BehaviorTree::idle(Object targetToAttack) {
	wander();
}

void GiantBehaviorTree_BehaviorTree::foundPerson(Object targetToAttack) {
	adjacent();
	near();
	notClose();
}

void GiantBehaviorTree_BehaviorTree::wander(Vector destination) {
	moveTo();
}

void GiantBehaviorTree_BehaviorTree::adjacent(Object targetToAttack) {
	CloseEnoughForMeleeAttack_BTDecorator::PerformConditionCheck();
	giantMeleeAttack();
}

void GiantBehaviorTree_BehaviorTree::near(Object targetToAttack) {
	GiantCloseEnoughForRangedAttack_BTDecorator::PerformConditionCheck();
	giantRangedAttack();
}

void GiantBehaviorTree_BehaviorTree::notClose(Object targetToAttack) {
	CloseEnoughForMeleeAttack_BTDecorator::PerformConditionCheck();
	giantApproach();
}

void GiantBehaviorTree_BehaviorTree::moveTo(Vector destination) {
	GiantCloseEnoughForRangedAttack_BTDecorator::PerformConditionCheck();
	giantRangedAttack();
}

void GiantBehaviorTree_BehaviorTree::giantMeleeAttack(Object targetToAttack) {
	GiantMeleeAttack_BTTask::ReceiveExecute();
	GiantMeleeAttack_BTTask::ReceiveTick();
}

void GiantBehaviorTree_BehaviorTree::giantRangedAttack(Object targetToAttack) {
	GiantRangedAttack_BTTask::ReceiveExecute();
	GiantRangedAttack_BTTask::ReceiveTick();
}

void GiantBehaviorTree_BehaviorTree::giantApproach(Object targetToAttack) {
	GiantApproach_BTTask::ReceiveExecute();
	GiantApproach_BTTask::ReceiveAbort();
}