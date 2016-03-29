#include "stdafx.h"
#include "GiantMeleeAttack_BTTask.h"
#include "Giant_Enemy.h"

EventGraph ReceiveTick() {
	Giant_Enemy::istryAttack3();
	Giant_Enemy::attack3();
}

EventGraph ReceiveExecute(Actor OwnerActor) {
	
}