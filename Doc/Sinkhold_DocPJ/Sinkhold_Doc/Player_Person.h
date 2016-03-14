#pragma once
#include "Person_Character.h"

/**
@brief  플레이어 클래스.
@details
@details ....
@details
*/
class Player_Person :
	public Person_Character
{
public:
	/**
	@brief 컨스트럭션 스크립트.
	@details 플레이어의 경우 Character에서 제공하는 Mesh 를 사용할 수 없어 새로운 Mesh를 만든 후 그 매시를 캐릭터로 등록한다.
	@details 캐릭터와 무기를 소켓 결합 시킨다.
	*/
	Construction Script();

	/**
	@brief 앞/뒤 이동 이벤트.
	@details 키 설정에서 앞 뒤 버튼으로 등록한 키 입력을 받으면 동작한다.
	@param AxisValue 누른 정도의 값을 나타낸다.
	*/
	EventGraph InputAction_MoveForward(float AxisValue);

	/**
	@brief 좌/우 이동 이벤트.
	@details 키 설정에서 좌 우 버튼으로 등록한 키 입력을 받으면 동작한다.
	@param AxisValue 누른 정도의 값을 나타낸다.
	*/
	EventGraph InputAction_MoveRight(float AxisValue);

	/**
	@brief 좌/우 방향전환 이벤트.
	@details 마우스를 사용하여 좌우 화면 전환을 한다.
	@param AxisValue 마우스를 움직인 정도를 나타낸다.
	*/
	EventGraph InputAction_Turn(float AxisValue);

	/**
	@brief 상/하 방향전환 이벤트.
	@details 마우스를 사용하여 상하 화면 전환을 한다.
	@param AxisValue 마우스를 움직인 정도를 나타낸다.
	*/
	EventGraph InputAction_LookUp(float AxisValue);

	/**
	@brief Tick 이벤트.
	@details 매 프레임마다 실행되는 이벤트.
	@details 부모 Tick 을 실행 한다.
	@details 점프 및 앉기 의 상태를 체크한 후 적절한 카메라 움직임을 보여준다.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventtick'
	*/
	EventGraph Tick(float DeltaSeconds);

	/**
	@brief 재장전 애니메이션 완전 종료.
	@details 
	*/
	void endReloadAnim();

	/**
	@brief 앉기 이벤트.
	@details 토글을 이용하여 앉았다 일어섰다 한다.
	*/
	EventGraph InputAction_Crouch_Pressed();

	/**
	@brief Jump 이벤트.
	@details 키 이벤트로 점프가 들어온다.
	@details Pressed 는 눌렀다는 의미.
	*/
	EventGraph InputAction_Jump_Pressed();
	/**
	@brief Jump 이벤트.
	@details 키 이벤트로 점프가 들어온다.
	@details Releasd 는 눌렀다 뗌을 의미.
	*/
	EventGraph InputAction_Jump_Releasd();
	/**
	@brief 달리기 이벤트.
	@details 키 이벤트로 점프가 들어온다.
	@details Pressed 는 눌렀다는 의미.
	*/
	EventGraph InputAction_Sprint_Pressed();
	/**
	@brief 달리기 이벤트.
	@details 키 이벤트로 점프가 들어온다.
	@details Releasd 는 눌렀다 뗌을 의미.
	*/
	EventGraph InputAction_Sprint_Releasd();

	/**
	@brief 정조준 이벤트.
	@details 토글을 이용.
	*/
	EventGraph InputAction_Ironsights_Pressed();


	/**
	@brief 사격개시 이벤트.
	@details 키 이벤트로 점프가 들어온다.
	@details Pressed 는 눌렀다는 의미.
	*/
	EventGraph InputAction_Fire_Pressed();
	/**
	@brief 사격종료 이벤트.
	@details 키 이벤트로 점프가 들어온다.
	@details Releasd 는 눌렀다 뗌을 의미.
	*/
	EventGraph InputAction_Fire_Releasd();

	/**
	@brief 재장전 이벤트.
	@details 키 이벤트로 점프가 들어온다.
	@details Pressed 는 눌렀다는 의미.
	*/
	EventGraph InputAction_Reload_Pressed();

	/**
	@brief 태블릿 꺼내기 이벤트.
	*/
	EventGraph InputAction_Tablet_Pressed();

	/**
	@brief 일시정지 이벤트.
	*/
	EventGraph InputAction_Pause_Pressed();

	/**
	@brief 카메라 위치 선정.
	@details 정조준의 경우와 일반적인 경우 카메라 위치가 다르다. 때에 따라서 적절하게 카메라 위치를 잡아준다.
	@param _me true 일 경우 무조건 일반 카메라 위치로 표시한다.
	*/
	void setViewTarget(bool _me);

	/**
	@brief 에임 정보를 준다.
	@details 에임을 그리는데 있어 필요한 정보들을 넘겨준다..
	@return _recoil 반동의 정도
	@return _screen_point 에임을 표시할 화면상의 위치
	@return _show_aim 에임 표시 여부
	*/
	void getAimInfo(float *_recoil, Vector2D *_screen_point, bool *_show_aim);

	/**
	@brief 화면에 표시할 총알의 정보를 준다.
	@details 
	@return _bullet 장전되어 있는 총알의 수
	@return _have_bullet 소유하고 있는 총알의 수
	*/
	void getBulletInfo(int *_bullet, int *_have_bullet);

	bool fire_input_tag;
	bool jumping;
};

