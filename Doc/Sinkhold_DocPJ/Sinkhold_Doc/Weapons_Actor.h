#pragma once
/**
@brief 무기(총)의 기본형 클래스.
@details
*/
class Weapons_Actor
{
public:
	/**
	@brief 컨스트럭션 스크립트.
	@details ZoomCamera 의 위치를 잡아준다.
	*/
	Construction Script();

	bool actionFire(bool _pressed);
	void doFire(Actor _demage_causer, HitResult _hit_info);
	void getAim(Vector _start_location, Vector _end_location, Vector2D _screen_point);
	bool delayFire(float _delta_seconds);
	bool onFire();
	void createParticle();
	void playFireSound();
	void getDemageActor(bool _in_aim_data, Vector _start_location, Vector _end_location, HitResult[] * _out_hit, bool *_return_value);
	int actionReload(int _total_bullet);
	void onReloadAnimation();
	void waitingFire(int _delta_seconds);
	void getRecoilLine(bool _in_aim_data, Vector _start_location, Vector _end_location, Vector *_out_start_location, Vector *_out_end_location, _EObjectType *_object_type);
	Vector getLookVector();
	void playReloadSound();
	void playZoominSound();
	float getAimInfo();


	float FIRE_SPEED;
	float RECOIL_RANGE_MAX;

	int in_bullet;
	int MAX_BULLET;
	float DEMAGE;
	GunTypeEnum gun_type;
	Controller player_controller;

private:
	bool can_fire;
	float delta_time;
	float recoil_range;
	float recoil;
	float RECOIL_DEFAULT;
	float RANGE;

};

