#include "camera.h"

#include "./glm/gtc/matrix_transform.hpp"

Camera *Camera::current_camera = nullptr;

void Camera::bind() {
	make_current();

	model_view_matrix = glm::mat4(1);
}

void Camera::make_current() {
	current_camera = this;
}

Camera::Camera() {
	width = 2;
	height = 2;
	fov = glm::radians(45.0);

	position = glm::vec3(0, 0, 0);
	rotation = glm::vec3(0, 0, 0);
	scale = glm::vec3(1, 1, 1);
}
Camera::~Camera() {
}

void OrthographicCamera::bind() {
    Camera::bind();

    //fixed function pipeline
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    //glOrtho(bottom_left.x, top_right.x, bottom_left.y, top_right.y, near, far);

    //glTranslatef(position.x, position.y, 0);
    //glRotatef(rotation.x, 1, 0, 0);
	//glRotatef(rotation.y, 0, 1, 0);
    //glRotatef(rotation.z, 0, 0, 1);
    
	//glScalef(scale.x, scale.y, scale.z);

    projection_matrix = glm::ortho<float>(-(width / 2.0), width / 2.0, -(height / 2.0), height / 2.0);

    projection_matrix = glm::translate(projection_matrix, -position);

    projection_matrix = glm::rotate(projection_matrix, rotation.x, glm::vec3(1, 0, 0));
    projection_matrix = glm::rotate(projection_matrix, rotation.y, glm::vec3(0, 1, 0));
    projection_matrix = glm::rotate(projection_matrix, rotation.z, glm::vec3(0, 0, 1));

    projection_matrix = glm::scale(projection_matrix, scale);
}

OrthographicCamera::OrthographicCamera() : Camera() {
}

OrthographicCamera::~OrthographicCamera() {
}

void PerspectiveCamera::bind() {
    Camera::bind();

    //fixed fucntion pipeline
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    //glFrustum(bottom_left.x, top_right.x, bottom_left.y, top_right.y, near, far);

    //glTranslatef(position.x, position.y, position.z);
    //glRotatef(rotation.x, 1, 0, 0);
	//glRotatef(rotation.y, 0, 1, 0);
	//glRotatef(rotation.z, 0, 0, 1);
    
	//glScalef(scale.x, scale.y, scale.z);

    projection_matrix = glm::perspectiveFov<float>(fov, width, height, near, far);

    projection_matrix = glm::translate(projection_matrix, -position);

    projection_matrix = glm::rotate(projection_matrix, rotation.x, glm::vec3(1, 0, 0));
    projection_matrix = glm::rotate(projection_matrix, rotation.y, glm::vec3(0, 1, 0));
    projection_matrix = glm::rotate(projection_matrix, rotation.z, glm::vec3(0, 0, 1));

    projection_matrix = glm::scale(projection_matrix, scale);
}

PerspectiveCamera::PerspectiveCamera() : Camera() {
    near = 0.1;
    far = 10;
}

PerspectiveCamera::~PerspectiveCamera() {
}