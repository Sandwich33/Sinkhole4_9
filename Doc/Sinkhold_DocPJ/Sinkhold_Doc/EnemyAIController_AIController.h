#pragma once

/**
@brief �� AI ��Ʈ�ѷ�
@details �� AI ĳ���͵��� ��Ʈ���ϱ� ���� �����ӿ�ũ �ּ�
*/
class EnemyAIController_AIController :
	public AIController
{
public:
	/**
	@brief ���� ���� �̺�Ʈ
	@details �� AI �����̺�� Ʈ���� ������ �� ĳ���͵鿡�� ��������ش�.
	*/
	EventGraph BeginPlay();
};

