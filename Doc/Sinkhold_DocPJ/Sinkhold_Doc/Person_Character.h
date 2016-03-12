#pragma once
#include "Weapons_Actor.h"

/**
@brief 아군 캐릭터의 기본형 클래스.
@details 
@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
@details 
*/
class Person_Character
{
public:
	/**
	@brief 컨스트럭션 스크립트.
	@details 사람임을 나타내는 'Person' 태그를 설정한다.;
	@details 캐리터의 체력, 스켈레톤 매시, 스피드 값을 Define 값으로 설정한다.
	@details 캐릭터와 무기를 소켓 결합 시킨다.
	*/
	Construction Script();

	/**
	@brief 데미지 처리 이벤트.
	@details 어떠한 종류의 데미지라도 데미지를 입는다면 들어오는 이벤트다.
	@details 팀킬 가능 여부를 체크한 뒤 Demage를 Hp에 적용한다.
	@details 데미지 처리 후 죽을 경우 적절한 애니메이션을 실행한다.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventanydamage'
	*/
	EventGraph AnyDamage(float Damage,Object DamageType, Actor InstigatedBy, Actor DamageCauser);

	/**
	@brief Tick 이벤트.
	@details 매 프레임마다 실행되는 이벤트.
	@details 총을 쏘고 있는 중인지 체크한다.
	@details 디버깅용 Hp Bar를 표시한다.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventtick'
	*/
	EventGraph Tick(float DeltaSeconds);

	/**
	@brief 시작 이벤트.
	@details 블루프린트가 시작 될 때 실행되는 이벤트.
	@details 무기(총)의 정보를 초기화 한다.
	@details 디버깅용 Hp Bar를 표시여부를 설정한다.
	@details reloadDispatcher_Event를 생성한다.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventbeginplay'
	*/
	EventGraph BeginPlay();


	/**
	@brief 재장전을 알리는 이벤트.
	@details 재장전 애니메이션이 끝나기를 기다리는것이 주 목적으로, 함수 안에서는 'Delay 함수( C 의 Sleep함수와 유사 )'를 사용할 수 없어 이벤트로 만들어 처리한다.
	@details 재장전 중에는 행동 제약이 많고, 재장전 애니메이션이 끝난 후 처리해야하는 남은 총알의 숫자 등을 처리한다.
	@param _delay 재생해야할 애니메이션의 길이
	@param _total_bullet 남은 총 총알 수.
	*/
	EventGraph reloadDispatcher_Event(float _delay, int _total_bullet);

	/**
	@brief 팀킬 처리 여부 매크로.
	@details 팀킬 여부를 처리한다.
	@param _can_teamkill true의 경우 팀킬이 가능하다.
	@param _demage_cursor 데미지를 준 대상을 알아보고 같은 팀인지 판별한다..
	*/
	Macros isTeamKill(bool _can_teamkill, Actor _demage_cursor);

	/**
	@brief 데미지 처리 매크로.
	@details 받은 데미지 만큼 Hp를 소모하고, 죽었는지를 판단한다.
	@param _demage 받은 데미지.
	*/
	Macros applyDemage(float _demage);

	/**
	@brief 총을 쏠 수 있는 상황인지를 판단.
	@details 재장전 애니메이션을 실행 중 이거나, 달리는 중에는 총을 쏠 수 없다.
	@return 총을 쏠 수 있으면 "true"를 리턴한다.
	*/
	Macros canFire();


	/**
	@brief Jump Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@param _on_pressed 점프키를 눌렀는가에 대한 bool 값.
	*/
	void actionJump(bool _on_pressed);

	/**
	@brief 앉는 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 토글의 형태로 작동한다.
	*/
	void actionCrouch();

	/**
	@brief 달리는 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@param _on_pressed 달리기키를 눌렀는가에 대한 bool 값.
	*/
	void actionSprint(bool _on_pressed);

	/**
	@brief 정조준 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 토글의 형태로 작동한다.
	*/
	void actionIronsights();

	/**
	@brief 현재 움직임 정보를 한번에 얻을 수 있는 함수.
	@details 애니메이션 처리를 돕기 위해 현재 움직임에 대한 정보를 한꺼번에 얻을 수 있는 함수이다.
	@param _sprint, _crouch, _prone, _jump, _ironsights 캐릭터의 현재 행동을 알 수 있다.
	@param _gun_type 총기 종류 (서브머신건, 샷건, 스나이퍼건) 를 알 수 있다.
	*/
	void getMovementValues(bool *_sprint, bool * _crouch, bool * _prone, bool * _jump, bool * _ironsights, GunType* _gun_type);
	

	/**
	@brief 사격 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 사격 가능 여부를 체크 한 후 사격 함수 호출( ingFire() ).
	@param _on_pressed 사격키를 눌렀는가에 대한 bool 값.
	*/
	void actionFire(bool _on_pressed);

	/**
	@brief 사격중 Aim에 관한 처리를 함.
	@details 사격중 Weapons_Actor 로부터 Aim 정보를 얻어내어 실제 사격 함수를 호출 ( ingFire_Fire() ).
	@param _delta_seconde 연속 사격에 사용되는 프레임과 프레임 사이의 시간(초).
	*/
	void ingFire(float _delta_seconde);

	/**
	@brief 사격중 실제 사격에 관한 처리를 함.
	@details 사격중 애니메이션 재생과, 남은 총알의 수, 연속 사격 속도 를 체크하여 파티클과 함께 사격 대상 엑터에 데미지를 입힌다.
	@param _start_location 총구의 위치.
	@param _end_location 총알이 날아가 맞는 곳의 위치.
	@param _delta_seconde 연속 사격에 사용되는 프레임과 프레임 사이의 시간(초).
	*/
	void ingFire_Fire(Vector _start_location, Vector _end_location, float _delta_seconde);

	/**
	@brief 재장전 Action 을 처리.
	@details 사람의 기본적인 움직임을 표현하는 클래스로, player 캐릭터와 AI 캐릭터의 기본적인 움직임을 담당하는 클래스이다.
	@details 재장전 애니메이션을 재생 후 reloadDispatcher_Event 를 실행한다.
	@param _total_bullet 소유하고 있는 전체 총알의 수.
	*/
	void actionReload(int _total_bullet);

	/**
	@brief 재장전 애니메이션 완전 종료.
	@details 재장전 애니메이션이 완전히 종료된 상황으로, 현재 클래스(Person_Character)를 상속받은 자식 클래스에서 오버라이드하여 사용한다.
	*/
	void endReloadAnim();

	/**
	@brief 무기 설정 초기화.
	@details Zoom 했을 경우 전환되는 카메라 등록 및 무기 타입에 따른 사격 및 재장전 애니메이션 설정
	*/
	void initWeapon();


	float MAX_STAND_SPEED;
	float MAX_SPRINT_SPEED;
	float MAX_CROUCH_SPEED;
	float MAX_STAND_IRONSIGHTS_SPEED;

	float hp;
	int bulletCount;
	bool runing_fire;
	Weapons_Actor Gun;
	float MAX_HP;
	HpBarWidget hp_bar;
	bool show_hp_bar;

	AnimMontage Anim_Death;
	AnimMontage Anim_Fire;
	AnimMontage Anim_Reload;

	Vector2D screen_point;

private:
	bool sprint_pressed;
	bool crouch_pressed;
	bool prone_pressed;
	bool jump_pressed;
	bool toggle_ironsights;
	bool toggle_crouch;
	bool toggleProne;
	bool disable_Movement;
	bool Ironsights_pressed;
	bool is_play_reload;
};

