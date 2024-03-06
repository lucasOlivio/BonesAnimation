#include "pch.h"

#include "MeshAnimationSystem.h"

#include "Engine/ECS/Scene/SceneView.hpp"
#include "Engine/ECS/Components.h"

#include "Engine/Utils/AnimationUtils.h"
#include "Engine/Utils/TransformUtils.h"

#include <glm/gtx/matrix_decompose.hpp>

#define PRINT_SPACES(x) {int s = x; while(s--> 0) printf(" ");}

namespace MyEngine
{
	void MeshAnimationSystem::Init()
	{
	}

	void MeshAnimationSystem::Start(Scene* pScene)
	{
		//for (Entity entityId : SceneView<TagComponent, TransformComponent, ModelComponent>(*pScene))
		//{
		//	TagComponent* pTag = pScene->Get<TagComponent>(entityId);
		//	TransformComponent* pTransform = pScene->Get<TransformComponent>(entityId);
		//	ModelComponent* pModel = pScene->Get<ModelComponent>(entityId);

		//	if (pTag->name != "character")
		//	{
		//		continue;
		//	}

		//	// ANIMATION TEST
		//	MeshAnimations* pMeshAnimations = new MeshAnimations();
		//	pMeshAnimations->isActive = true;
		//	pMeshAnimations->animActive = 0;

		//	pMeshAnimations->animations.resize(2);
		//	AnimationInfo animInfo = AnimationInfo();

		//	 // ANIMATION 1
		//	{
		//		animInfo.name = "test1";
		//		animInfo.duration = 60.0f;
		//		animInfo.ticksPerSecond = 60.0f;

		//		for (uint j = 0; j < 1; ++j)
		//		{
		//			// LEFT ARM
		//			NodeAnimationInfo nodeAnimInfo = NodeAnimationInfo();
		//			nodeAnimInfo.name = "mixamorig:LeftArm";

		//			nodeAnimInfo.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF = RotationKeyFrame();
		//			rotKF.time = 0.0f;
		//			rotKF.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.3826834f);
		//			nodeAnimInfo.rotationKeyFrames[0] = rotKF;

		//			RotationKeyFrame rotKF2 = RotationKeyFrame();
		//			rotKF2.time = 60.0f;
		//			rotKF2.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, -0.3826834f);
		//			nodeAnimInfo.rotationKeyFrames[1] = rotKF2;

		//			RotationKeyFrame rotKF3 = RotationKeyFrame();
		//			rotKF3.time = 120.0f;
		//			rotKF3.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.3826834f);
		//			nodeAnimInfo.rotationKeyFrames[2] = rotKF3;

		//			animInfo.channels[nodeAnimInfo.name] = nodeAnimInfo;

		//			// RIGHT ARM
		//			NodeAnimationInfo nodeAnimInfo2 = NodeAnimationInfo();
		//			nodeAnimInfo2.name = "mixamorig:RightArm";

		//			nodeAnimInfo2.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF4 = RotationKeyFrame();
		//			rotKF4.time = 0.0f;
		//			rotKF4.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.3826834f);
		//			nodeAnimInfo2.rotationKeyFrames[0] = rotKF4;

		//			RotationKeyFrame rotKF5 = RotationKeyFrame();
		//			rotKF5.time = 60.0f;
		//			rotKF5.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, -0.3826834f);
		//			nodeAnimInfo2.rotationKeyFrames[1] = rotKF5;

		//			RotationKeyFrame rotKF6 = RotationKeyFrame();
		//			rotKF6.time = 120.0f;
		//			rotKF6.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.3826834f);
		//			nodeAnimInfo2.rotationKeyFrames[2] = rotKF6;

		//			animInfo.channels[nodeAnimInfo2.name] = nodeAnimInfo2;

		//			// LEFT LEG
		//			NodeAnimationInfo nodeAnimInfo3 = NodeAnimationInfo();
		//			nodeAnimInfo3.name = "mixamorig:LeftUpLeg";

		//			nodeAnimInfo3.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF7 = RotationKeyFrame();
		//			rotKF7.time = 0.0f;
		//			rotKF7.value = glm::quat(0.9238795f, -0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo3.rotationKeyFrames[0] = rotKF7;

		//			RotationKeyFrame rotKF8 = RotationKeyFrame();
		//			rotKF8.time = 60.0f;
		//			rotKF8.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo3.rotationKeyFrames[1] = rotKF8;

		//			RotationKeyFrame rotKF9 = RotationKeyFrame();
		//			rotKF9.time = 120.0f;
		//			rotKF9.value = glm::quat(0.9238795f, -0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo3.rotationKeyFrames[2] = rotKF9;

		//			animInfo.channels[nodeAnimInfo3.name] = nodeAnimInfo3;

		//			// RIGHT LEG
		//			NodeAnimationInfo nodeAnimInfo4 = NodeAnimationInfo();
		//			nodeAnimInfo4.name = "mixamorig:RightUpLeg";

		//			nodeAnimInfo4.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF10 = RotationKeyFrame();
		//			rotKF10.time = 0.0f;
		//			rotKF10.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo4.rotationKeyFrames[0] = rotKF10;

		//			RotationKeyFrame rotKF11 = RotationKeyFrame();
		//			rotKF11.time = 60.0f;
		//			rotKF11.value = glm::quat(0.9238795f, -0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo4.rotationKeyFrames[1] = rotKF11;

		//			RotationKeyFrame rotKF12 = RotationKeyFrame();
		//			rotKF12.time = 120.0f;
		//			rotKF12.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo4.rotationKeyFrames[2] = rotKF12;

		//			animInfo.channels[nodeAnimInfo4.name] = nodeAnimInfo4;
		//		}
		//		animInfo.timeLastFrame = 120.0f;

		//		pMeshAnimations->animations[0] = animInfo;
		//	}

		//	// ANIMATION 2
		//	{
		//		AnimationInfo animInfo2 = AnimationInfo();

		//		animInfo2.name = "test2";
		//		animInfo2.duration = 60.0f;
		//		animInfo2.ticksPerSecond = 60.0f;

		//		for (uint j = 0; j < 1; ++j)
		//		{
		//			// HIP
		//			NodeAnimationInfo nodeAnimInfoHip = NodeAnimationInfo();
		//			nodeAnimInfoHip.name = "mixamorig:Hips";

		//			nodeAnimInfoHip.positionKeyFrames.resize(3);

		//			PositionKeyFrame posKF = PositionKeyFrame();
		//			posKF.time = 0.0f;
		//			posKF.value = glm::vec3(0.0f, 0.91f, 0.0f);
		//			nodeAnimInfoHip.positionKeyFrames[0] = posKF;

		//			PositionKeyFrame posKF2 = PositionKeyFrame();
		//			posKF2.time = 60.0f;
		//			posKF2.value = glm::vec3(0.0f, 2.0f, 0.0f);
		//			nodeAnimInfoHip.positionKeyFrames[1] = posKF2;

		//			PositionKeyFrame posKF3 = PositionKeyFrame();
		//			posKF3.time = 120.0f;
		//			posKF3.value = glm::vec3(0.0f, 0.91f, 0.0f);
		//			nodeAnimInfoHip.positionKeyFrames[2] = posKF3;

		//			animInfo2.channels[nodeAnimInfoHip.name] = nodeAnimInfoHip;

		//			// LEFT ARM
		//			NodeAnimationInfo nodeAnimInfo = NodeAnimationInfo();
		//			nodeAnimInfo.name = "mixamorig:LeftArm";

		//			nodeAnimInfo.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF = RotationKeyFrame();
		//			rotKF.time = 0.0f;
		//			rotKF.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo.rotationKeyFrames[0] = rotKF;

		//			RotationKeyFrame rotKF2 = RotationKeyFrame();
		//			rotKF2.time = 60.0f;
		//			rotKF2.value = glm::quat(0.9238795f, -0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo.rotationKeyFrames[1] = rotKF2;

		//			RotationKeyFrame rotKF3 = RotationKeyFrame();
		//			rotKF3.time = 120.0f;
		//			rotKF3.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo.rotationKeyFrames[2] = rotKF3;

		//			animInfo2.channels[nodeAnimInfo.name] = nodeAnimInfo;

		//			// RIGHT ARM
		//			NodeAnimationInfo nodeAnimInfo2 = NodeAnimationInfo();
		//			nodeAnimInfo2.name = "mixamorig:RightArm";

		//			nodeAnimInfo2.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF4 = RotationKeyFrame();
		//			rotKF4.time = 0.0f;
		//			rotKF4.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo2.rotationKeyFrames[0] = rotKF4;

		//			RotationKeyFrame rotKF5 = RotationKeyFrame();
		//			rotKF5.time = 60.0f;
		//			rotKF5.value = glm::quat(0.9238795f, -0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo2.rotationKeyFrames[1] = rotKF5;

		//			RotationKeyFrame rotKF6 = RotationKeyFrame();
		//			rotKF6.time = 120.0f;
		//			rotKF6.value = glm::quat(0.9238795f, 0.3826834f, 0.0f, 0.0f);
		//			nodeAnimInfo2.rotationKeyFrames[2] = rotKF6;

		//			animInfo2.channels[nodeAnimInfo2.name] = nodeAnimInfo2;

		//			// LEFT LEG
		//			NodeAnimationInfo nodeAnimInfo3 = NodeAnimationInfo();
		//			nodeAnimInfo3.name = "mixamorig:LeftUpLeg";

		//			nodeAnimInfo3.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF7 = RotationKeyFrame();
		//			rotKF7.time = 0.0f;
		//			rotKF7.value = glm::quat(0.9238795f, 0.0f, 0.0f, 0.0f);
		//			nodeAnimInfo3.rotationKeyFrames[0] = rotKF7;

		//			RotationKeyFrame rotKF8 = RotationKeyFrame();
		//			rotKF8.time = 60.0f;
		//			rotKF8.value = glm::quat(0.9238795f, 0.0f, 0.0f, 0.3826834f);
		//			nodeAnimInfo3.rotationKeyFrames[1] = rotKF8;

		//			RotationKeyFrame rotKF9 = RotationKeyFrame();
		//			rotKF9.time = 120.0f;
		//			rotKF9.value = glm::quat(0.9238795f, 0.0f, 0.0f, 0.0f);
		//			nodeAnimInfo3.rotationKeyFrames[2] = rotKF9;

		//			animInfo2.channels[nodeAnimInfo3.name] = nodeAnimInfo3;

		//			// RIGHT LEG
		//			NodeAnimationInfo nodeAnimInfo4 = NodeAnimationInfo();
		//			nodeAnimInfo4.name = "mixamorig:RightUpLeg";

		//			nodeAnimInfo4.rotationKeyFrames.resize(3);

		//			RotationKeyFrame rotKF10 = RotationKeyFrame();
		//			rotKF10.time = 0.0f;
		//			rotKF10.value = glm::quat(0.9238795f, 0.0f, 0.0f, 0.0f);
		//			nodeAnimInfo4.rotationKeyFrames[0] = rotKF10;

		//			RotationKeyFrame rotKF11 = RotationKeyFrame();
		//			rotKF11.time = 60.0f;
		//			rotKF11.value = glm::quat(0.9238795f, 0.0f, 0.0f, -0.3826834f);
		//			nodeAnimInfo4.rotationKeyFrames[1] = rotKF11;

		//			RotationKeyFrame rotKF12 = RotationKeyFrame();
		//			rotKF12.time = 120.0f;
		//			rotKF12.value = glm::quat(0.9238795f, 0.0f, 0.0f, 0.0f);
		//			nodeAnimInfo4.rotationKeyFrames[2] = rotKF12;

		//			animInfo2.channels[nodeAnimInfo4.name] = nodeAnimInfo4;
		//		}
		//		animInfo2.timeLastFrame = 120.0f;

		//		pMeshAnimations->animations[1] = animInfo2;
		//	}

		//	pModel->pMeshes[0]->pMeshAnimations = pMeshAnimations;
		//}
	}

