#pragma once

#include "Engine/ECS/System/iSystem.h"
#include "Engine/ECS/Components.h"

#include "Engine/Graphics/GraphicsProperties.h"

namespace MyEngine
{
	// Handles all the transform movements based on the time and the key frames for the animation
	class NodeAnimationSystem : public iSystem
	{
	public:
		NodeAnimationSystem() = default;
		virtual ~NodeAnimationSystem() { };

		virtual std::string SystemName() { return "NodeAnimationSystem"; };

		virtual void Init();

		virtual void Start(Scene* pScene);

		virtual void Update(Scene* pScene, float deltaTime);

		virtual void Render(Scene* pScene);

		virtual void End(Scene* pScene);

		virtual void Shutdown();

	private:
		void m_CalculateMatrices(sMesh* pMesh, NodeAnimationComponent* pNodeAnim, Node* node, const glm::mat4& parentTransformationMatrix, double keyFrameTime);

	};
}
