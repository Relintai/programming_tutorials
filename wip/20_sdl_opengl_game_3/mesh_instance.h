#ifndef MESH_INSTANCE_H
#define MESH_INSTANCE_H

#include <vector>
#include "opengl.h"
#include "material.h"
#include "mesh.h"

#include "./glm/vec3.hpp"

class MeshInstance {
public:
    void render();

    MeshInstance();
    virtual ~MeshInstance();

    Material *material;
    Mesh *mesh;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    std::vector<MeshInstance *> children;
};

#endif
