#pragma once

/**
@brief ���� ���� ����
@details ���� ���� ������ �������� SpawningPoint �� �����Ѵ�.
*/
class SpawningVloume_Actor :
	public Actor
{
public:
	/**
	@brief ƽ �̺�Ʈ
	@details ���� ���� ������ �������� SpawningPoint �� �����Ѵ�.
	@details ���� ���� �� ĳ���� ���� �����ؼ� ������ �� �̻��̸� ������ ���´�.
	*/
	EventGraph Tick();
};

