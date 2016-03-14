#pragma once
#include "Person_Character.h"
/**
@brief  AI ���� Ŭ����.
@details
@details ....
@details
*/
class AI_Person :
	public Person_Character
{
public:

	/**
	@brief Tick �̺�Ʈ.
	@details �� �����Ӹ��� ����Ǵ� �̺�Ʈ.
	@details ���� ��� �ִ� ������ üũ�Ѵ�.
	@details ������ Hp Bar�� ǥ���Ѵ�.
	@param 'https://docs.unrealengine.com/latest/KOR/Engine/Blueprints/UserGuide/Events/index.html#eventtick'
	*/
	EventGraph Tick(float DeltaSeconds);

	/**
	@brief ��� ����� ����.
	@details AI ó�� �������Ʈ���� ��� ���(�̺�Ʈ)�� ����.
	@param _delta_seconds �����Ӱ� �ð� ����
	@param _end_location ��� ����Ʈ
	@param _get_object ��ݴ��
	*/
	void actionAI_OnFile(float _delta_seconds, Vector _end_location, Object _get_object);

	/**
	@brief ������
	*/
	void actionAI_Reload();
};

