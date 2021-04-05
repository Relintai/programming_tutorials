#ifndef IMPL_APPLICATION_H
#define IMPL_APPLICATION_H

#include "application.h"

#include "main_scene.h"

class ImplApplication : public Application {
public:
    ImplApplication() : Application() {
        scene = new MainScene();
    }
    ~ImplApplication() {
        delete scene;
    }
};

#endif