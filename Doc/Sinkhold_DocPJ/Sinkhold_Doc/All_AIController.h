#pragma once

/**
@brief 팀원 AI 컨트롤러
@details 팀원 AI 캐릭터들을 컨트롤하기 위한 프레임워크 애셋
*/

class All_AIController :
	public AIController
{
public:
	/**
	@brief Possess 이벤트
	@details 팀원 AI 비헤이비어 트리를 각각의 팀원 캐릭터들에게 연결시켜준다.
	*/
	EventGraph OnPossess();
};

