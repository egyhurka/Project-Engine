#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <optional>

enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;

class Camera
{
public:
	Camera(float aspectRatio, glm::vec3 startPosition);

	void update(std::optional<float> aspectRatio = std::nullopt);
	void ProcessKeyboard(CameraMovement direction, float deltaTime);
	void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 getViewMatrix();

	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

private:
	int screenWidth, screenHeight = 0;
	float ratio;

	float yaw;
	float pitch;
	float movementSpeed;
	float mouseSensitivity;

	void updateCameraVectors();
};