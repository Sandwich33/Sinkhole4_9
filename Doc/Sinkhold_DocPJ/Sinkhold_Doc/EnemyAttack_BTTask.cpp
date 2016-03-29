#include "stdafx.h"
#include "EnemyAttack_BTTask.h"
#include "Enemy_Character.h"

EventGraph ReceiveTick() {
	Enemy_Character::onAttack();
}

EventGraph ReceiveExecute(Actor OwnerActor) {

}