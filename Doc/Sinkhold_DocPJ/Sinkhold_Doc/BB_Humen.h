#pragma once

/**
@brief ���� AI ������
@details �����̺�� Ʈ���� �帧�� �����ϱ� ���� �������� ��Ƶδ� ���̴�.
*/

class BB_Humen :
	public Blackboard
{
public:
	Object myCharacter;
	Object targetToAttack;
	Object SelectAI;
	Vector Destination;
	Vector myLocation;
	Integer bullet;
	Rotator OriginalRotation;
	Float attackRange;
	Bool Command;
	Bool distanceCheck;
};

