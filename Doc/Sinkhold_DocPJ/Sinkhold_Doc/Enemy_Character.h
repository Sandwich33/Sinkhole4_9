#pragma once

/**
@brief  적 기본 클래스.
@details
@details 모든 적들은 해당 클래스를 부모 클래스로 가진다.
@details
*/

class Enemy_Character
{
public:
	
	/**
	@brief 컨스트럭션 스크립트.
	@details HP 초기화
	@details 태그("Enemy") 추가
	*/
	Construction Script();

	//EventGraph BeginPlay();

	/**
	@brief 데미지 처리 이벤트.
	@details 어떠한 종류의 데미지라도 데미지를 입는다면 들어오는 이벤트다.
	@details 팀킬 가능 여부를 체크한 뒤 Demage를 Hp에 적용한다.
	@details 데미지 처리 후 죽을 경우 적절한 애니메이션을 실행한다.
	@details 주변 동료들에게 공격받은 사실을 알림.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventanydamage'
	*/
	EventGraph AnyDamage(float Damage, Object DamageType, Actor InstigatedBy, Actor DamageCauser);

	/**
	@brief .....
	@details /////
	**/
	void onDie();

	/**
	@brief .....
	@details /////
	@param _can_attack 공격 가능/불가능 상태 세팅.
	**/
	void setCanAttack(bool _can_attack);

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void hitAttack(HitResult _hit, Actor _other_actor);

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void onAttack();

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void alarmGettingAttacked(Actor _demageCauser);

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void receiveAttackAlarm(Actor _demageCauser);

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void playAttackSound();


	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void playDieSound();

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void playAttackSound2();

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	void playAttackSound3();

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	Macros isTeamKill(bool _can_teamkill, Actor _demage_curser);

	/**
	@brief .....
	@details /////
	@param _hit ////
	@param _other_actor ///
	**/
	Macros applyDemage(bool _demage);

	float hp;
	float DEMAGE;
	float MAX_HP;
	bool can_attack;
};

