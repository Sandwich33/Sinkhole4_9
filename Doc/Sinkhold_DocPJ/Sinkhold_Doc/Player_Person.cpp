#include "stdafx.h"
#include "Player_Person.h"


EventGraph Player_Person::Tick(float DeltaSeconds){
	Person_Character::Tick();

	setViewTarget();
}


void Player_Person::endReloadAnim(){
	setViewTarget();
}
EventGraph Player_Person::InputAction_Crouch_Pressed(){
	Person_Character::actionCrouch();
}


EventGraph Player_Person::InputAction_Jump_Pressed(){
	setViewTarget();
	Person_Character::actionJump();

}
EventGraph Player_Person::InputAction_Jump_Releasd(){
	Person_Character::actionJump();
}

EventGraph Player_Person::InputAction_Sprint_Pressed(){
	setViewTarget();
	Person_Character::actionSprint();

}
EventGraph Player_Person::InputAction_Sprint_Releasd(){
	setViewTarget();
	Person_Character::actionSprint();

}

EventGraph Player_Person::InputAction_Fire_Pressed(){
	Person_Character::actionFire();
}

EventGraph Player_Person::InputAction_Fire_Releasd(){
	Person_Character::actionFire();
}

EventGraph Player_Person::InputAction_Ironsights_Pressed(){
	Person_Character::actionIronsights();
	setViewTarget();
	InputAction_Sprint_Releasd();
}

EventGraph Player_Person::InputAction_Reload_Pressed(){
	setViewTarget();
	Person_Character::actionReload();
}

void Player_Person::getAimInfo(float *_recoil, Vector2D *_screen_point, bool *_show_aim){
	Gun.getAimInfo();
}