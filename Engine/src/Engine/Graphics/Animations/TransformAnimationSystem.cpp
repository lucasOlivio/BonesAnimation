#include "pch.h"

#include "TransformAnimationSystem.h"

#include "Engine/ECS/Scene/SceneView.hpp"
#include "Engine/ECS/Components.h"

#include "Engine/Utils/AnimationUtils.h"

namespace MyEngine
{
    void TransformAnimationSystem::Init()
    {
    }

    void TransformAnimationSystem::Start(Scene* pScene)
    {
        for (Entity entityId : SceneView<TransformComponent, TransformAnimationComponent>(*pScene))
        {
            TransformAnimationComponent* pAnimation = pScene->Get<TransformAnimationComponent>(entityId);

            pAnimation->time = 0.0f;
        }
    }

    void TransformAnimationSystem::Update(Scene* pScene, float deltaTime)
    {
        for (Entity entityId : SceneView<TransformComponent, TransformAnimationComponent>(*pScene))
        {
            TransformComponent* pTransform = pScene->Get<TransformComponent>(entityId);
            TransformAnimationComponent* pAnimation = pScene->Get<TransformAnimationComponent>(entityId);

            float currTime = pAnimation->time;

            // Position
            AnimationUtils::InterpolateAndApply<PositionKeyFrame, glm::vec3>(pAnimation->positionKeyFrames,
                currTime, pAnimation->currStartPosKF, pAnimation->currEndPosKF, pTransform->position);

            // Rotation
            AnimationUtils::InterpolateAndApply<RotationKeyFrame, glm::quat>(pAnimation->rotationKeyFrames,
                currTime, pAnimation->currStartRotKF, pAnimation->currEndRotKF, pTransform->orientation);

            // Scale
            AnimationUtils::InterpolateAndApply<ScaleKeyFrame, float>(pAnimation->scaleKeyFrames,
                currTime, pAnimation->currStartScaKF, pAnimation->currEndScaKF, pTransform->scale);
        }
    }

    void TransformAnimationSystem::Render(Scene* pScene)
    {
    }

    void TransformAnimationSystem::End(Scene* pScene)
    {
    }

    void TransformAnimationSystem::Shutdown()
    {
    }
}
