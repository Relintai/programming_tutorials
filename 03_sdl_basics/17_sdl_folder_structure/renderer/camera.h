#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

#include "core/rect2.h"

class Camera {
public:
    void bind();

    Camera();
    virtual ~Camera();

    bool integer_scaling;
    float scale_w;
    float scale_h;
    Rect2 viewport;
    Rect2 clip_rect;
};

#endif