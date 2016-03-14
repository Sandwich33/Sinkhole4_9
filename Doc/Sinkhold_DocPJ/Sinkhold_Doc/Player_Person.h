#pragma once
#include "Person_Character.h"

/**
@brief  �÷��̾� Ŭ����.
@details
@details ....
@details
*/
class Player_Person :
	public Person_Character
{
public:
	/**
	@brief ����Ʈ���� ��ũ��Ʈ.
	@details �÷��̾��� ��� Character���� �����ϴ� Mesh �� ����� �� ���� ���ο� Mesh�� ���� �� �� �Žø� ĳ���ͷ� ����Ѵ�.
	@details ĳ���Ϳ� ���⸦ ���� ���� ��Ų��.
	*/
	Construction Script();

	/**
	@brief ��/�� �̵� �̺�Ʈ.
	@details Ű �������� �� �� ��ư���� ����� Ű �Է��� ������ �����Ѵ�.
	@param AxisValue ���� ������ ���� ��Ÿ����.
	*/
	EventGraph InputAction_MoveForward(float AxisValue);

	/**
	@brief ��/�� �̵� �̺�Ʈ.
	@details Ű �������� �� �� ��ư���� ����� Ű �Է��� ������ �����Ѵ�.
	@param AxisValue ���� ������ ���� ��Ÿ����.
	*/
	EventGraph InputAction_MoveRight(float AxisValue);

	/**
	@brief ��/�� ������ȯ �̺�Ʈ.
	@details ���콺�� ����Ͽ� �¿� ȭ�� ��ȯ�� �Ѵ�.
	@param AxisValue ���콺�� ������ ������ ��Ÿ����.
	*/
	EventGraph InputAction_Turn(float AxisValue);

	/**
	@brief ��/�� ������ȯ �̺�Ʈ.
	@details ���콺�� ����Ͽ� ���� ȭ�� ��ȯ�� �Ѵ�.
	@param AxisValue ���콺�� ������ ������ ��Ÿ����.
	*/
	EventGraph InputAction_LookUp(float AxisValue);

	/**
	@brief Tick �̺�Ʈ.
	@details �� �����Ӹ��� ����Ǵ� �̺�Ʈ.
	@details �θ� Tick �� ���� �Ѵ�.
	@details ���� �� �ɱ� �� ���¸� üũ�� �� ������ ī�޶� �������� �����ش�.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventtick'
	*/
	EventGraph Tick(float DeltaSeconds);

	/**
	@brief ������ �ִϸ��̼� ���� ����.
	@details 
	*/
	void endReloadAnim();

	/**
	@brief �ɱ� �̺�Ʈ.
	@details ����� �̿��Ͽ� �ɾҴ� �Ͼ�� �Ѵ�.
	*/
	EventGraph InputAction_Crouch_Pressed();

	/**
	@brief Jump �̺�Ʈ.
	@details Ű �̺�Ʈ�� ������ ���´�.
	@details Pressed �� �����ٴ� �ǹ�.
	*/
	EventGraph InputAction_Jump_Pressed();
	/**
	@brief Jump �̺�Ʈ.
	@details Ű �̺�Ʈ�� ������ ���´�.
	@details Releasd �� ������ ���� �ǹ�.
	*/
	EventGraph InputAction_Jump_Releasd();
	/**
	@brief �޸��� �̺�Ʈ.
	@details Ű �̺�Ʈ�� ������ ���´�.
	@details Pressed �� �����ٴ� �ǹ�.
	*/
	EventGraph InputAction_Sprint_Pressed();
	/**
	@brief �޸��� �̺�Ʈ.
	@details Ű �̺�Ʈ�� ������ ���´�.
	@details Releasd �� ������ ���� �ǹ�.
	*/
	EventGraph InputAction_Sprint_Releasd();

	/**
	@brief ������ �̺�Ʈ.
	@details ����� �̿�.
	*/
	EventGraph InputAction_Ironsights_Pressed();


	/**
	@brief ��ݰ��� �̺�Ʈ.
	@details Ű �̺�Ʈ�� ������ ���´�.
	@details Pressed �� �����ٴ� �ǹ�.
	*/
	EventGraph InputAction_Fire_Pressed();
	/**
	@brief ������� �̺�Ʈ.
	@details Ű �̺�Ʈ�� ������ ���´�.
	@details Releasd �� ������ ���� �ǹ�.
	*/
	EventGraph InputAction_Fire_Releasd();

	/**
	@brief ������ �̺�Ʈ.
	@details Ű �̺�Ʈ�� ������ ���´�.
	@details Pressed �� �����ٴ� �ǹ�.
	*/
	EventGraph InputAction_Reload_Pressed();

	/**
	@brief �º� ������ �̺�Ʈ.
	*/
	EventGraph InputAction_Tablet_Pressed();

	/**
	@brief �Ͻ����� �̺�Ʈ.
	*/
	EventGraph InputAction_Pause_Pressed();

	/**
	@brief ī�޶� ��ġ ����.
	@details �������� ���� �Ϲ����� ��� ī�޶� ��ġ�� �ٸ���. ���� ���� �����ϰ� ī�޶� ��ġ�� ����ش�.
	@param _me true �� ��� ������ �Ϲ� ī�޶� ��ġ�� ǥ���Ѵ�.
	*/
	void setViewTarget(bool _me);

	/**
	@brief ���� ������ �ش�.
	@details ������ �׸��µ� �־� �ʿ��� �������� �Ѱ��ش�..
	@return _recoil �ݵ��� ����
	@return _screen_point ������ ǥ���� ȭ����� ��ġ
	@return _show_aim ���� ǥ�� ����
	*/
	void getAimInfo(float *_recoil, Vector2D *_screen_point, bool *_show_aim);

	/**
	@brief ȭ�鿡 ǥ���� �Ѿ��� ������ �ش�.
	@details 
	@return _bullet �����Ǿ� �ִ� �Ѿ��� ��
	@return _have_bullet �����ϰ� �ִ� �Ѿ��� ��
	*/
	void getBulletInfo(int *_bullet, int *_have_bullet);

	bool fire_input_tag;
	bool jumping;
};

