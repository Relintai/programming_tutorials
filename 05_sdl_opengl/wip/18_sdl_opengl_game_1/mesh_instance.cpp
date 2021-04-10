#include "mesh_instance.h"

#include "camera.h"

#include "./glm/vec3.hpp"
#include "./glm/matrix.hpp"
#include "./glm/gtc/matrix_transform.hpp"

void MeshInstance::render() {
    if (!mesh)
        return;

    //glMatrixMode(GL_MODELVIEW);

    //glPushMatrix();

    //glTranslatef(position.x, position.y, position.z);
    //glRotatef(rotation.x, 1, 0, 0);
    //glRotatef(rotation.y, 0, 1, 0);
    //glRotatef(rotation.z, 0, 0, 1);
    //glScalef(scale.x, scale.y, scale.z);

    glm::mat4 mat_oring = Camera::current_camera->model_view_matrix;

    Camera::current_camera->model_view_matrix = glm::translate(Camera::current_camera->model_view_matrix, position);

    Camera::current_camera->model_view_matrix = glm::rotate(Camera::current_camera->model_view_matrix, rotation.x, glm::vec3(1, 0, 0));
    Camera::current_camera->model_view_matrix = glm::rotate(Camera::current_camera->model_view_matrix, rotation.y, glm::vec3(0, 1, 0));
    Camera::current_camera->model_view_matrix = glm::rotate(Camera::current_camera->model_view_matrix, rotation.z, glm::vec3(0, 0, 1));

    Camera::current_camera->model_view_matrix = glm::scale(Camera::current_camera->model_view_matrix, scale);

    if (material) 
        material->bind();

    mesh->render();

    for (uint32_t i = 0; i < children.size(); ++i) {
        MeshInstance *c = children[i];

        if (c)
            c->render();
    }

    //glPopMatrix();

    Camera::current_camera->model_view_matrix = mat_oring;
}

MeshInstance::MeshInstance() {
    material = nullptr;
    mesh = nullptr;

    position = glm::vec3(0, 0, 0);
    rotation = glm::vec3(0, 0, 0);
    scale = glm::vec3(1, 1, 1);
}

MeshInstance::~MeshInstance() {
    children.clear();
}