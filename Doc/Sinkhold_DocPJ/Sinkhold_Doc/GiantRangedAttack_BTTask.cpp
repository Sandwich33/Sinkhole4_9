#include "stdafx.h"
#include "GiantRangedAttack_BTTask.h"
#include "Giant_Enemy.h"

EventGraph ReceiveTick() {
	Giant_Enemy::attack2();
}

EventGraph ReceiveExecute(Actor OwnerActor) {

}