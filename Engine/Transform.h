//
// Created by nathan on 6/15/19.
//

#ifndef VOXEL4_TRANSFORM_H
#define VOXEL4_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Transform {

public:
    Transform()= default;
    glm::vec3 GetLocationRelative() const;
    glm::vec3 GetLocationAbsolute() const;
    glm::vec3 GetRotation() const;
    glm::vec3 GetScale() const;
    void Translate(const glm::vec3&);
    void Rotate(const glm::vec3&);
    void Scale(const glm::vec3&);


private:
    glm::vec3 mLocationRelative;
    glm::vec3 mScale;
    glm::vec3 mRotation;

};


#endif //VOXEL4_TRANSFORM_H
