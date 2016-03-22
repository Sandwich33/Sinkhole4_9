#pragma once

/**
@brief  �� �⺻ Ŭ����.
@details
@details ��� ������ �ش� Ŭ������ �θ� Ŭ������ ������.
@details
*/

class Enemy_Character
{
public:
	
	/**
	@brief ����Ʈ���� ��ũ��Ʈ.
	@details HP �ʱ�ȭ
	@details �±�("Enemy") �߰�
	*/
	Construction Script();

	//EventGraph BeginPlay();

	/**
	@brief ������ ó�� �̺�Ʈ.
	@details ��� ������ �������� �������� �Դ´ٸ� ������ �̺�Ʈ��.
	@details ��ų ���� ���θ� üũ�� �� Demage�� Hp�� �����Ѵ�.
	@details ������ ó�� �� ���� ��� ������ �ִϸ��̼��� �����Ѵ�.
	@details �ֺ� ����鿡�� ���ݹ��� ����� �˸�.
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
	@param _can_attack ���� ����/�Ұ��� ���� ����.
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

