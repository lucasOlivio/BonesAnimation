#pragma once

#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace MyEngine
{
	enum class eEasingType
	{
		Linear,
		SineEaseIn,
		SineEaseOut,
		SineEaseInOut
	};

	struct KeyFrame
	{
		eEasingType easeType = eEasingType::Linear;
		float time = 0.0f;
		bool isKeyEvent = false;
	};

	struct PositionKeyFrame : KeyFrame
	{
		glm::vec3 value = glm::vec3(0.0f);
	};

	struct ScaleKeyFrame : KeyFrame
	{
		glm::vec3 value = glm::vec3(0.0f);
	};

	struct RotationKeyFrame : KeyFrame
	{
		glm::quat value = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
	};

	struct NodeAnimationInfo
	{
		NodeAnimationInfo() { }
		NodeAnimationInfo(const std::string& name_) : name(name_) { }

		std::string name; // Node name

		std::vector<PositionKeyFrame> positionKeyFrames;
		std::vector<ScaleKeyFrame> scaleKeyFrames;
		std::vector<RotationKeyFrame> rotationKeyFrames;

		int currStartPosKF = -1;
		int currEndPosKF = -1;

		int currStartRotKF = -1;
		int currEndRotKF = -1;

		int currStartScaKF = -1;
		int currEndScaKF = -1;
	};

	struct AnimationInfo
	{
		std::map<std::string /*channel(bone) name*/, NodeAnimationInfo> channels;

		std::string name = ""; // Animation name

		float ticksPerSecond = 60.0f;
		float duration = 0.0f;
		float currTime = 0.0f;

		float timeFirstFrame = 0.0f;
		float timeLastFrame = 0.0f;

		bool isLoop = true;
	};

	struct BoneWeightInfo {
		BoneWeightInfo() {
			m_BoneId[0] = 0;
			m_BoneId[1] = 0;
			m_BoneId[2] = 0;
			m_BoneId[3] = 0;
			m_Weight[0] = 0.f;
			m_Weight[1] = 0.f;
			m_Weight[2] = 0.f;
			m_Weight[3] = 0.f;
		}
		float m_BoneId[4];
		float m_Weight[4];
	};
}
