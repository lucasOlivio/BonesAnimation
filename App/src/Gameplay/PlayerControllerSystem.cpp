#include "pch.h"

#include "PlayerControllerSystem.h"


#include "Engine/ECS/SingletonComponents/CoreLocator.h"
#include "Engine/ECS/SingletonComponents/GraphicsLocator.h"
#include "Engine/ECS/Scene/SceneView.hpp"
#include "Engine/ECS/Components.h"

#include "Engine/Events/InputEvent.h"
#include "Engine/Events/WindowEvents.h"
#include "Engine/Events/EventBusLocator.hpp"

#include "Engine/Core/InputProperties.h"

#include "Engine/Utils/InputUtils.h"

namespace MyEngine
{
	void PlayerControllerSystem::Init()
	{
        // Subscribe to keyboard event
        iEventBus<eInputEvents, KeyboardEvent>* pEventBus = EventBusLocator<eInputEvents, KeyboardEvent>::Get();

        pEventBus->Subscribe(eInputEvents::KEYBOARD, InputTriggered);

        m_InitiateMouseCapture();
	}

	void PlayerControllerSystem::Start(Scene* pScene)
	{
	}

	void PlayerControllerSystem::Update(Scene* pScene, float deltaTime)
	{
		KeyInputComponent* pKey = CoreLocator::GetKeyInput();
        for (Entity playerId : SceneView<PlayerComponent>(*pScene))
        {
            PlayerComponent* pPlayer = pScene->Get<PlayerComponent>(playerId);

            // Changing animations
            if (pKey->key[eKeyCodes::KP_1] || pKey->key[eKeyCodes::DIGIT_1])
            {
                ModelComponent* pModel = pScene->Get<ModelComponent>(playerId);

                MeshAnimations* pMeshAnimations = pModel->pMeshes[pModel->currMesh]->pMeshAnimations;
                pMeshAnimations->animActive = 0;
            }
            if (pKey->key[eKeyCodes::KP_2] || pKey->key[eKeyCodes::DIGIT_2])
            {
                ModelComponent* pModel = pScene->Get<ModelComponent>(playerId);

                MeshAnimations* pMeshAnimations = pModel->pMeshes[pModel->currMesh]->pMeshAnimations;
                pMeshAnimations->animActive = 1;
            }
        }
	}

	void PlayerControllerSystem::Render(Scene* pScene)
	{
	}

	void PlayerControllerSystem::End(Scene* pScene)
	{
	}

	void PlayerControllerSystem::Shutdown()
	{
        // Subscribe to keyboard event
        iEventBus<eInputEvents, KeyboardEvent>* pEventBus = EventBusLocator<eInputEvents, KeyboardEvent>::Get();

        pEventBus->Unsubscribe(eInputEvents::KEYBOARD, InputTriggered);

        m_StopMouseCapture();
	}

    void PlayerControllerSystem::InputTriggered(const KeyboardEvent& event)
    {
        if (event.keyData.key != eKeyCodes::ESCAPE)
        {
            return;
        }

        // Trigger window close event
        iEventBus<eWindowEvents, WindowCloseEvent>* pEventBus = EventBusLocator<eWindowEvents, WindowCloseEvent>::Get();

        WindowCloseEvent collEvent = WindowCloseEvent();
        pEventBus->Publish(collEvent);
    }

    void PlayerControllerSystem::m_InitiateMouseCapture()
    {
        // Set initial mouse position to consider mouse on center of window
        MouseInputComponent* pMouse = CoreLocator::GetMouseInput();
        if (pMouse->mouseCaptured)
        {
            return;
        }

        WindowComponent* pWindow = GraphicsLocator::GetWindow();

        pMouse->lastPosX = pMouse->posX;
        pMouse->lastPosY = pMouse->posY;

        InputUtils::CaptureMouse(pWindow->pGLFWWindow);
        pMouse->mouseCaptured = true;
        pMouse->sensitivity = DEFAULT_MOUSE_SENSITIVITY;

        return;
    }

    void PlayerControllerSystem::m_StopMouseCapture()
    {
        MouseInputComponent* pMouse = CoreLocator::GetMouseInput();
        if (!pMouse->mouseCaptured)
        {
            return;
        }
        WindowComponent* pWindow = GraphicsLocator::GetWindow();

        InputUtils::ReleaseMouse(pWindow->pGLFWWindow);
        pMouse->mouseCaptured = false;

        return;
    }
}
