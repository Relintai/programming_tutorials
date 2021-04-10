#include "mesh_instance.h"

void MeshInstance::render() {
    if (!mesh)
        return;

    if (material) 
        material->bind();

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glTranslatef(position.x, position.y, position.z);
    glRotatef(rotation.x, 1, 0, 0);
    glRotatef(rotation.y, 0, 1, 0);
    glRotatef(rotation.z, 0, 0, 1);
    glScalef(scale.x, scale.y, scale.z);

    mesh->render();

    for (uint32_t i = 0; i < children.size(); ++i) {
        MeshInstance *c = children[i];

        if (c)
            c->render();
    }

    glPopMatrix();
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