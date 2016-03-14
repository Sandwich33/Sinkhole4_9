#include "stdafx.h"
#include "AI_Person.h"


EventGraph AI_Person::Tick(float DeltaSeconds){
	Gun.onFire();
	Gun.waitingFire();
}
void AI_Person::actionAI_OnFile(float _delta_seconds, Vector _end_location, Object _get_object){
	Gun.actionFire();
	ingFire_Fire();
}
void AI_Person::actionAI_Reload(){
	actionReload();
}