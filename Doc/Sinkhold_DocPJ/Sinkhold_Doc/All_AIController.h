#pragma once

/**
@brief ���� AI ��Ʈ�ѷ�
@details ���� AI ĳ���͵��� ��Ʈ���ϱ� ���� �����ӿ�ũ �ּ�
*/

class All_AIController :
	public AIController
{
public:
	/**
	@brief Possess �̺�Ʈ
	@details ���� AI �����̺�� Ʈ���� ������ ���� ĳ���͵鿡�� ��������ش�.
	*/
	EventGraph OnPossess();
};

