//
// Created by nathan on 6/15/19.
//

#include "Object3d.h"

Object3d::Object3d():Actor() {}

void Object3d::Tick(double deltaTime) {
    Actor::Tick(deltaTime);
}

Transform Object3d::GetTransform() {
    return mTransform;
}
