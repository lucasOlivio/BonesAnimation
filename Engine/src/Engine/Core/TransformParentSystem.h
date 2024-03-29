#pragma once

#include "Engine/ECS/System/iSystem.h"

namespace MyEngine
{
	// Keeps the world values from transform updated relative to parent
	class TransformParentSystem : public iSystem
	{
	public:
		TransformParentSystem() = default;
		virtual ~TransformParentSystem() { };

		virtual std::string SystemName() { return "TransformParentSystem"; };

		virtual void Init();

		virtual void Start(Scene* pScene);

		virtual void Update(Scene* pScene, float deltaTime);

		virtual void Render(Scene* pScene);

		virtual void End(Scene* pScene);

		virtual void Shutdown();
	};
}
