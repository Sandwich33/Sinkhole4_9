#include "stdafx.h"
#include "PickupAmmo_Actor.h"
#include "Person_Character.h"

EventGraph PickupAmmo_Actor::OnComponentBeginOverlap(Actor OtherActor){
	Person_Character::addAmmunition();
}