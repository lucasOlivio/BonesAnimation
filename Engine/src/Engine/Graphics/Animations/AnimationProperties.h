#pragma once

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
		eEasingType easeType;
		float time;
		bool isKeyEvent;
	};

	struct PositionKeyFrame : KeyFrame
	{
		glm::vec3 value;
	};

	struct ScaleKeyFrame : KeyFrame
	{
		float value;
	};

	struct RotationKeyFrame : KeyFrame
	{
		glm::quat value;
	};

	struct NodeAnimationInfo
	{
		NodeAnimationInfo() { }
		NodeAnimationInfo(const std::string& name_) : name(name_) { }

		std::string name; // Node name

		std::vector<PositionKeyFrame> positionKeyFrames;
		std::vector<ScaleKeyFrame> scaleKeyFrames;
		std::vector<RotationKeyFrame> rotationKeyFrames;
	};

	struct AnimationsInfo
	{
		std::vector<NodeAnimationInfo> channels;

		std::string name; // Animation name

		float ticksPerSecond;
		float duration;
		float currTime;

		bool isLoop;
	};
}
