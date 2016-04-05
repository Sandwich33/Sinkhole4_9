#include "stdafx.h"
#include "Task_Move.h"
#include "Person_Character.h"

EventGraph ReceiveTick(Actor OwnerActor){
	Person_Character::actionIronsights();
	Person_Character::actionSprint();
}
