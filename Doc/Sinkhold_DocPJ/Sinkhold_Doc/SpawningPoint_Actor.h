#pragma once

/**
@brief ���� ���� ����
@details ���� �� ������ ��ƼŬ �ϳ��� �����ϰ� ������� ����.
*/
class SpawningPoint_Actor :
	public Actor
{
public:
	/**
	@brief ����Ʈ���� ��ũ��Ʈ
	@details ��ȯ�� �� ĳ���� Ŭ������ �迭�� �����.
	*/
	Construction Script();

	/**
	@brief ���� �̺�Ʈ
	@details ��ƼŬ �ϳ��� �����ϰ�, �迭���� ���� Ŭ������ �������� ������ �����Ѵ�.
	*/
	EventGraph BeginPlay();
};

