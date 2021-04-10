#ifndef OBJECT_2D_H
#define OBJECT_2D_H

#include "./glm/vec2.hpp"

class Object2D {
public:

    Object2D();
    virtual ~Object2D();

    glm::vec2 position;
    float rotation;
    glm::vec2 scale;
};

#endif
