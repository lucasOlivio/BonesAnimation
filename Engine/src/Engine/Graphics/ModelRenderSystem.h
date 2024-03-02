#pragma once

#include "Engine/ECS/System/iSystem.h"

namespace MyEngine
{
	// Sends all needed models to the rendering pipeline
	class ModelRenderSystem : public iSystem
	{
	public:
		ModelRenderSystem() = default;
		virtual ~ModelRenderSystem() { };

		virtual std::string SystemName() { return "ModelRenderSystem"; };

		virtual void Init();

		virtual void Start(Scene* pScene);

		virtual void Update(Scene* pScene, float deltaTime);

		virtual void Render(Scene* pScene);

		virtual void End(Scene* pScene);

		virtual void Shutdown();
	};
}