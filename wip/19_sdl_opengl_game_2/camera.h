#ifndef CAMERA_H
#define CAMERA_H

#include "opengl.h"

#include "./glm/vec3.hpp"
#include "./glm/matrix.hpp"

class Camera {
public:
    virtual void bind();

    void make_current();

    Camera();
    virtual ~Camera();

    float width;
    float height;
    float fov;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    static Camera *current_camera;

    glm::mat4x4 projection_matrix;
    glm::mat4x4 model_view_matrix;
};

class OrthographicCamera : public Camera {
public:

    void bind();

    OrthographicCamera();
    ~OrthographicCamera();
};

class PerspectiveCamera : public Camera {
public:
    float near;
    float far;

    void bind();

    PerspectiveCamera();
    ~PerspectiveCamera();
};

#endif
