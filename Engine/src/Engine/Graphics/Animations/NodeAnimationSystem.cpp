#include "pch.h"

#include "NodeAnimationSystem.h"

#include "Engine/ECS/Scene/SceneView.hpp"
#include "Engine/ECS/Components.h"

#include "Engine/Utils/AnimationUtils.h"

namespace MyEngine
{
    void NodeAnimationSystem::Init()
    {
    }

    void NodeAnimationSystem::Start(Scene* pScene)
    {
    }

    void NodeAnimationSystem::Update(Scene* pScene, float deltaTime)
    {
        // Update node/bones hierarchy
        //glm::mat4 origin = glm::mat4(1.0f);
        //glm::mat4 rootTransformation = glm::mat4(1.f);

        //CalculateMatrices(model, model->CharacterAnimations[0], model->RootNode, rootTransformation, 0.f);
    }

    void NodeAnimationSystem::Render(Scene* pScene)
    {
    }

    void NodeAnimationSystem::End(Scene* pScene)
    {
    }

    void NodeAnimationSystem::Shutdown()
    {
    }

    void NodeAnimationSystem::m_CalculateMatrices(sMesh* pMesh, NodeAnimationComponent* pNodeAnim, Node* node, const glm::mat4& parentTransformationMatrix, double keyFrameTime)
	{
		//std::string nodeName(node->Name);		// use this for lookups, bones, animation nodes

		//glm::mat4 transformationMatrix = node->Transformation;

		//// Project #2
		//// Animation calculation
		//// AnimationData* data = FindAnimationDat(nodeName);
		////if (data != nullptr)
		//{
		//	// glm::vec3 position = GetAnimationPosition(data, keyFrameTime);	/// POSITION update in previous function
		//	// glm::vec3 scale = GetAnimationPosition(data, keyFrameTime);		/// SCALE from your project
		//	// glm::vec3 rotation = GetAnimationPosition(data, keyFrameTime);	/// ROTATION update from previous function

		//	// calculate the matrices
		//	// glm::mat4 translationMatrix = glm::translate(glm::mat4(1.f), position);
		//	// glm::mat4 rotationMatrix = glm::mat4_cast(rotation);
		//	// glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.f), scale);

		//	// transformationMatrix = translationMatrix * rotationMatrix * scaleMatrix
		//}

		//// Calculate the global transformation
		//glm::mat4 globalTransformation = parentTransformationMatrix * transformationMatrix;

		//// If there is a bone associated with this name, assign the global transformation
		//auto boneMapIt = model->BoneNameToIdMap.find(nodeName);
		//if (boneMapIt != model->BoneNameToIdMap.end())
		//{
		//	BoneInfo& boneInfo = model->BoneInfoVec[boneMapIt->second];
		//	boneInfo.FinalTransformation = model->GlobalInverseTransformation * globalTransformation * boneInfo.BoneOffset;
		//	boneInfo.GlobalTransformation = globalTransformation;
		//}

		//// Calculate all children
		//for (int i = 0; i < node->Children.size(); ++i)
		//{
		//	CalculateMatrices(model, animation, node->Children[i], globalTransformation, keyFrameTime);
		//}
	}
}
