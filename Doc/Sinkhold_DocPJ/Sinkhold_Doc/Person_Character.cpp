#include "stdafx.h"
#include "Person_Character.h"

void Person_Character::actionIronsights(){
	Gun.playZoominSound();
}


void Person_Character::getMovementValues(bool *_sprint, bool * _crouch, bool * _prone, bool * _jump, bool * _ironsights, GunType* _gun_type){
	_gun_type = Gun.gun_type;
}

void Person_Character::actionFire(bool _on_pressed){
	canFire();
	if (Gun.actionFire()) {
		ingFire(0);
	}
}

void Person_Character::ingFire(float _delta_seconde){
	Gun.getAim();
	ingFire_Fire();
}

void Person_Character::actionReload(int _total_bullet){
	Gun.onReloadAnimation();
	Gun.playReloadSound();
	reloadDispatcher_Event();
}

void Person_Character::ingFire_Fire(Vector _start_location, Vector _end_location, float _delta_seconde){
	if (Gun.onFire()){
		if (Gun.delayFire()) {
			Gun.createParticle();
			Gun.playFireSound();
			Gun.getDemageActor();
			while (0){
				Gun.doFire();
			}
		}
	}
	else{
		Gun.waitingFire();
	}
}


EventGraph Person_Character::BeginPlay(){
	initWeapon();
}

EventGraph Person_Character::reloadDispatcher_Event(float _delay, int _total_bullet){
	Gun.actionReload();
	endReloadAnim();
}

EventGraph Person_Character::Tick(float DeltaSeconds){
	ingFire();
}