#include "stdafx.h"
#include "BearBehaviorTree_BehaviorTree.h"
#include "ScanPersonCharacters_BTService.h"
#include "EnemyAttack_BTTask.h"
#include "Approach_BTTask.h"
#include "CloseEnoughForMeleeAttack_BTDecorator.h"


void BearBehaviorTree_BehaviorTree::Root(){
	Selector();
}

void BearBehaviorTree_BehaviorTree::Selector()
{
	ScanPersonCharacters_BTService::ReceiveActivation();
	ScanPersonCharacters_BTService::ReceiveTick();

	idle();
	foundperson();
}

void BearBehaviorTree_BehaviorTree::idle(BlackboardKey targetToAttack){
	wander();
}
void BearBehaviorTree_BehaviorTree::foundperson(){
	closeenough();
	notclose();
}
void BearBehaviorTree_BehaviorTree::wander(){
	moveto();
}
void BearBehaviorTree_BehaviorTree::closeenough(){
	CloseEnoughForMeleeAttack_BTDecorator::PerformConditionCheck();
	attack();
}
void BearBehaviorTree_BehaviorTree::notclose(){
	CloseEnoughForMeleeAttack_BTDecorator::PerformConditionCheck();
	approach();
}
void BearBehaviorTree_BehaviorTree::moveto(){

}
void BearBehaviorTree_BehaviorTree::attack(){
	EnemyAttack_BTTask::ReceiveExecute();
	EnemyAttack_BTTask::ReceiveTick();
}
void BearBehaviorTree_BehaviorTree::approach(){
	Approach_BTTask::ReceiveExecute();
}