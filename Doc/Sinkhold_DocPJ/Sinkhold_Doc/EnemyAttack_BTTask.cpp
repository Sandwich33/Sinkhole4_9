#include "stdafx.h"
#include "EnemyAttack_BTTask.h"
#include "Enemy_Character.h"


EventGraph EnemyAttack_BTTask::ReceiveExecute(){
	Enemy_Character::onAttack();
}