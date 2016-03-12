#pragma once
#include "Weapons_Actor.h"

/**
@brief �Ʊ� ĳ������ �⺻�� Ŭ����.
@details 
@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
@details 
*/
class Person_Character
{
public:
	/**
	@brief ����Ʈ���� ��ũ��Ʈ.
	@details ������� ��Ÿ���� 'Person' �±׸� �����Ѵ�.;
	@details ĳ������ ü��, ���̷��� �Ž�, ���ǵ� ���� Define ������ �����Ѵ�.
	@details ĳ���Ϳ� ���⸦ ���� ���� ��Ų��.
	*/
	Construction Script();

	/**
	@brief ������ ó�� �̺�Ʈ.
	@details ��� ������ �������� �������� �Դ´ٸ� ������ �̺�Ʈ��.
	@details ��ų ���� ���θ� üũ�� �� Demage�� Hp�� �����Ѵ�.
	@details ������ ó�� �� ���� ��� ������ �ִϸ��̼��� �����Ѵ�.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventanydamage'
	*/
	EventGraph AnyDamage(float Damage,Object DamageType, Actor InstigatedBy, Actor DamageCauser);

	/**
	@brief Tick �̺�Ʈ.
	@details �� �����Ӹ��� ����Ǵ� �̺�Ʈ.
	@details ���� ��� �ִ� ������ üũ�Ѵ�.
	@details ������ Hp Bar�� ǥ���Ѵ�.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventtick'
	*/
	EventGraph Tick(float DeltaSeconds);

	/**
	@brief ���� �̺�Ʈ.
	@details �������Ʈ�� ���� �� �� ����Ǵ� �̺�Ʈ.
	@details ����(��)�� ������ �ʱ�ȭ �Ѵ�.
	@details ������ Hp Bar�� ǥ�ÿ��θ� �����Ѵ�.
	@details reloadDispatcher_Event�� �����Ѵ�.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventbeginplay'
	*/
	EventGraph BeginPlay();


	/**
	@brief �������� �˸��� �̺�Ʈ.
	@details ������ �ִϸ��̼��� �����⸦ ��ٸ��°��� �� ��������, �Լ� �ȿ����� 'Delay �Լ�( C �� Sleep�Լ��� ���� )'�� ����� �� ���� �̺�Ʈ�� ����� ó���Ѵ�.
	@details ������ �߿��� �ൿ ������ ����, ������ �ִϸ��̼��� ���� �� ó���ؾ��ϴ� ���� �Ѿ��� ���� ���� ó���Ѵ�.
	@param _delay ����ؾ��� �ִϸ��̼��� ����
	@param _total_bullet ���� �� �Ѿ� ��.
	*/
	EventGraph reloadDispatcher_Event(float _delay, int _total_bullet);

	/**
	@brief ��ų ó�� ���� ��ũ��.
	@details ��ų ���θ� ó���Ѵ�.
	@param _can_teamkill true�� ��� ��ų�� �����ϴ�.
	@param _demage_cursor �������� �� ����� �˾ƺ��� ���� ������ �Ǻ��Ѵ�..
	*/
	Macros isTeamKill(bool _can_teamkill, Actor _demage_cursor);

	/**
	@brief ������ ó�� ��ũ��.
	@details ���� ������ ��ŭ Hp�� �Ҹ��ϰ�, �׾������� �Ǵ��Ѵ�.
	@param _demage ���� ������.
	*/
	Macros applyDemage(float _demage);

	/**
	@brief ���� �� �� �ִ� ��Ȳ������ �Ǵ�.
	@details ������ �ִϸ��̼��� ���� �� �̰ų�, �޸��� �߿��� ���� �� �� ����.
	@return ���� �� �� ������ "true"�� �����Ѵ�.
	*/
	Macros canFire();


	/**
	@brief Jump Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@param _on_pressed ����Ű�� �����°��� ���� bool ��.
	*/
	void actionJump(bool _on_pressed);

	/**
	@brief �ɴ� Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ����� ���·� �۵��Ѵ�.
	*/
	void actionCrouch();

	/**
	@brief �޸��� Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@param _on_pressed �޸���Ű�� �����°��� ���� bool ��.
	*/
	void actionSprint(bool _on_pressed);

	/**
	@brief ������ Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ����� ���·� �۵��Ѵ�.
	*/
	void actionIronsights();

	/**
	@brief ���� ������ ������ �ѹ��� ���� �� �ִ� �Լ�.
	@details �ִϸ��̼� ó���� ���� ���� ���� �����ӿ� ���� ������ �Ѳ����� ���� �� �ִ� �Լ��̴�.
	@param _sprint, _crouch, _prone, _jump, _ironsights ĳ������ ���� �ൿ�� �� �� �ִ�.
	@param _gun_type �ѱ� ���� (����ӽŰ�, ����, �������۰�) �� �� �� �ִ�.
	*/
	void getMovementValues(bool *_sprint, bool * _crouch, bool * _prone, bool * _jump, bool * _ironsights, GunType* _gun_type);
	

	/**
	@brief ��� Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ��� ���� ���θ� üũ �� �� ��� �Լ� ȣ��( ingFire() ).
	@param _on_pressed ���Ű�� �����°��� ���� bool ��.
	*/
	void actionFire(bool _on_pressed);

	/**
	@brief ����� Aim�� ���� ó���� ��.
	@details ����� Weapons_Actor �κ��� Aim ������ ���� ���� ��� �Լ��� ȣ�� ( ingFire_Fire() ).
	@param _delta_seconde ���� ��ݿ� ���Ǵ� �����Ӱ� ������ ������ �ð�(��).
	*/
	void ingFire(float _delta_seconde);

	/**
	@brief ����� ���� ��ݿ� ���� ó���� ��.
	@details ����� �ִϸ��̼� �����, ���� �Ѿ��� ��, ���� ��� �ӵ� �� üũ�Ͽ� ��ƼŬ�� �Բ� ��� ��� ���Ϳ� �������� ������.
	@param _start_location �ѱ��� ��ġ.
	@param _end_location �Ѿ��� ���ư� �´� ���� ��ġ.
	@param _delta_seconde ���� ��ݿ� ���Ǵ� �����Ӱ� ������ ������ �ð�(��).
	*/
	void ingFire_Fire(Vector _start_location, Vector _end_location, float _delta_seconde);

	/**
	@brief ������ Action �� ó��.
	@details ����� �⺻���� �������� ǥ���ϴ� Ŭ������, player ĳ���Ϳ� AI ĳ������ �⺻���� �������� ����ϴ� Ŭ�����̴�.
	@details ������ �ִϸ��̼��� ��� �� reloadDispatcher_Event �� �����Ѵ�.
	@param _total_bullet �����ϰ� �ִ� ��ü �Ѿ��� ��.
	*/
	void actionReload(int _total_bullet);

	/**
	@brief ������ �ִϸ��̼� ���� ����.
	@details ������ �ִϸ��̼��� ������ ����� ��Ȳ����, ���� Ŭ����(Person_Character)�� ��ӹ��� �ڽ� Ŭ�������� �������̵��Ͽ� ����Ѵ�.
	*/
	void endReloadAnim();

	/**
	@brief ���� ���� �ʱ�ȭ.
	@details Zoom ���� ��� ��ȯ�Ǵ� ī�޶� ��� �� ���� Ÿ�Կ� ���� ��� �� ������ �ִϸ��̼� ����
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

