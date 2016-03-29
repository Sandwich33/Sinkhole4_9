#include "stdafx.h"
#include "GiantApproach_BTTask.h"
#include "Giant_Enemy.h"

EventGraph ReceiveExecute(Actor OwnerActor) {
	Giant_Enemy::runAttackReady();
	Giant_Enemy::runAttack();
}

EventGraph ReceiveAbort() {
	Giant_Enemy::runAttackEnd();
}