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

	/**
	@brief Weapons 에게 방아쇠를 당겼음을 알려준다.
	@details 사용자가 발사 버튼을 눌렀음을 Weapons 의 can_fire 변수에 알려준다.
	@param _pressed 키의 상태
	@return _pressed 의 값을 그대로 리턴해준다.
	*/
	bool actionFire(bool _pressed);

	/**
	@brief 총알에 맞은 엑터에게 데미지를 입힌다.
	@details 총알에 맞은 엑터에게 데미지 이벤트를 날린다.
	@param _demage_durser ////////
	@param _hit_info ////////
	*/
	void doFire(Actor _demage_causer, HitResult _hit_info);

	/**
	@brief ////////
	@details ////////
	@param _start_location ////////
	@param _end_location ////////
	@param _screen_point ////////
	*/
	void getAim(Vector _start_location, Vector _end_location, Vector2D _screen_point);

	/**
	@brief ////////
	@details ////////
	@param _delta_seconds ////////
	@return -- ////////
	*/
	bool delayFire(float _delta_seconds);

	/**
	@brief ////////
	@details ////////
	@return -- ////////
	*/
	bool onFire();

	/**
	@brief 파티클을 생성한다.
	@details 상속받은 자식 클래스에서 사용하며 각 총에 알맞는 파티클을 생성한다.
	*/
	void createParticle();

	/**
	@brief 총소리를 재생한다.
	@details 상속받은 자식 클래스에서 사용하며 각 총에 알맞는 총소리를 재생한다.
	*/
	void playFireSound();

	/**
	@brief ////////
	@details ////////
	@param _in_aim_data ////////
	@param _start_location ////////
	@param _end_location ////////
	@return _out_hit ////////
	@return _return_value ////////
	*/
	void getDemageActor(bool _in_aim_data, Vector _start_location, Vector _end_location, HitResult[] * _out_hit, bool *_return_value);

	/**
	@brief ////////
	@details ////////
	@param _total_bullet ////////
	@return --- ////////
	*/
	int actionReload(int _total_bullet);

	/**
	@brief ////////
	@details ////////
	*/
	void onReloadAnimation();

	/**
	@brief ////////
	@details ////////
	@param _delta_seconds ////////
	*/
	void waitingFire(int _delta_seconds);

	/**
	@brief ////////
	@details ////////
	@param _in_aim_data ////////
	@param _start_location ////////
	@param _end_location ////////
	@param _out_start_location ////////
	@param _out_end_location ////////
	@param _object_type ////////
	*/
	void getRecoilLine(bool _in_aim_data, Vector _start_location, Vector _end_location, Vector *_out_start_location, Vector *_out_end_location, _EObjectType *_object_type);

	/**
	@brief ////////
	@details ////////
	@return --- ////////
	*/
	Vector getLookVector();

	/**
	@brief ////////
	@details ////////
	*/
	void playReloadSound();

	/**
	@brief ////////
	@details ////////
	*/
	void playZoominSound();

	/**
	@brief ////////
	@details ////////
	*/
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

