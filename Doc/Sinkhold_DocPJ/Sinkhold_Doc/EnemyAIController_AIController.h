#pragma once

/**
@brief 적 AI 컨트롤러
@details 적 AI 캐릭터들을 컨트롤하기 위한 프레임워크 애셋
*/
class EnemyAIController_AIController :
	public AIController
{
public:
	/**
	@brief 게임 시작 이벤트
	@details 적 AI 비헤이비어 트리를 각각의 적 캐릭터들에게 연결시켜준다.
	*/
	EventGraph BeginPlay();
};

