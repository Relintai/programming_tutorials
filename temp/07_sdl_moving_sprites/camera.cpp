#include "camera.h"

#include "renderer.h"

void Camera::bind() {
    Renderer::get_singleton()->set_integer_scaling(integer_scaling);

    Renderer::get_singleton()->set_scale(scale_w, scale_h);

    Renderer::get_singleton()->set_viewport(viewport);
    Renderer::get_singleton()->set_clip_rect(&clip_rect);
}

Camera::Camera() {
    integer_scaling = false;

    scale_w = 1;
    scale_h = 1;

    viewport = Renderer::get_singleton()->get_viewport();
    clip_rect = Renderer::get_singleton()->get_clip_rect();
}
Camera::~Camera() {
}
