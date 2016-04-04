#pragma once

/**
@brief ���� AI ����
@details ����� �޾��� ��, ����Ǿ�� �� �������� Set���ش�. �׸��� �Ѿ��� ���� ���� �ֽ�ȭ�Ѵ�.
*/

class Service_Destination :
	public BTService
{
public:
	BlackboardKeySelector Destination;
	BlackboardKeySelector myCharacter;
	BlackboardKeySelector bullet;
	BlackboardKeySelector SelectAI;
	BlackboardKeySelector Command;
	BlackboardKeySelector OriginalRotation;
	AI_Person AI_Person_Ref;
	Shotgun_AI_Person Storm_Ref;
	M4A1_AI_Person M4A1_Ref;
	AWP_AI_Person AWP_Ref;

	/**
	@brief ���� ƽ �̺�Ʈ
	@details �Ѿ� ���� Set���ִ� ����
	@details ������ �Ѿ� ���� ������ bullet ������ ������ Set��
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveTick(Actor OwnerActor);

	/**
	@brief ���� Ȱ��ȭ �̺�Ʈ
	@details ����� �޾Ҵٸ� moveToPointEvent�� Ȱ��ȭ�Ǿ� Destination�� Command ������ Set�ǰ�, �ƴ϶�� followOnEvent�� Ȱ��ȭ�Ǿ� Command�� Set�ϰ� Destination�� �����. 
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph ReceiveActivation(Actor OwnerActor);

	/**
	@brief Ŀ���� �̺�Ʈ
	@details Destination�� Command ������ Set�ȴ�. (�������� Set�ȴ�)
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph moveToPointEvent(Vector Point);

	/**
	@brief Ŀ���� �̺�Ʈ
	@details Command�� Set�ϰ� Destination�� �����. (�������� �����.)
	@param OwnerActor AI ��Ʈ�ѷ�.
	*/
	EventGraph followOnEvent();
};

