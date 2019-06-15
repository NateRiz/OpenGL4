//
// Created by nathan on 6/15/19.
//

#include "Transform.h"

glm::vec3 Transform::GetRotation() const{
    return mRotation; // TODO
}

glm::vec3 Transform::GetScale() const{
    return mScale; //TODO
}

glm::vec3 Transform::GetLocationRelative() const {
    return mLocationRelative;
}

glm::vec3 Transform::GetLocationAbsolute() const {
    return glm::vec3(); //TODO
}

void Transform::Translate(const glm::vec3& translate) {
    glm::vec4 position = glm::vec4( mLocationRelative, 1.0f );
    glm::mat4 model = glm::translate( glm::mat4( 1.0f ), translate );
    mLocationRelative = model * position; //Remove the w automatically
}

void Transform::Rotate(const glm::vec3& rot) {
    glm::vec4 position = glm::vec4( mLocationRelative, 0.f);
    glm::mat4 model = glm::rotate(glm::mat4(1.f), rot.x, glm::vec3{1.f,0.f,0.f});
    model = glm::rotate(model, rot.y, glm::vec3{0.f,1.f,0.f});
    model = glm::rotate(model, rot.z, glm::vec3{0.f,0.f,1.f});
    mLocationRelative = model * position;
}

void Transform::Scale(const glm::vec3& scale) {
    glm::vec4 position = glm::vec4( mLocationRelative, 0.f);
    glm::mat4 model = glm::scale(glm::mat4(1.f), scale);
    mLocationRelative = model * position;
}
