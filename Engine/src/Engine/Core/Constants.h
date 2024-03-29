#pragma once

#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace MyEngine
{
#define MAX_LINE_LENGTH 65536		// 16x1024
#define PI 3.14f

#define CHANNELGROUP_MASTER_INDEX	0
#define CHANNELGROUP_MUSIC_INDEX	1
#define CHANNELGROUP_SFX_INDEX		2

// This should match with the number in the shaders
#define MAX_LIGHTS 40

#define TEXT_FONT_SIZE 1.2f

#define MAX_PARTICLES 1000

#define DEFAULT_MOUSE_SENSITIVITY 0.001f

	const std::string DEFAULT_CONFIG = "config.json";

	const glm::vec3 X_VECTOR = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	const glm::vec3 Y_VECTOR = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	const glm::vec3 Z_VECTOR = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	const glm::vec3 W_VECTOR = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	const glm::vec4 RIGHT_VECTOR = glm::vec4(1, 0, 0, 1);
	const glm::vec4 UP_VECTOR = glm::vec4(0, 1, 0, 1);
	const glm::vec4 FORWARD_VECTOR = glm::vec4(0, 0, -1, 1);

	const int   FRAME_RATE = 30;  // Frames per second
	const float FRAME_DURATION = 1.0f / (float)FRAME_RATE;

	const glm::vec4 WHITE = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	const glm::vec4 RED = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	const glm::vec4 GREEN = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	const glm::vec4 BLUE = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	const glm::vec4 YELLOW = glm::vec4(0.0f, 1.0f, 1.0f, 1.0f);

	// For any kind of orientation needed
	enum eDirections
	{
		BACKWARD,
		LEFT,
		RIGHT,
		FORWARD
	};
}