	void MeshAnimationSystem::Update(Scene* pScene, float deltaTime)
	{
		for (Entity entityId : SceneView<TransformComponent, ModelComponent>(*pScene))
		{
			TransformComponent* pTransform = pScene->Get<TransformComponent>(entityId);
			ModelComponent* pModel = pScene->Get<ModelComponent>(entityId);

			if (pModel->pMeshes.size() == 0 ||
				!pModel->isActive)
			{
				continue;
			}

			MeshAnimations* pMeshAnimations = pModel->pMeshes[pModel->currMesh]->pMeshAnimations;
			if (!pMeshAnimations || !pMeshAnimations->isActive)
			{
				continue;
			}

			AnimationInfo& animation = pMeshAnimations->animations[pMeshAnimations->animActive];
			sMesh* pMesh = pModel->pMeshes[0];

			glm::mat4 matTransform = glm::mat4(1.0f);
			glm::mat4 globalInverseMat = glm::inverse(pMesh->rootNode->transformation);

			m_CalculateMatrices(pMesh, *(pMesh->rootNode), animation,
								matTransform, globalInverseMat);
		}
	}

	void MeshAnimationSystem::Render(Scene* pScene)
	{
	}

	void MeshAnimationSystem::End(Scene* pScene)
	{
	}

	void MeshAnimationSystem::Shutdown()
	{
	}

