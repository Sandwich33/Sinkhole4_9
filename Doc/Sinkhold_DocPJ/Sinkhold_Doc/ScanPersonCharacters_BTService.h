#pragma once

/**
@brief �� AI ����
@details �� ƽ���� ���� ����� ã�´�. �߰��ϸ� ����� �������� targetToAttack�� set�Ѵ�.
*/
class ScanPersonCharacters_BTService :
	public BTService
{
public:
	BlackboardKeySelector targetToAttack;
private:
	Vector myLocation;
	Actor allTheSameActors[];
	float closest;
	Actor closestActor;
};

