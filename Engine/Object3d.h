//
// Created by nathan on 6/15/19.
//

#ifndef VOXEL4_OBJECT3D_H
#define VOXEL4_OBJECT3D_H

#include "Actor.h"
#include "Transform.h"

class Object3d: Actor {

public:
    Object3d();
    virtual void Tick(double deltaTime);
    Transform GetTransform();

private:
    Transform mTransform;

};


#endif //VOXEL4_OBJECT3D_H