	void MeshAnimationSystem::m_CalculateMatrices(sMesh* pMesh,
													Node& node,
													AnimationInfo& animation,
													const glm::mat4& parentTransformationMatrix,
													const glm::mat4& globalInverseMat)
	{
		std::string nodeName = node.name;

		glm::mat4 transformationMatrix = node.transformation;

		glm::vec3 positiontest = glm::vec3(0.0f);
		glm::quat rotationtest = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
		glm::vec3 scaletest = glm::vec3(1.0f);
		glm::vec3 skew;
		glm::vec4 perspective;
		glm::decompose(transformationMatrix, scaletest, rotationtest, positiontest, skew, perspective);

		std::map<std::string, NodeAnimationInfo>::iterator animIt = animation.channels.find(nodeName);
		if (animIt != animation.channels.end())
		{
			NodeAnimationInfo& nodeAnimInfo = animIt->second;

			// Position
			glm::vec3 position = glm::vec3(0.0f);
			AnimationUtils::InterpolateAndApply<PositionKeyFrame, glm::vec3>(nodeAnimInfo.positionKeyFrames,
				animation.currTime, nodeAnimInfo.currStartPosKF, nodeAnimInfo.currEndPosKF, position);

			// Rotation
			glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
			AnimationUtils::InterpolateAndApply<RotationKeyFrame, glm::quat>(nodeAnimInfo.rotationKeyFrames,
				animation.currTime, nodeAnimInfo.currStartRotKF, nodeAnimInfo.currEndRotKF, rotation);

			// Scale
			glm::vec3 scale = glm::vec3(1.0f);
			AnimationUtils::InterpolateAndApply<ScaleKeyFrame, glm::vec3>(nodeAnimInfo.scaleKeyFrames,
				animation.currTime, nodeAnimInfo.currStartScaKF, nodeAnimInfo.currEndScaKF, scale);

			transformationMatrix = glm::mat4(1.0f);
			TransformUtils::GetTransform(position, rotation, scale, transformationMatrix);
		}

		// Calculate the global transformation
 		glm::mat4 globalTransformation = parentTransformationMatrix * transformationMatrix;

		std::map<std::string, int>::iterator bonesIt = pMesh->boneNameId.find(nodeName);
		if (bonesIt != pMesh->boneNameId.end())
		{
			// If there is a bone associated with this name, assign the global transformation
			int boneId = bonesIt->second;
			BoneInfo& boneInfo = pMesh->bonesInfo[boneId];

			boneInfo.FinalTransformation = globalInverseMat * globalTransformation * boneInfo.BoneOffset;
			boneInfo.GlobalTransformation = globalTransformation;
		}

		// Calculate all children
		for (int i = 0; i < node.children.size(); ++i)
		{
			m_CalculateMatrices(pMesh , *(node.children[i]), animation,
								globalTransformation, globalInverseMat);
		}
	}
}
