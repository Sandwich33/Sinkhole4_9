#pragma once
/**
@brief ����(��)�� �⺻�� Ŭ����.
@details
*/
class Weapons_Actor
{
public:
	/**
	@brief ����Ʈ���� ��ũ��Ʈ.
	@details ZoomCamera �� ��ġ�� ����ش�.
	*/
	Construction Script();

	/**
	@brief Weapons ���� ��Ƽ踦 ������� �˷��ش�.
	@details ����ڰ� �߻� ��ư�� �������� Weapons �� can_fire ������ �˷��ش�.
	@param _pressed Ű�� ����
	@return _pressed �� ���� �״�� �������ش�.
	*/
	bool actionFire(bool _pressed);

	/**
	@brief �Ѿ˿� ���� ���Ϳ��� �������� ������.
	@details �Ѿ˿� ���� ���Ϳ��� ������ �̺�Ʈ�� ������.
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
	@brief ��ƼŬ�� �����Ѵ�.
	@details ��ӹ��� �ڽ� Ŭ�������� ����ϸ� �� �ѿ� �˸´� ��ƼŬ�� �����Ѵ�.
	*/
	void createParticle();

	/**
	@brief �ѼҸ��� ����Ѵ�.
	@details ��ӹ��� �ڽ� Ŭ�������� ����ϸ� �� �ѿ� �˸´� �ѼҸ��� ����Ѵ�.
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

