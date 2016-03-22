#include "stdafx.h"
#include "Enemy_Character.h"


EventGraph Enemy_Character::AnyDamage(float Damage, Object DamageType, Actor InstigatedBy, Actor DamageCauser){
	isTeamKill();
	onDie();
	alarmGettingAttacked();
}