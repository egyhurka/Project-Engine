#include "Camera.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "..\Core\Log.h"
#include "..\Input\Input.h"

Camera::Camera(float aspectRatio, glm::vec3 startPosition)
	: ratio(aspectRatio), front(glm::vec3(0.0f, 0.0f, -1.0f)), up(glm::vec3(0.0f, 1.0f, 0.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVITY)
{
	position = startPosition;
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	yaw = YAW;
	pitch = PITCH;
	updateCameraVectors();
}

void Camera::update(std::optional<float> aspectRatio)
{
	projection = glm::perspective(glm::radians(45.0f), aspectRatio.value_or(ratio), 0.1f, 100.0f);
	view = getViewMatrix();
}

void Camera::ProcessKeyboard(CameraMovement direction, float deltaTime)
{
	float velocity = movementSpeed * deltaTime;
	if (direction == FORWARD)
		position += front * velocity;
	if (direction == BACKWARD)
		position -= front * velocity;
	if (direction == LEFT)
		position -= right * velocity;
	if (direction == RIGHT)
		position += right * velocity;
	if (direction == UP)
		position += worldUp * velocity;
	if (direction == DOWN)
		position -= worldUp * velocity;
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (constrainPitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix()
{
	return glm::lookAt(position, position + front, up);
}

void Camera::updateCameraVectors()
{
	glm::vec3 unFront;
	unFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	unFront.y = sin(glm::radians(pitch));
	unFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(unFront);

	right = glm::normalize(glm::cross(front, worldUp));
	up = glm::normalize(glm::cross(right, front));
}